#include <stdio.h>

int main (void){
    double raio, pi, area;
    pi = 3.14159;
    scanf("%lf", &raio);
    area = pi * (raio*raio);
    printf("A=%.4lf", area);
    return 0;
}