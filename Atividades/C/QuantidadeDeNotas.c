#include <stdio.h>

int main (){
    int entrada, a = 0, b = 3, x = 15, i, j;
    scanf("%d", &entrada);

    for(i = 0; x != entrada; i++){
            if(b >= 1){
                a = a+3;
                b = b-1;
                x = x + 1;
            }
            if(a >= 7){
                a = a-7;
                b = b+3;
                x = x + 1;
            }
    }

    printf("%d %d", a, b);


    return 0;
}