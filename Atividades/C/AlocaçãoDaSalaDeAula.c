#include <stdio.h>

int main (){
    int xinicial, yinicial, x, y, i, casos, aulas = 1;

    scanf("%d", &casos);
    scanf("%d %d", &xinicial, &yinicial);
    for(i = 1; i < casos; i++){
        scanf("%d %d", &x, &y);
        if(yinicial <= x){
            yinicial = y;
            aulas++;
        }
    }

    printf("%d", aulas);

    return 0;   
}