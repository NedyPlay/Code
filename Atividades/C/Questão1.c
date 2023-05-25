#include <stdio.h>


int main (){
    
    long int n1, n2, n[100], cont, casos, soma, soma2, soma3, num, inFibonacci = 0;
    int j = 0, k = 0, i = 0;

    scanf("%ld", &casos);
    n[0] = 0;

    for(i = 0; i < casos; i++){
        n1 = 0;
        n2 = 1;
        scanf("%ld", &num);
        for(cont = 1; cont < 50; cont++){
            soma = n1 + n2;
            n[cont] = soma;
            k++;
            n1 = n2;
            n2 = soma;
        }
        for(k = 0; k < 50; k++){
            j = k + 1;
            for(j; j < 50; j++){
                soma2 = n[k] + n[j];
                soma3 = n[k] + n[k];
                if(soma2 == num || soma3 == num){
                    inFibonacci = 1;
                }
            }
        }
        if (inFibonacci == 1){
            printf("S\n");
            inFibonacci = 0;
        }
        else{
            printf("N\n");
        }
    }
    return 0;
}