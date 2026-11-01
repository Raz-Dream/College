#include <stdio.h>

int main()
{
    int A;
    int B;

    scanf("%d %d", &A, &B);

    int beda = A ^ B;

    int jumlah_ubah = 0;

    while (beda > 0){
        if(beda % 2 == 1){
            jumlah_ubah++;
        }
        
        beda = beda / 2;
    }
    printf("%d\n", jumlah_ubah);

    return 0;

}