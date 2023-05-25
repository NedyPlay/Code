#include <stdio.h>
#include <math.h>

int main (){

    long long int total = 0, i, teste;

    for (i = 1; i <= 26; i++){
        total = i*(i+1)*(i+2);
        printf("%lld %lld\n", i, total);
    }
    printf("%lld", total);
    teste = pow(26,3) + 3*pow(26,2) + 2*26;
    printf("\nteste: %lld", teste);

    return 0;
}