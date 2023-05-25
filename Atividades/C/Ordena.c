#include<stdlib.h>

typedef struct
{
    int *lista;
    int size;
} VETOR;

VETOR * ordena(VETOR *a) {
    int tamanho, i, j, k, temp;
    tamanho = sizeof(VETOR);
    VETOR *x = (VETOR*)malloc(tamanho);
    x -> size = a -> size;
    x -> lista = (int*)malloc(sizeof(int));

    for(i = 0; i < a->size; i++){
        x->lista[i] = a -> lista[i];
    }
    for(j = 0; j < x->size;j++){
        for(k = 0;k < x->size;k++){
            //Comparação interna
            if(x->lista[j] < x->lista[k]){
                temp = x->lista[j];
                x -> lista[k] = x -> lista[j];
                x -> lista[j] = temp;
            }
        }
    }


    return x;
}