#include <stdio.h>

int main() {
    long long X, Y, Z;
    scanf("%lld %lld %lld", &X, &Y, &Z);

    long long Maksimal = X;
    if (Y > Maksimal) Maksimal = Y;
    if (Z > Maksimal) Maksimal = Z;

    long long Minimum = X;
    if (Y < Minimum) Minimum = Y;
    if (Z < Minimum) Minimum = Z;

    printf("Stok terbanyak : %lld\n", Maksimal);
    printf("Stok terendah : %lld\n", Minimum);

    if (X == Y) {
        printf("Terdapat toko dengan stok yang sama : %lld\n", X);
    } else if (Y == Z) {
        printf("Terdapat toko dengan stok yang sama : %lld\n", Y);
    } else if (Z == X) {
        printf("Terdapat toko dengan stok yang sama : %lld\n", Z);
    } else {
        printf("Tidak ada stok yang sama.\n");
    }

    return 0;
}