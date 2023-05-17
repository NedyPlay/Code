#include <stdio.h>
#include <string.h>

int main (){
    int n, m, i, j, cont, erro = 0, linhainicial, colunainicial, linhachegada, colunachegada;
    char mapa[100][100], in, fi;
    in = 'I';
    fi = 'F';
    scanf("%d %d", &n, &m);
    
    for(i = 1; i < n+1; i++){
        for(j = 1; j < m+1; j++){
            scanf("\n%c", &mapa[i][j]);
            if (mapa[i][j] == in){
                linhainicial = i;
                colunainicial = j;
                printf("Linha inicial eh %d e Coluna %d\n", linhainicial, colunainicial);
            }
            if (mapa[i][j] == fi){
                linhachegada = i;
                colunachegada = j;
                printf("Linha final eh %d e Coluna %d\n", linhachegada, colunachegada);
            }
        
        }
    }
    cont = 0;
    while(colunainicial != colunachegada || linhainicial != linhachegada){
        if(mapa[linhainicial][colunainicial+1] == 'B' || mapa[linhainicial][colunainicial+1] == 'F'){
            colunainicial++;
        }
        else if(mapa[linhainicial-1][colunainicial] == 'B' || mapa[linhainicial-1][colunainicial] == 'F'){
            linhainicial--;
        }
        else if(mapa[linhainicial+1][colunainicial] == 'B' || mapa[linhainicial+1][colunainicial] == 'F'){
            linhainicial++;
        }
        else if(mapa[linhainicial][colunainicial-1] == 'B' || mapa[linhainicial][colunainicial-1] == 'F'){
            colunainicial--;
        }
        
        printf("Inicial %d %d\n", linhainicial, colunainicial);
        printf("Chegada %d %d\n", linhachegada, colunachegada);
        cont++;
        if(cont == 100){
            erro = 1;
            break;
        }
    }
    if(erro == 1){
        printf("N");
    }
    else{
        printf("S");
    }
    return 0;
}