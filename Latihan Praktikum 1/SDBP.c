#include <stdio.h>

int main() {
    unsigned long long x;
    scanf("%llu", &x);

    int r2 = x % 2;
    int r4 = x % 4;
    int r7 = x % 7;
    int r9 = x % 9;

    if (r2 == 0 && r4 == 0 && r7 == 0 && r9 == 0) {
        printf("aku suka dasar pemrograman\n");
    } else {
        printf("aku suka ");
        if (r2 != 0) printf("%d", r2);
        if (r4 != 0) printf("%d", r4);
        if (r7 != 0) printf("%d", r7);
        if (r9 != 0) printf("%d", r9);
        printf(" dasar pemrograman\n");
    }

    return 0;
}