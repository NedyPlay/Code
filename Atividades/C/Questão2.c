#include <stdio.h>

int main (){
    int casos, num;
    int i, cont = 0;
    scanf("%d", &casos);

    for (i = 0; i < casos; i++){
        scanf("%d", &num);
        cont = 0;
        while (num != 1){
            if(num%2 != 0){
                num = (3*num)+1;
                cont++;
            }
            if(num%2 == 0){
                num = num/2;
                cont++;
            }
        }
        printf("%d\n", cont);
    }

    return 0;
}
