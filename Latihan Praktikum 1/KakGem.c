#include <stdio.h>

int main(){

    long long V, B;
    scanf("%lld %lld", &V, &B);

    int Lebihdari10menit = V > 600;
    int Lebihdari100juta = B > 100000000;

    if(Lebihdari10menit && Lebihdari100juta){
        printf("GAK MASUK AKAL\n");
    }
    if(Lebihdari10menit || Lebihdari100juta){
        printf("GUWENDENG\n");
    }
    if(B >= 15000LL * V){
        printf("PAHAM\n");
    }
    else{
        printf("Tapi Tunggu Dulu\n");
    }

    return 0;

}