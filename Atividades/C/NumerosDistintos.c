#include <stdio.h>

int main(){
    long int vetor[1000], vetorDist[1000], casos, contem, temp;
    long int i, j, k;

    scanf("%ld", &casos);
    k = 0;
    for(i = 0; i < casos; i++){
        scanf("%ld", &temp);
        for (j = 0; j < i; j++){
            if(temp == vetorDist[j]){
                contem = 1;
                continue;
            }
        }
        if(contem == 1){
            i--;
            contem = 0;
        }
        else{
            vetorDist[k] = temp;
            printf("%ld ", vetorDist[k]);
            k = k + 1;
        }
    }
    
    return 0;
}