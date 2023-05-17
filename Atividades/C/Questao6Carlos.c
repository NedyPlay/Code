#include <stdio.h>

int main(){
    int a, b, c, d;
    scanf("%d %d", &a, &b);

    //256 = 100000000
    c = a << b; //desloca pra esquerda
    d = a >> b; // desloca pra direita
    //00001 = 1
    printf("c: %d\nd: %d\n", c, d);
    return 0;
}