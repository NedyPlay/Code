#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void PrintVetor(int* Vetor, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", Vetor[i]);
    }
}
int ScanVetorX(int* x,int n){
    int i;
    for(i = 0; i < n; i++){
        printf("Digite o valor para x[%d]\n", i);
        scanf("%d", &x[i]);
    }
    printf("Vetor X [ ");
    PrintVetor(x, n);
    printf("]\n");
    return x;
}

int ScanVetorY(int* y,int n){
    int i;
    for(i = 0; i < n; i++){
        printf("Digite o valor para y[%d]\n", i);
        scanf("%d", &y[i]);
    }
    printf("Vetor Y [ ");
    PrintVetor(y, n);
    printf("]\n");
    return y;
}

int main (){
    int x[MAX];
    int y[MAX];
    int a;
    int i, j, n;
    printf("Digite o valor para n: ");
    scanf("%d", &n);
    ScanVetorX(x, n);
    printf("Digite o valor de a: ");
    scanf("%d", &a);
    ScanVetorY(y, n);
    printf("Salvando em y o resultado de Ax + y\n");
    printf("Para o vetor X = [ ");
    PrintVetor(x, n);
    printf("]\n");
    printf("Vetor A = %d\n", a);
    printf("E com Y = [ ");
    PrintVetor(y, n);
    printf("]\n");

    for(j = 0; j < n; j++){
        y[j] = (a*x[j]) + y[j];
    }

    printf("Resultado de Ax + y:\n");
    printf("[ ");
    PrintVetor(y, n);
    printf("]");
    return 0;
}
