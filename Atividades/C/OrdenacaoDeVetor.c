#include<stdlib.h>

typedef struct
{
    int *lista;
    int size;
} VETOR;

VETOR * ordena(VETOR *a) {
    #include <stdio.h>
    int i,j,k,aux, l, *v, size;
    v = (int *) malloc (sizeof (int) * 10);

    for(k=0 ; k < a->size ; k++){
       v[k] = a->lista[k];
    }   


    for(i=1;i<a->size; i++){
        aux = v[i];
        for(j=i;(j>0)&&(aux < v[j-1]);j--){
            v[j] = v[j-1];
            v[j]= aux;
        }
    }
    size = sizeof(v);
    printf("\nTamanho %d\n", size);
    for(l = 0; l < size; l++){
        printf("%d", v[l]);
    }

    return 0;
}