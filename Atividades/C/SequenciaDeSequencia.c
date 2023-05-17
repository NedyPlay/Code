#include <stdio.h>
int main()  {
    
    int n, i, total, caso = 1, casos;
        scanf("%d", casos);
    for(i = 0; i < casos; i++){
        scanf("%d", &n);
        total = 1;
        int num = n;
        while (num > 0)
            total += num--;
        printf("Caso %i: %i numero", caso++, total);
        if (n)
            printf("s");
        printf("\n0");

        int cont;
        while (++num <= n) {
            cont = num;
            while (cont-- > 0)
                printf(" %i", num);
        }
        printf("\n\n");
    }
    return 0;
}