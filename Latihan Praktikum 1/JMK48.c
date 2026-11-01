#include <stdio.h>
#include <math.h>

int main(){

    int A, K, U, R, F;
    scanf("%d %d %d %d %d", &A, &K, &U, &R, &F);

    float rata_rata = (A + K + U + R + F) / 5.0;

    if(A >= rata_rata && A >= 80){
        printf("Ambatron Lulus\n");
    }
    if(K >= rata_rata && K >= 80){
        printf("Kumalala Lulus\n");
    }
    if(U >= rata_rata && U >= 80){
        printf("Ucok Lulus\n");
    }
    if(R >= rata_rata && R  >= 80){
        printf("Rehan Lulus\n");
    }
    if(F >= rata_rata && F  >= 80){
        printf("Farhan Lulus");

    }return 0;
}