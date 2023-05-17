#include <stdio.h>

int main (){
    int ncasos;
    int blocos;
    int i;
    scanf("%d", &ncasos);
    for(i = 0; i < ncasos; i++){
        blocos = 0;
        int l1 = 0, l2 = 0, l3 = 0;
        scanf("%d", &blocos);

        while(blocos > 0){
            if(blocos > 0){
                l1++;
                blocos--;
            }
            if(blocos > 0){
                l2++;
                blocos--;
            }
            if(blocos > 0){
                l3++;
                blocos--;
            }
        }
        while(l1 < l2 || l1 < l3 || l2 < l3 || l1 == l2 || l2 == l3){
            if(l1 == l2){
                l3--;
                l1++;
            }
            if(l2 == l3){
                l3--;
                l2++;
            }
            if(l2-1 > l3 && l3 == 0){
                l3++;
                l2--;
            }
        }
        printf("%d %d %d\n", l2, l1, l3);

    }
    return 0;
}