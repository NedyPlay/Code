#include <stdio.h>

int main(){
    long int vetor[100], vetorInv[100], casos;
    int i, j;

    scanf("%ld", &casos);
    for(i = 0; i < casos; i++){
        scanf("%ld", &vetor[i]);
    }
    for(i=0, j = casos-1; i < casos && j >= 0; i++, j-- ) {
        vetorInv[i] = vetor[j];
        printf("%ld ", vetorInv[i]);
    }

    return 0;
}