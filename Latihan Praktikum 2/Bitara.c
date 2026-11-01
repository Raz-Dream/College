/*
 * MINI BATTLE ala Undertale - versi WINDOWS (tanpa ncurses)
 * Kompilasi: gcc undertale_mini_win.c -o undertale_mini_win.exe
 * Jalankan : .\undertale_mini_win.exe   (di terminal / cmd / PowerShell)
 *
 * Kontrol:
 *   Menu   : Panah Kiri/Kanan (atau A/D) pilih, Enter/Z konfirmasi
 *   Dodge  : Panah / WASD menggerakkan jiwa (v)
 *   Q      : keluar
 */
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SCR_W 80
#define SCR_H 24
#define BOX_W 32
#define BOX_H 10
#define BOX_X 24
#define BOX_Y 9
#define MAX_B 48

/* warna console Windows */
#define C_WHITE  7
#define C_RED    12
#define C_GREEN  10
#define C_CYAN   11
#define C_YELLOW 14

enum { K_NONE = -1, K_LEFT = 1000, K_RIGHT, K_UP, K_DOWN };

/* ---------- mini "engine" layar ---------- */
static CHAR_INFO scr[SCR_W * SCR_H];
static HANDLE hout;

static void gfx_clear(void) {
    for (int i = 0; i < SCR_W * SCR_H; i++) {
        scr[i].Char.AsciiChar = ' ';
        scr[i].Attributes = C_WHITE;
    }
}

static void put(int y, int x, char c, int col) {
    if (y < 0 || y >= SCR_H || x < 0 || x >= SCR_W) return;
    scr[y * SCR_W + x].Char.AsciiChar = c;
    scr[y * SCR_W + x].Attributes = (WORD)col;
}

static void print(int y, int x, int col, const char *fmt, ...) {
    char buf[256];
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);
    for (int i = 0; buf[i]; i++) put(y, x + i, buf[i], col);
}

static void gfx_flush(void) {
    COORD size = {SCR_W, SCR_H}, zero = {0, 0};
    SMALL_RECT r = {0, 0, SCR_W - 1, SCR_H - 1};
    WriteConsoleOutputA(hout, scr, size, zero, &r);
}

/* ---------- input ---------- */
static int read_key(void) {
    if (!_kbhit()) return K_NONE;
    int c = _getch();
    if (c == 0 || c == 224) {
        c = _getch();
        switch (c) {
        case 75: return K_LEFT;
        case 77: return K_RIGHT;
        case 72: return K_UP;
        case 80: return K_DOWN;
        }
        return K_NONE;
    }
    if (c >= 'A' && c <= 'Z') c += 32;
    return c;
}

static int wait_key(void) {
    for (;;) {
        int k = read_key();
        if (k != K_NONE) return k;
        Sleep(10);
    }
}

/* tunggu ms milidetik, kembalikan tombol terakhir yang ditekan */
static int poll_key(int ms) {
    int last = K_NONE;
    DWORD end = GetTickCount() + ms;
    while (GetTickCount() < end) {
        int k = read_key();
        if (k != K_NONE) last = k;
        Sleep(5);
    }
    return last;
}

/* ---------- data game ---------- */
typedef struct { int x, y, dx, dy, active; } Bullet;

static Bullet bl[MAX_B];
static int hp = 20, maxhp = 20;
static int ehp = 30, emaxhp = 30;
static int mercy = 0, items = 3, turn = 1;
static char msg[160] = "* Lendir muncul menghalangi jalanmu!";

static const char *menu[4] = {"FIGHT", "ACT", "ITEM", "MERCY"};

/* ---------- gambar ---------- */
static void draw_bar(int y, int x, int cur, int max, int color) {
    int w = 20, fill = cur * w / max;
    if (cur > 0 && fill == 0) fill = 1;
    for (int i = 0; i < w; i++) put(y, x + i, i < fill ? '#' : '.', color);
}

static void draw_box(void) {
    for (int i = 0; i < BOX_W; i++) {
        put(BOX_Y, BOX_X + i, '-', C_WHITE);
        put(BOX_Y + BOX_H - 1, BOX_X + i, '-', C_WHITE);
    }
    for (int j = 0; j < BOX_H; j++) {
        put(BOX_Y + j, BOX_X, '|', C_WHITE);
        put(BOX_Y + j, BOX_X + BOX_W - 1, '|', C_WHITE);
    }
}

static void draw_enemy(void) {
    print(1, 34, C_CYAN, "   .-\"\"\"-.");
    print(2, 34, C_CYAN, "  /  o o  \\");
    print(3, 34, C_CYAN, " |    ~    |");
    print(4, 34, C_CYAN, " '._______.'");
    print(5, 30, C_WHITE, "LENDIR  ");
    draw_bar(5, 38, ehp, emaxhp, C_GREEN);
    print(6, 30, C_WHITE, "Mercy   ");
    draw_bar(6, 38, mercy > 100 ? 100 : mercy, 100, C_CYAN);
}

static void draw_status(void) {
    print(BOX_Y + BOX_H + 1, BOX_X, C_WHITE, "KAMU  LV 1  HP ");
    draw_bar(BOX_Y + BOX_H + 1, BOX_X + 15, hp, maxhp, C_RED);
    print(BOX_Y + BOX_H + 1, BOX_X + 36, C_WHITE, "%02d/%02d", hp, maxhp);
}

