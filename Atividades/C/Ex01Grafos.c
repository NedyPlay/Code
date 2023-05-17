#include <stdio.h>
#include <stdlib.h>

// Macros para criar tabela de quantidade de bits em 1 em um byte
#define B2(n) n, n + 1, n + 1, n + 2
#define B4(n) B2(n), B2(n + 1), B2(n + 1), B2(n + 2)
#define B6(n) B4(n), B4(n + 1), B4(n + 1), B4(n + 2)
#define QUANT_BITS B6(0), B6(1), B6(1), B6(2)
 
// tabela de quantidade de bits em 1 em um byte.
const unsigned int __qbits_tab[256] = { QUANT_BITS };
 
// Função para contar cardinalidade da interseção
// a,b: ponteiros para vetores de bytes
// n: quantidade de bytes em cada vetor
int card_inters(char a, char* b, int nb)
{
    int ret = 0;
    // percorre bytes dos vetores
    for (int i = 0; i < nb; i++)
        ret += __qbits_tab[a & b[i]];    // i-esimo byte
    return ret;
}

//Usando a função card_inters como medida de similaridade entre dois conjuntos, implemente a função

// S: vetor de elementos
// n: quantidade de elementos em S
// a: elemento
// nb: quantidade de bytes em cada elemento
// k: quantidade de similares

void simil(char * S, int n, char a, int nb, int k){
    int i;
    char b [200];
        if (card_inters(a,b,nb) > card_inters(a,b,nb)){
            k++;
        }
    printf("Final %d ", k);
    
}

void print_conj(char* a, int nb)
{
    printf("{");
    for (int b = 0, i = 0; b < nb; b++)
        for (int j = 0; j < 8; j++, i++)
        {
            a[b] >>= j;
            if (a[b] & 1)
                printf(" %c", a[j]);
        }
    printf(" }");
}
void print_mat(char* Mat){
    for(int i = 0; i < 11; i++){
        printf("%c", Mat[i]);
    }
    printf("\n");
}
int main()
{
    printf("START!\n");
    long long int intmat = 20210012601;
    int n = 11;
    printf("n = %d\n", n);
    char mat[] = "20210012601";
    print_mat(mat);
    char S[n];
    int i, k, l, j;
    for (int i = 0, k = 0, l = 0; i < n; i++, l += 8){
        printf("i = %d\n k = %d\n l = %d\n", i, k, l);
        for (int j = 0; j < n; j++, k++){
            printf("j = %d\n", j);
            printf("mat = %c\n", mat[k]);
            S[k] = mat[k] & ~(~j << l);
            printf("S[%d] = %c \n", k, S[k]);
        }
    }
    
    simil(S, n, mat, n, 10);
    printf("Conjuntos mais similares a %lld:\n", intmat);
    print_conj(S, n);
    printf("\n-----------------------\n");
    for (int i = 0; i < 10; i++)
    {
        printf("S[%d] = %llu\n", i, S[i]);
        print_conj(S, n);
        printf("\n");
    }
    return 0;
}

