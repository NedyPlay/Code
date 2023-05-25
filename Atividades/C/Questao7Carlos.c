#include <stdio.h>

int main (){

int i, n;
int resultado = 0;
scanf("%d", &n);
for(i = 1; i < n; i++){
    resultado = resultado + i; //resultado += i;
}

printf("O resultado da soma de todos os numeros de 0 ate %d eh igual a %d", n, resultado);
    return 0;
}