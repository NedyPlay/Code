#include <stdio.h>
#include <math.h>

int main (){
    double peso;
    scanf("%lf", &peso);
    if (fmod(peso, 2) == 0 && peso != 1 && peso != 2){
        printf("YES");
    }
    else{
        printf("NO");
    }

    return 0;
}