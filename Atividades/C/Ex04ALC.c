#include <stdio.h>
#include <math.h>
#include <locale.h>

#define MAX 200

void printar(int dim, int iteracao,float values[dim]){
    int i;
    printf("Iteracao %d \n", iteracao);
    for(i = 0 ;i < dim; i++){
    printf("[ ");
    printf("Valor[%d]= %f ",i+1,values[i]);
  printf("\n");
  }
}
float findSum(int dim, int i, float a[dim][dim]){
     float soma = 0;
     for(int j=0;j<dim;j++){
       if(i != j){
         soma = soma + a[i][j];
       }
     }
     return soma;
} 
void ModVetor(int dim, float Vetor[dim]){
    int i;
    for(i = 0; i < dim; i++){
        Vetor[i] = Vetor[i];
    }
}
float MaxNoVetor(int dim, float Vetor[dim]){
    int i;
    ModVetor(dim, Vetor);
    float aux = Vetor[0];
    for(i = 1; i < dim; i++){
        if(Vetor[i] > aux){
            aux = Vetor[i];
        }
    }
    return aux;
}
void VRecebeV(int dim, float Vetor1[dim], float Vetor2[dim]){
    int i;
    for(i = 0; i < dim; i++){
        Vetor1[i] = Vetor2[i];
    }
}
void ZeraVetor(int dim, float Vetor[dim]){
    int i;
    for(i = 0; i < dim; i++){
        Vetor[i] = 0;
    }
}
void PrintVetor(float *Vetor, int n){
    int i;
    printf("[ ");
    for(i = 0; i < n; i++){
        printf("%.2f ", Vetor[i]);
    }
    printf("]\n");
}
void PrintMatriz(int Linhas, int Colunas, float Matriz[Linhas][Colunas]){
    int i, j;
    printf("Matriz A:\n");
    for(i = 0; i < Linhas; i++){
        printf("[ ");
        for(j = 0; j < Colunas; j++){
            if(Matriz[i][j] < 10){
                printf("%.2f  ", Matriz[i][j]);
            }
            else{
                printf("%.2f ", Matriz[i][j]);
            }
        }
        printf("]\n");
    }
}
void ScanMatriz(int Linhas, int Colunas, float Matriz[Linhas][Colunas], float TermoIndependente[Colunas]){
    int i, j;
    for(i = 0; i < Linhas; i++){
        for(j = 0; j < Colunas; j++){
            printf("Valor do elemento a[%d][%d]: ", i+1, j+1);
            scanf("%f", &Matriz[i][j]);
        }
        printf("Insira o Termo Independente da linha %d: ", i+1);
        scanf("%f", &TermoIndependente[i]);
    }
    PrintMatriz(Linhas, Colunas, Matriz);
}
void ScanVetorInicial (int dim, float VetorInicial[dim]){

    int i;
    printf("Insira o vetor inicial: ");
    for (i = 0; i < dim; i++){
        scanf("%f", &VetorInicial[i]);
    }
    printf("Vetor Inicial: ");
    PrintVetor(VetorInicial, dim);
}
void ZerarTudo(int dim, float Matriz[dim][dim], float TermoIndependente[dim], float VetorInicial[dim]){
    int i, j;
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            Matriz[i][j] = 0;
        }
        TermoIndependente[i] = 0;
        VetorInicial[i] = 0;
    }
}
void GerarMatrizQ4(int dim, float Matriz[dim][dim], float TermoIndependente[dim], float VetorInicial[dim]){
    int i, j;
    for(i = 0; i < dim; i++){       //Preenchendo o vetor inicial
        VetorInicial[i] = 1;
    }


    float h = 0.1;
    Matriz[0][0] = (-2*(1+(h*h)))*VetorInicial[0]; 
    Matriz[0][1] = VetorInicial[1];                 //Primeira linha da Matriz
    for(i = 2; i < dim; i++){
        Matriz[0][i] = 0;
    }
    TermoIndependente[0] = 1;
    i = 0;

    for(i = 1; i < dim; i++){
        for(j = 0; j < dim; j++){
            if(i == j){
                Matriz[i][j-1] = VetorInicial[j-1];
                Matriz[i][j] = (-2*(1+(h*h)))*VetorInicial[j];
                Matriz[i][j+1] = VetorInicial[j+1];
            }
        }
    }

    Matriz[dim-1][dim-2] = VetorInicial[dim-1];
    Matriz[dim-1][dim-1] = (-2*(1+(h*h)))*VetorInicial[dim-1];
    TermoIndependente[dim-1] = 1;
}
void GerarMatrizP2(int dim, float Matriz[dim][dim], float TermoIndependente[dim], float VetorInicial[dim]){
    int i, j;
    for(i = 0; i < dim; i++){       //Preenchendo o vetor inicial
        VetorInicial[i] = 1+i;
    }
    i = 0;

    //Criar Matriz[i][j], linha por linha
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            if(i != j){
                if(i > j){
                    Matriz[i][j] = 10 - (10 - (i - j));
                }
                else if(j > i){
                    Matriz[i][j] = j-i;
                }
                else{
                    Matriz[i][j] = j;
                }
            }
            else{
                Matriz[i][j] = 0;
            }
        }
    }
    i = 0;
    for(i = 0; i < dim; i++){
        TermoIndependente[i] = i+1;
    }
}
/*void GaussJacobi (int dim, float Matriz[dim][dim], float TermoIndependente[dim], float VetorIni[dim], float Resultado[4], int Contagem[4]){

}*/
void EliminacaoGaussParcial(int dim, float Matriz[dim][dim], float TermoIndependente[dim]){
    float Aux[dim][dim];
    int i, j, k;
    for(i = 0; i < dim; i++){
        for(j = i+1; j < dim; j++){
            Aux[i][j] = (-Matriz[i][j]/Matriz[i][i]);
            Matriz[i][j] = 0;
            for(k = j+1; k < dim; k++){
                Matriz[i][k] = Matriz[i][k] + Aux[i][j]*Matriz[j][k];
                TermoIndependente[j] = TermoIndependente[j] + Aux[j][k]*TermoIndependente[i];
            }
        }
    }
}

int main (){
    int opc, dim;
    printf("insira a Dimensao do Sistema Linear: \n");
    scanf("%d", &dim);
    printf("A dimensao eh %d\n", dim);
    float Matriz[dim][dim];
    float TermoIndependente[dim];
    float VetorInicial[dim];
    float Resultado[4];
    int Contagem[4]; 
    ZerarTudo(dim, Matriz, TermoIndependente, VetorInicial);
    PrintMatriz(dim, dim, Matriz);
    GerarMatrizP2(dim, Matriz, TermoIndependente, VetorInicial);
    PrintMatriz(dim, dim, Matriz);
    EliminacaoGaussParcial(dim, Matriz, TermoIndependente);
    PrintMatriz(dim, dim, Matriz);
    PrintVetor(TermoIndependente, dim);

    return 0;
}