#include <stdio.h>

int main (){
    int a, b;

    //7 = 0111
    //15 = 1111
    // & = 0111 = 7
    // | = 1111 = 15
    scanf("%d %d", &a, &b);
    printf("%d\n", (a & b) + (a | b));

    return 0;
}