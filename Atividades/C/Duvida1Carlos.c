#include <stdio.h>

int main (){
    int a = 5; //101
    int b = 3; //011
    int c = 3; //001
    int resto;
    //Ou lógico = ^
    //E lógico = &
    //Ou = ||
    //E = &&
    resto = a % b;
    if(a == b || b == c){
        printf("Alguma coisa\n");
    }
    printf("Valor de c eh %d", c);
    printf("O resto da divisao entre %d e %d eh igual a %d", a, b, resto);



    float e, f, resultado;
    e = 3.0;
    f = 4.2;
    resultado = e * f;
    printf("O resultado eh %f", resultado);

    return 0;
}