#include <stdio.h>
#include <string.h>
#define MAX 20

int main (){
    int num, temp, i = 0, j = 0;
    char invhexa[MAX];
    scanf("%d", &num);
    while(num > 0){

        temp = num%16;
        num = num / 16;

        if (temp == 0){
            invhexa[i] = '0';
        }
        else if (temp == 1){
            invhexa[i] = '1';
        }
        else if (temp == 2){
            invhexa[i] = '2';
        }
        else if (temp == 3){
            invhexa[i] = '3';
        }
        else if (temp == 4){
            invhexa[i] = '4';
        }
        else if (temp == 5){
            invhexa[i] = '5';
        }
        else if (temp == 6){
            invhexa[i] = '6';
        }
        else if (temp == 7){
            invhexa[i] = '7';
        }
        else if (temp == 8){
            invhexa[i] = '8';
        }
        else if (temp == 9){
            invhexa[i] = '9';
        }
        else if (temp == 10){
            invhexa[i] = 'A';
        }
        else if (temp == 11){
            invhexa[i] = 'B';
        }
        else if (temp == 12){
            invhexa[i] = 'C';
        }
        else if (temp == 13){
            invhexa[i] = 'D';
        }
        else if (temp == 14){
            invhexa[i] = 'E';
        }
        else if (temp == 15){
            invhexa[i] = 'F';
        }
        i++;
    }
    invhexa[i] = '\0';

    j = strlen(invhexa);
    j = j - 1;
    for (j; j>=0; j--){
        printf("%c", invhexa[j]);
    }
    
    
    return 0;
}