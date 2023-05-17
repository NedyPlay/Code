#include <stdio.h>
#define MAX 100
int main(){
    long int vetor[MAX], vetorDist[MAX] = {600}, casos, contem, temp = 100, posicao;
    long int i = 0, j, k = 0, cont = 0;

    scanf("%ld %ld", &casos, &posicao);
    k = 0;
    for(i = 0; i < casos; i++){
        scanf("%ld", &temp);
        for (j = 0; j <= i-1; j++){
            if(temp == vetorDist[j] && temp != 0){
                contem = 1;
            }
        }
        if(contem == 1){
            contem = 0;
        }
        else{
            vetorDist[k] = temp;
            vetor[k] = temp;
            k++;
            cont++;
        }

    }
    for(i=0;i<cont;i++){
        printf("%ld ", vetor[i]);
    }
    j = 0;
    i = 0;
    temp = 0;
    for(i; i < cont; i++){
        for(j = i + 1; j < cont; j++){
            if( vetor[i] > vetor[j] ){
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }

    printf("%ld", vetor[posicao]);
    return 0;
}
