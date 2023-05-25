#include <stdio.h>


int main (){
    
    int n1, n2, cont, i, casos, posicao, fib, soma;
    scanf("%d", &casos);
    
    for(i = 0; i < casos; i++){
        scanf("%d", &posicao);
        n1 = 0;
        n2 = 1;
        for(cont = 1; cont < posicao; cont++){
            soma = n1 + n2;
            n1 = n2;
            n2 = soma;
        }
        fib = soma;
        if (posicao == 0){
            printf("Fib(0) = 0\n");
        }
        else {
            printf("Fib(%d) = %d\n", posicao, fib);
        }
    }
    return 0;
}