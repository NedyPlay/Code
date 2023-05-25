#include <stdio.h>
#include <string.h>
int main (){

    int casos, i, j, k, repet, erro = 0, zerador = 0;
    char string[11], stringAceita[11], stringPassada[11];

    scanf("%d", &casos);
    for(i = 0; i < casos; i++){
        for(zerador = 0; zerador < 11; zerador++){
            string[zerador] = '0';
            stringPassada[zerador] = '0';
            stringAceita[zerador] = '0';
        }
        for(j = 0; j < 4; j++){
            scanf("%d", &repet);
            for (k = 0; k < repet+1; k++){
                scanf("%c", &string[k]);
                if(string[k] == 'A' || string[k] == '4' || string[k] == 'a'){
                    string[k] = 'a';
                }
                else if(string[k] == 'E' || string[k] == '3' || string[k] == 'e'){
                    string[k] = 'e';
                }
                else if(string[k] == 'I' || string[k] == '1' || string[k] == 'i'){
                    string[k] = 'i';
                }
                else if(string[k] == 'O' || string[k] == '0' || string[k] == 'o'){
                    string[k] = 'o';
                }
                else if(string[k] == 'Z' || string[k] == '2' || string[k] == 'z'){
                    string[k] = 'z';
                }
                else{
                    string[k] = string[k];
                }
                stringAceita[k] = string[k];
                printf("%c e %c\n", stringPassada[k], stringAceita[k]);
                if (j > 1){
                    if(stringPassada[k] != stringAceita[k]){
                        erro = 1;
                    }
                }
                stringPassada[k] = stringAceita[k];
            }
        }
        if (erro == 1){
            printf("N\n");
            erro = 0;
        }
        else {
            printf("S\n");
        }
    }
    return 0;
}