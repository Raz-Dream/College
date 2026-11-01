#include <stdio.h>

int Angkabelakang(int n) {
    
    if (n == 0) {
        return 0;
    }
    else{ 
    return (n % 10) + Angkabelakang(n / 10);
    }                                                                                           
}
int main(){
    int angka;
    printf("Masukkan Angka: ");
    scanf("%d", &angka);

    printf("%d", Angkabelakang(angka));

    return 0;
}