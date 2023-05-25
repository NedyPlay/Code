#include <stdio.h>

int main (){
    char num[1000];
    int leds, cont, linhas, i;
    scanf("%d", &linhas);
    
    for(cont = 0; cont < linhas; cont++){
        scanf("%s", num);
        leds = 0;
        i = 0;
        while(i<1000){
            if(num[i] == '1'){
                leds += 2;
            }
            if(num[i] == '2'){
                leds += 5;
            }
            if(num[i] == '3'){
                leds += 5;
            }
            if(num[i] == '4'){
                leds += 4;
            }
            if(num[i] == '5'){
                leds += 5;
            }
            if(num[i] == '6'){
                leds += 6;
            }
            if(num[i] == '7'){
                leds += 3;
            }
            if(num[i] == '8'){
                leds += 7;
            }
            if(num[i] == '9'){
                leds += 6;
            }
            if(num[i] == '0'){
                leds += 6;
            }
            if(num[i] == '\0'){
                break;
            }
            i++;
        }
        printf("%d leds", leds);
    }

    return 0;
}