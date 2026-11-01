#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define JUMLAH 5

void clear_screen() {
    system("cls"); 
}

void buat_angka(int angka[]) {
    for (int i = 0; i < JUMLAH; i++) {
        angka[i] = rand() % 100;
    }
}

void tampilkan_angka(int angka[]) {
    for (int i = 0; i < JUMLAH; i++) {
        printf("%d ", angka[i]);
    }
}

void input_tebakan(int tebakan[]) {
    for (int i = 0; i < JUMLAH; i++) {
        printf("Angka ke-%d: ", i + 1);
        scanf("%d", &tebakan[i]);
    }
}

void tampilkan_hasil(int angka[], int tebakan[]) {
    int benar = 1;

    for (int i = 0; i < JUMLAH; i++) {
        if (tebakan[i] != angka[i]) {
            benar = 0;
            break;
        }
    }

    if (benar) {
        printf("Tebakanmu Benar\n");
    } else {
        clear_screen();
        printf("Tebakanmu salah\n\n");
        printf("Deretan angka yang benar adalah: ");
        tampilkan_angka(angka);
        printf("\ncoba lagi\n");
    }
}

int main() {
    int angka[JUMLAH];
    int tebakan[JUMLAH];

    srand(time(NULL));

    buat_angka(angka);

    printf("Hafalkan %d angka berikut ini:\n", JUMLAH);
    tampilkan_angka(angka);

    printf("\n\nTekan Enter jika kamu sudah hafal...");
    while (getchar() != '\n');

    clear_screen();

    printf("Sekarang, masukkan %d angka yang tadi kamu hafal\n", JUMLAH);
    input_tebakan(tebakan);

    tampilkan_hasil(angka, tebakan);

    return 0;
}