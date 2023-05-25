#include <stdio.h>
#include <math.h>
#define MAX 500

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
void ScanMatriz(float Matriz[MAX][MAX], float TermoIndependente[MAX] ,int Linhas, int Colunas){
    int i, j;
    for(i = 0; i < Linhas; i++){
        for(j = 0; j < Colunas; j++){
            printf("Valor do elemento a[%d][%d]: ", i+1, j+1);
            scanf("%f", &Matriz[i][j]);
        }
        printf("Insira o Termo Independente da linha %d: ", i+1);
        scanf("%f", &TermoIndependente[i]);
    }
    PrintMatriz(Matriz, Linhas, Colunas);
}
void ScanVetorInicial (float VetorInicial[MAX], int dim){
    int i;
    printf("Insira o vetor inicial: ");
    for (i = 0; i < dim; i++){
        scanf("%f", &VetorInicial[i]);
    }
    printf("Vetor Inicial: ");
    PrintVetor(VetorInicial, dim);
}
void GerarMatrizQ4(float Matriz[MAX][MAX], float TermoIndependente[MAX], float VetorInicial[MAX], int dim){
    int i, j;
    for(i = 0; i < dim; i++){       //Preenchendo o vetor inicial
        VetorInicial[i] = 0;
    }
    
    int h = 0.1;
    Matriz[0][0] = (-2*(1+pow(h, 2)))*VetorInicial[0]; 
    Matriz[0][1] = VetorInicial[1];            //Primeira linha da Matriz
    for(i = 2; i < dim; i++){
        Matriz[0][i] = 0;
    }

    TermoIndependente[0] = 1;

    for(i = 1; i < dim-1; i++){
        Matriz[i][0] = VetorInicial[i-1];  //Linhas do meio da Matriz
        Matriz[i][1] = (-2*(1+pow(h, 2)))*VetorInicial[i];
        Matriz[i][2] = VetorInicial[i];
        for(j = 0; j < dim; j++){
            Matriz[i][j] = 0;
        }
        TermoIndependente[i] = 0;
    }
    Matriz[dim][0] = VetorInicial[dim-1];
    Matriz[dim][1] = (-2*(1+pow(h, 2)))*VetorInicial[dim]; //Ultima linha da Matriz
    for(i = 2; i < dim; i++){
        Matriz[dim][i] = 0;
    }
    TermoIndependente[dim] = 1;
}
void GaussJacobi (float Matriz[MAX][MAX], float TermoIndependente[MAX], float VetorIni[MAX], int dim, float Resultado[MAX]){
    float diagonalVar, soma;
    int i, Linha, Coluna, k, interacoes = 0, aux[MAX];
    int x[MAX];
    printf("Metodo Gauss Jacobi selecionado\n");
    for(i = 0; i < dim; i++){
        Resultado[i] = VetorIni[i];
    }
    while(x[k+1] - x[k] < pow(10, -4)){
       for(Linha = 0; Linha < dim; Linha++){
            diagonalVar = Matriz[Linha][Linha];
            Matriz[Linha][Linha] = 0;
            for(Coluna = 0; Coluna < dim; Coluna++){
               soma = soma + Matriz[Linha][Coluna];
            }
        }
       interacoes++;
    }
}

int main (){
    float Matriz[MAX][MAX];
    float TermoIndependente[MAX];
    float VetorInicial[MAX];
    float Resultado[MAX];
    int opc, dim;
    printf("insira a Dimensao do Sistema Linear: ");
    scanf("%d", &dim);
    GerarMatrizQ4(Matriz, TermoIndependente, VetorInicial, dim);
    PrintMatriz(Matriz, dim, dim);




    printf("Aproximacao para um sistema Linear\n");
    printf("Escolha um desses metodos:\n");
    printf("[ 1 ] Gauss Jacobi\n");
    printf("[ 2 ] Gauss Seidel\n");
    printf("[ 3 ] Metodo SOR\n");
    printf("[ 4 ] Gradiente Conjulgado\n");
    scanf("%d", &opc);
    switch (opc){
    case 1:
        GaussJacobi(Matriz, TermoIndependente, VetorInicial, dim, Resultado);
        break;
    case 2:
        printf("Boa");
        break;
    case 3:

        break;
    case 4:

        break;
    default:
        printf("Valor Invalido!");
        break;
    }


    return 0;
}