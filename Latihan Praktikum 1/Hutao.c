#include <stdio.h>
#include <stdlib.h>

int main(){
    int a1, a2, a3, b1, b2, b3;
    char c1, c2, c3, c4;
    int d1, d2, d3, d4;

    scanf("%d %d", &a1, &b1);
    scanf("%d %d", &a2, &b2);
    scanf("%d %d", &a3, &b3);

    scanf(" %c %d", &c1, &d1);
    scanf(" %c %d", &c2, &d2);
    scanf(" %c %d", &c3, &d3);
    scanf(" %c %d", &c4, &d4);

    int x = 0, y = 0;
    int foto1, foto2, foto3;
    int langkah = 0;

    if(c1 == 'W') y += d1;
    else if(c1 == 'A') x -= d1;
    else if(c1 == 'S') y -= d1;
    else if(c1 == 'D') x += d1;

    if (!foto1 && x == a1 && y == b1){ foto1 = 1; langkah++; }
    if (!foto2 && x == a2 && y == b2){ foto2 =1; langkah++; }
    if (!foto3 && x == a3 && y == b3){ foto3 =1; langkah ++;}

    if(c2 ==  'W') y += d2;
    else if (c2 == 'A') x -= d2;
    else if (c2 == 'S') y -= d2;
    else if (c2 == 'D') x += d2;

    if (!foto1 && x == a1 && y == b1){ foto1 = 1; langkah++; }
    if (!foto2 && x == a2 && y == b2){ foto2 =1; langkah++; }
    if (!foto3 && x == a3 && y == b3){ foto3 =1; langkah ++;}

    if(c3 ==  'W') y += d3;
    else if (c3 == 'A') x -= d3;
    else if (c3 == 'S') y -= d3;
    else if (c3 == 'D') x += d3;

    if (!foto1 && x == a1 && y == b1){ foto1 = 1; langkah++; }
    if (!foto2 && x == a2 && y == b2){ foto2 =1; langkah++; }
    if (!foto3 && x == a3 && y == b3){ foto3 =1; langkah ++;}

    if(c2 ==  'W') y += d4;
    else if (c4 == 'A') x -= d4;
    else if (c4 == 'S') y -= d4;
    else if (c4 == 'D') x += d4;

    if (!foto1 && x == a1 && y == b1){ foto1 = 1; langkah++; }
    if (!foto2 && x == a2 && y == b2){ foto2 =1; langkah++; }
    if (!foto3 && x == a3 && y == b3){ foto3 =1; langkah ++; }

    if(langkah > 0){
    printf("%d\n", langkah);
    } else {
        printf("aku kangen kamu zhong li");
    }
return 0;
}

