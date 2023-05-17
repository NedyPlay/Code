#include <stdio.h>
int ordenaVetor(int *vet, int tamvetor){
    int i, j;
    int indpar = 0, indimpar = 0, resultado = 0;
    for(i = 0; i < tamvetor; i++){
        if(i % 2 == 0 && vet[i] % 2 == 1){
            indpar++;
        }
        if(i % 2 == 1 && vet[i] % 2 == 0){
            indimpar++;
        }
    }
    for(j = 0; j < tamvetor; j++){
        if(indpar > 0 && indimpar > 0){
            resultado++;
            indpar--;
            indimpar--;
        }
    }
    if((indpar > 0)||(indimpar > 0)){
        resultado = -1;
    }
    return resultado;
}
int main (){
    int ncasos, tamvetor;
    scanf("%d", &ncasos);
    int i, j;
    for(i = 0; i < ncasos; i++){
        scanf("%d", &tamvetor);
        int vet[tamvetor];
        for(j = 0; j < tamvetor; j++){
            scanf("%d", &vet[j]);
        }
        printf("%d\n", ordenaVetor(vet, tamvetor));
    }
    return 0;
}