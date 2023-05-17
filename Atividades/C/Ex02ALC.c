#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void PrintVetor(float *Vetor, int n){
    int i;
    printf("[ ");
    for(i = 0; i < n; i++){
        printf("%.2f ", Vetor[i]);
    }
    printf("]\n");
}
void PrintMatriz(float Matriz[MAX][MAX], int Linhas, int Colunas){
    int i, j;
    printf("Matriz A:\n");
    for(i = 0; i < Linhas; i++){
        printf("[ ");
        for(j = 0; j < Colunas; j++){
            printf("%.2f ", Matriz[i][j]);
        }
        printf("]\n");
    }
}
void ScanVetorX(float* x,int Colunas){
    int i;
    for(i = 0; i < Colunas; i++){
        printf("Digite o valor para x[%d]\n", i);
        scanf("%f", &x[i]);
    }
    printf("Vetor X: ");
    PrintVetor(x, Colunas);
    return x;
}
void ScanMatriz(float *Matriz[MAX][MAX],int Linha, int Coluna){
    int i, j;
    for(i = 0; i < Linha; i++){
        for(j = 0; j < Coluna; j++){
            printf("Valor do elemento a[%d][%d]: ", i+1, j+1);
            scanf("%f", &Matriz[i][j]);
        }
    }
}
void ScanVetorY(float* y,int Colunas){
    int i;
    for(i = 0; i < Colunas; i++){
        printf("Digite o valor para y[%d]\n", i);
        scanf("%f", &y[i]);
    }
    printf("Vetor Y: ");
    PrintVetor(y, Colunas);
}

int main (){
    float x[MAX];
    float y[MAX];
    float ax[MAX];
    float a[MAX][MAX];
    int i, j, Colunas, Linhas;
    printf("Digite o numero de Linhas: ");
    scanf("%d", &Linhas);
    printf("Digite o numero de Colunas: ");
    scanf("%d", &Colunas);
    ScanMatriz(a, Linhas, Colunas);
    PrintMatriz(a, Linhas, Colunas);
    ScanVetorX(x, Colunas);
    ScanVetorY(y, Linhas);
    
    printf("Formando a o vetor Ax\n");
    int k = 0;
    for(i = 0; i < Linhas; i++){
        ax[k] = 0;
        for(j = 0; j < Colunas; j++){
            ax[k] = ax[k] + a[i][j]*x[j];
        }
        k++;
    }
    printf("Vetor Ax: \n");
    PrintVetor(ax, Linhas);
    printf("Vetor Y antes da operacao Ax + y: \n");
    PrintVetor(y, Linhas);

    for (i = 0; i < k; i++){
        y[i] = (ax[i] + y[i]); 
    }
    printf("Vetor Y apos operacao Ax + y: \n");
    PrintVetor(y, Linhas);
    return 0;
}