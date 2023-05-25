#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    char string[200], minuscula[200];
    int tamanho, cont;
    cont = 0;
    scanf("%s", string);
    tamanho = strlen(string);
    
    for (cont; cont < tamanho; cont++){
        minuscula[cont] = tolower(string[cont]);
    }

    printf("%s", minuscula);
    return 0;
}