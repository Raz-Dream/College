#include <stdio.h>

int main(){
    int Zeon, EFSF;
    char KondisiGundam;
    
    scanf("%d %d %c", &Zeon, &EFSF, &KondisiGundam);

    if(Zeon >= EFSF && KondisiGundam == 'N'){
        printf("Strategi A");
    }
    else if(Zeon < EFSF && KondisiGundam == 'N'){
        printf("Strategi B");
    } 
    else if (Zeon >= EFSF && KondisiGundam == 'Y'){
        printf("Strategi C");
    }
    else if (Zeon < EFSF && KondisiGundam == 'Y'){
        printf("Strategi D");
    }
    else {
        printf("MUNDURR");
    }
return 0;
}
