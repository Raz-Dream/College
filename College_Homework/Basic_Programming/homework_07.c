#include <stdio.h>
#include <stdlib.h>

char gambar[200][200];
int x, y, arah;
int ukuran;

void kiri() {
    arah = (arah + 3) % 4;
}

void kanan() {
    arah = (arah + 1) % 4;
}

void maju() {
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    int nx = x + dx[arah] * 2;
    int ny = y + dy[arah] * 2;

    gambar[y + dy[arah]][x + dx[arah]] = '@';

    x = nx;
    y = ny;

    gambar[y][x] = '@';
}

void A(int n);
void B(int n);

void A(int n) {
    if (n == 0) {
        return;
    }

    kiri();
    B(n - 1);
    maju();
    kanan();
    A(n - 1);
    maju();
    A(n - 1);
    kanan();
    maju();
    B(n - 1);
    kiri();
}

void B(int n) {
    if (n == 0) {
        return;
    }

    kanan();
    A(n - 1);
    maju();
    kiri();
    B(n - 1);
    maju();
    B(n - 1);
    kiri();
    maju();
    A(n - 1);
    kanan();
}

int main() {
    int n;

    printf("orde Hilbert: ");
    scanf("%d", &n);

    if (n < 1 || n > 6) {
        printf("Orde harus antara 1-6.\n");
        return 0;
    }

    ukuran = (1 << n) * 2 - 1;

    for (int i = 0; i < ukuran; i++) {
        for (int j = 0; j < ukuran; j++) {
            gambar[i][j] = ' ';
        }
    }

    x = 0;
    y = 0;
    arah = 1;

    gambar[y][x] = '@';

    A(n);

    printf("\nHilbert Curve orde %d:\n\n", n);

    for (int i = 0; i < ukuran; i++) {
        for (int j = 0; j < ukuran; j++) {
            printf("%c ", gambar[i][j]);
        }
        printf("\n");
    }

    return 0;
}