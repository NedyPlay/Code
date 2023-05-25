#include <stdio.h>
#include <stdlib.h>

long long int fator(int x){
    long long int fat;
    for (fat = 1; x > 1; x--){
        fat = fat * x;
    }
    return fat;
}
long long int combinatoria(int c, int p){
    long long int comb;
    comb = (fator(c)/(fator(p)*fator(c-p)));
    return comb;
}
long long int combinacaorept(int c, int p){
    int combrept;
    combrept = fator(c + p - 1)/(fator(p)*fator(c-1));
    return combrept;
}

int main (){

    long long int i, resultado, final = 0, teste;
    /*for (i = 17; i > 3; i--){
        teste = combinatoria(6, 2);
        printf("Combinatoria de %lld e 4 eh %lld\n", i, teste);
        resultado = combinatoria(i, 4) - combinatoria(i-1, 3) - combinatoria(i-2, 3);
        printf("%lld\n", resultado); 
        final = final + resultado;
    }
    printf("%lld", final);*/
    teste = combinatoria(28,7);
    printf("%lld", teste);
    return 0;
}