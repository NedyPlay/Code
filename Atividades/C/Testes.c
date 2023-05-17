#include <stdio.h>

int main(void){

    int linhas, x, y, qtd;
    float valor, num, maiorN, diferenca;

    scanf("%d", &linhas);

    for(x=0; x < linhas; x++){
        scanf("%d", &qtd);
        
        for(y=0; y < qtd; y++){
            
            scanf("%f", &valor);

            if(y==0){
                num = valor;
            }
            else if(y==1){
                if(valor>num){
                    diferenca = valor-num;
                }
                else{
                    diferenca = num-valor;
                }
            }
            else{
                if(valor>num){
                    if((valor-num) <= diferenca){
                        diferenca = valor-num;
                        maiorN = valor;
                    }
                }
                else{
                    if((num-valor) <= diferenca){
                        diferenca = num-valor;
                        maiorN = valor;
                    }
                }
            }
        }

        printf("%.1f\n", maiorN);
    }

    return 0;
}