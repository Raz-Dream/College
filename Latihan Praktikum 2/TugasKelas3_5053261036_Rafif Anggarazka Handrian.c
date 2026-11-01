#include <stdio.h>

int cariFaktorPrima(int n, int faktor[]) {
    int count = 0;

    while (n % 2 == 0) {
        faktor[count++] = 2;
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            faktor[count++] = i;
            n = n / i;
        }
    }

    if (n > 2) {
        faktor[count++] = n;
    }

    return count;
}

void cetakOutput(int angka, int faktor[], int jumlah) {
    if (angka <= 1) {
        printf("Bilangan %d tidak memiliki faktor prima.\n", angka);
        return;
    }

    printf("Faktor prima dari %d adalah: ", angka);
    for (int i = 0; i < jumlah; i++) {
        printf("%d", faktor[i]);
        
        if (i < jumlah - 1) {
            printf(" x ");
        }
    }
    printf("\n");
}

int main() {
    int bilangan;
    int faktor[100]; 
    
    printf("Masukkan sebuah bilangan: ");
    scanf("%d", &bilangan);
    
    int jumlahFaktor = cariFaktorPrima(bilangan, faktor);
    
    cetakOutput(bilangan, faktor, jumlahFaktor);
    
    return 0;
}