#include <stdio.h>

int main (){
    long int casos, num, i, n1 = 10, n2 = 10, n3 = 10, n4 = 10, n5 = 10;

    scanf("%d", &casos);

    for(i = 0; i < casos; i++){
        scanf("%d", &num);
        if(num < n1){
            n5 = n4;
            n4 = n3;
            n3 = n2;
            n2 = n1;
            n1 = num;
            continue;
        }
        if(num < n2 && num > n1){
            n5 = n4;
            n4 = n3;
            n3 = n2;
            n2 = num;
            continue;
        }
        if (num < n3 && num > n2 && num > n1){
            n5 = n4;
            n4 = n3;
            n3 = num;
            continue;
        }
        if (num < n4 && num > n3 && num > n2 && num > n1){
            n5 = n4;
            n4 = num;
            continue;
        }
        if (num < n5 && num > n4 && num > n3 && num > n2 && num > n1){
            n5 = num;
            continue;
        }
    }
    printf("%d", n5);
    
    return 0;
}