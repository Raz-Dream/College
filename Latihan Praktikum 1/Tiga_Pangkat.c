#include <stdio.h>

int main(){

    long long x;
    scanf("lld", &x);

    long long Hasil = (x * (x + 1) / 2);
    long long Deret = Hasil * Hasil;

    printf("lld\n", Deret);

    return 0;

}