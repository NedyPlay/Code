#include <stdio.h>

int main(void){
    double a, b, media;
    scanf("%lf", &a);
    scanf("%lf", &b);
    a = a * 3.5;
    b = b * 7.5;
    media = (a + b) / 11;
    printf("A media e igual a: %.5lf", media);
    return 0;
}
