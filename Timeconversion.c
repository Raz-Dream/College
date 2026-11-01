#include <stdio.h>

int main()
{
    int S;
    scanf("%d", &S);
    
    int jam, menit, detik;

    jam = S / 3600;
    menit = (S % 3600) / 60;
    detik = S % 60;

    printf("%d jam %d menit %d detik", jam, menit, detik);
    return 0;

}