#include <stdio.h>

int main()
{
    long long N;
    
    scanf("%lld", &N);

    long long m3 = N / 3;
    long long m5 = N / 5;
    long long m15 = N / 15;

    long long sum3 = 3 * m3 * (m3 + 1) / 2;
    long long sum5 = 5 * m5 * (m5 + 1) / 2;
    long long sum15 = 15 * m15 * (m15+1) / 2;

    long long Total = sum3 + sum5 - sum15;

    printf("%lld\n", Total);

    return 0;
}