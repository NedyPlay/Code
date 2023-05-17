#include <stdio.h>

int main(){
int i, j, k, pr, temp, vetor[6];

    for (k = 0; k<6; k++){
        scanf("%d", &vetor[k]);
        printf("%d\n", vetor[k]);
    }
    for(j = 6; j >= 1; j--){
        for(i = 0; i < j; i++){
            if(vetor[i] > vetor[i+1]){
                temp = vetor[i];
                vetor[i] = vetor [i+1];
                vetor[i+1] = temp;
            }
        }
    }
    for(pr = 0; pr < 6; pr++){
        printf("%d\n", vetor[pr]);
    }
}