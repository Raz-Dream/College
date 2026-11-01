#include <stdio.h>
#include <math.h>

int main()
{
    int Merah, Biru;

    scanf("%d %d", &Merah, &Biru);
    int beda_warna, sisa;

    if (Biru < Merah) {
    
    beda_warna = Biru;
    sisa = Merah - Biru;
    }
    else {
    beda_warna = Merah;
    sisa = Biru - Merah;
    }
    int sama_warna = sisa / 2;

    printf("%d %d\n", beda_warna, sama_warna);
    return 0; 
}