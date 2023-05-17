#include <stdio.h>

int main (){
    int casos, n;
    double real[100], subtracao, resultado, desejado, numOrig1= 0, numOrig2= 0, SubAnt;
    int i, j;

    scanf("%d", &casos);
    for (i = 0; i < casos; i++){
        n = 0;
        scanf("%d", &n);
        scanf("%lf", &desejado);
        subtracao = 0;
        SubAnt = 101;
        for (j = 0; j < n; j++){
            scanf("%lf", &real[j]);
            if(real[j] > desejado){
                numOrig2 = real[j];
                subtracao = real[j] - desejado;
            }
            if(real[j] < desejado){
                subtracao = desejado - real[j];
            }
            if(real[j] == desejado){
                resultado = real[j];
                numOrig1 = real[j];
            }
            if(subtracao < SubAnt){
                resultado = real[j];
                SubAnt = subtracao;
                numOrig1 = real[j];
            }
            if(subtracao == resultado){
                if(numOrig1 > numOrig2){
                    resultado = numOrig1;
                }
                else{
                    resultado = numOrig2;
                }
            }
        }
        printf("%.1lf\n", resultado);
    }



    return 0;
}