static void draw_all(int sel) {
    gfx_clear();
    draw_enemy();
    draw_box();
    draw_status();
    print(BOX_Y + 1, BOX_X + 2, C_WHITE, "%s", msg);
    for (int i = 0; i < 4; i++)
        print(BOX_Y + BOX_H + 3, BOX_X + i * 9, i == sel ? C_YELLOW : C_WHITE,
              "[%s]", menu[i]);
    gfx_flush();
}

/* ---------- fase menghindar ---------- */
static int dodge_phase(void) {
    int px = BOX_W / 2, py = BOX_H / 2, inv = 0;
    int ticks = 55 + turn * 8;
    memset(bl, 0, sizeof(bl));

    for (int t = 0; t < ticks; t++) {
        int ch = poll_key(80);
        if (ch == 'q') return -1;
        if ((ch == K_LEFT || ch == 'a') && px > 1) px--;
        if ((ch == K_RIGHT || ch == 'd') && px < BOX_W - 2) px++;
        if ((ch == K_UP || ch == 'w') && py > 1) py--;
        if ((ch == K_DOWN || ch == 's') && py < BOX_H - 2) py++;

        /* spawn peluru */
        if (rand() % (4 - (turn > 3 ? 1 : 0)) == 0) {
            for (int i = 0; i < MAX_B; i++) {
                if (bl[i].active) continue;
                bl[i].active = 1;
                if (rand() % 2) { /* hujan */
                    bl[i].x = 1 + rand() % (BOX_W - 2);
                    bl[i].y = 1; bl[i].dx = 0; bl[i].dy = 1;
                } else {          /* dari samping */
                    int left = rand() % 2;
                    bl[i].y = 1 + rand() % (BOX_H - 2);
                    bl[i].x = left ? 1 : BOX_W - 2;
                    bl[i].dx = left ? 1 : -1; bl[i].dy = 0;
                }
                break;
            }
        }

        /* gerak + tabrakan */
        for (int i = 0; i < MAX_B; i++) {
            if (!bl[i].active) continue;
            bl[i].x += bl[i].dx; bl[i].y += bl[i].dy;
            if (bl[i].x < 1 || bl[i].x > BOX_W - 2 ||
                bl[i].y < 1 || bl[i].y > BOX_H - 2) { bl[i].active = 0; continue; }
            if (inv == 0 && bl[i].x == px && bl[i].y == py) {
                hp -= 3; inv = 8; bl[i].active = 0;
            }
        }
        if (inv > 0) inv--;
        if (hp <= 0) { hp = 0; return 0; }

        /* gambar */
        gfx_clear();
        draw_enemy(); draw_box(); draw_status();
        for (int i = 0; i < MAX_B; i++)
            if (bl[i].active) put(BOX_Y + bl[i].y, BOX_X + bl[i].x, '*', C_WHITE);
        if (!(inv > 0 && inv % 2)) put(BOX_Y + py, BOX_X + px, 'v', C_RED);
        gfx_flush();
    }
    return 1;
}

static void end_screen(const char *text) {
    gfx_clear();
    print(10, 20, C_YELLOW, "%s", text);
    print(12, 20, C_WHITE, "Tekan tombol apa saja...");
    gfx_flush();
    wait_key();
}

/* ---------- main ---------- */
int main(void) {
    srand((unsigned)time(NULL));
    hout = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO ci = {1, FALSE};      /* sembunyikan kursor */
    SetConsoleCursorInfo(hout, &ci);
    system("cls");

    int sel = 0;
    for (;;) {
        /* ----- giliran pemain ----- */
        int chosen = 0;
        while (!chosen) {
            draw_all(sel);
            int ch = wait_key();
            if (ch == 'q') goto quit;
            if ((ch == K_LEFT || ch == 'a') && sel > 0) sel--;
            if ((ch == K_RIGHT || ch == 'd') && sel < 3) sel++;
            if (ch == '\r' || ch == 'z') chosen = 1;
        }

        switch (sel) {
        case 0: { /* FIGHT */
            int dmg = 6 + rand() % 7;
            ehp -= dmg;
            snprintf(msg, sizeof(msg), "* Kamu menyerang! %d damage.", dmg);
            if (ehp <= 0) { end_screen("MENANG! Lendir kalah..."); goto quit; }
            break; }
        case 1: /* ACT */
            mercy += 35;
            snprintf(msg, sizeof(msg), "* Kamu ngobrol dengan Lendir. Dia mulai tenang.");
            break;
        case 2: /* ITEM */
            if (items > 0) {
                items--; hp += 10; if (hp > maxhp) hp = maxhp;
                snprintf(msg, sizeof(msg), "* Kamu makan Roti. HP +10. (sisa %d)", items);
            } else snprintf(msg, sizeof(msg), "* Tidak ada item lagi!");
            break;
        case 3: /* MERCY */
            if (mercy >= 100) { end_screen("Kamu mengampuni Lendir. MENANG damai!"); goto quit; }
            snprintf(msg, sizeof(msg), "* Lendir belum mau berdamai. (ACT dulu)");
            break;
        }

        /* ----- giliran musuh ----- */
        draw_all(sel); Sleep(900);
        int r = dodge_phase();
        if (r < 0) goto quit;
        if (r == 0) { end_screen("GAME OVER - Tetaplah bertekad!"); goto quit; }
        turn++;
        snprintf(msg, sizeof(msg), "* Lendir menatapmu. Giliran %d.", turn);
    }
quit:
    ci.bVisible = TRUE;
    SetConsoleCursorInfo(hout, &ci);
    system("cls");
    return 0;
}