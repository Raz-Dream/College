#include <stdio.h>
#include <math.h>

unsigned long long faktorial(int n) {
    unsigned long long hasil = 1;
    for (int i = 1; i <= n; i++){
        hasil *= i;
    }
}

void hitungPermutasi (int n, int r){

    if (r > n){
        printf("Error nilai r tidak boleh melebihi dari n\n");
        return;
    }

    unsigned long long hasil = faktorial(n) / faktorial(n - r);

    printf("Hasil P(%d, %d) = %llu\n", n, r, hasil);
}

int main(){
    int n, r;

    printf("Masukkan nilai total n\n");
    scanf("%d", &n);
    printf("Masukkan nilai total r\n");
    scanf("%d", &r);

    hitungPermutasi(n, r);

    return 0;
}