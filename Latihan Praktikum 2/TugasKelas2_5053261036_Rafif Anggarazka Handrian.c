#include <stdio.h>

void tampilMenu() {
    printf("1. Gajah\n");
    printf("2. Orang\n");
    printf("3. Semut\n");
}

void tampilRonde(int ronde) {
    printf("\nRONDE %d dari 3\n", ronde);
}

void inputPemain(int *pemain) {
    do {
        printf("Pilihanmu (1-3): ");
        scanf("%d", pemain);
    } while (*pemain < 1 || *pemain > 3);
}

void balasKomputer(int pemain, int *komputer) {
    if (pemain == 1) {
        *komputer = 3;     
    } else if (pemain == 2) {
        *komputer = 1;      
    } else {
        *komputer = 2;     
    }
}

void tampilNama(int pilihan) {
    if (pilihan == 1) printf("Gajah\n");
    else if (pilihan == 2) printf("Orang\n");
    else printf("Semut\n");
}

void tampilHasil(int pemain, int komputer) {
    printf("\nKamu     : ");
    tampilNama(pemain);
    printf("Komputer : ");
    tampilNama(komputer);

    if (pemain == 1) printf("Semut masuk ke telinga Gajah!\n");
    else if (pemain == 2) printf("Gajah menginjak Orang!\n");
    else printf("Orang menginjak Semut!\n");

    printf("Komputer menang ronde ini!\n");
}

void tampilSkor(int skorPemain, int skorKomputer) {
    printf("Skor -> Kamu: %d | Komputer: %d\n", skorPemain, skorKomputer);
}

void tampilPemenang(int skorPemain, int skorKomputer) {
    printf("\nHASIL AKHIR\n");
    tampilSkor(skorPemain, skorKomputer);
    if (skorKomputer > skorPemain) printf("KOMPUTER MENANG\n");
}

int main() {
    int pemain, komputer;
    int ronde;
    int skorPemain = 0, skorKomputer = 0;

    printf("GAME GAJAH - ORANG - SEMUT\n");

    for (ronde = 1; ronde <= 3; ronde++) {
        tampilRonde(ronde);
        tampilMenu();
        inputPemain(&pemain);
        balasKomputer(pemain, &komputer);
        tampilHasil(pemain, komputer);

        skorKomputer++;
        tampilSkor(skorPemain, skorKomputer);
    }

    tampilPemenang(skorPemain, skorKomputer);
    return 0;
}