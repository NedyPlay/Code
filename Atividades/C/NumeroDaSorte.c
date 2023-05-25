#include <stdio.h>
#include <math.h>

int count(int i) {
    int ret=1;
    while (i/=10) ret++;
    return ret;
}
int decimal(int n, int k){
    while(n--)
        k/=10;
    return k%10;
}

int main (){

    int total = 0, i, j, resposta = 0, temp;
    char nome[200], alfabeto[28] = {' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    scanf("Digite seu nome: %s", &nome);
    for (i = 0; nome[i] != '\0'; i++){
        for(j = 0; j < 28; j++){
            if(nome[i] == alfabeto[j]){
                total = total + j;
            }
        }
    }
    printf("%d", total);
    for(i = 0; i < count(total); i++){
    resposta += decimal(i, total);
    }
    temp = resposta;
    resposta = 0;
    for(i = 0; i < count(temp); i++){
        resposta += decimal(i, temp);
    }
    printf("\n%d", resposta);
}