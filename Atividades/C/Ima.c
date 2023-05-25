#include <stdio.h>

int main (){
    int linhas, n, cont, imaA, imaB, grupos;
    grupos = 0;
    cont = 0;
    scanf("%d", &linhas);
    for(cont; cont <= linhas; cont++){
        scanf("%d", &imaA);
        if(imaA == 10 && imaB == 01){
            grupos = grupos + 1;
        }
        else if(imaA == 01 && imaB == 10){
            grupos = grupos + 1;
        }
        else{
            continue;
        }
    }
    printf("%d", grupos);

    return 0;
}