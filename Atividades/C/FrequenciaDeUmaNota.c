#include <stdio.h>

int main (){

    long int nota, i, casos;
    int zero, um, dois, tres, quatro, cinco, seis, sete, oito, nove, dez;
    zero = 0, um = 0, dois = 0, tres = 0, quatro = 0, cinco = 0, seis = 0, sete = 0, oito = 0, nove = 0, dez = 0;
    scanf("%ld", &casos);

    for(i = 0; i < casos; i++){
        scanf("%ld", &nota);
        switch (nota){
        case 0:
            zero++;
            break;
        case 1:
            um++;
            break;
        case 2:
            dois++;
            break;
        case 3:
            tres++;
            break;
        case 4:
            quatro++;
            break;
        case 5:
            cinco++;
            break;
        case 6:
            seis++;
            break;
        case 7:
            sete++;
            break;
        case 8:
            oito++;
            break;
        case 9:
            nove++;
            break;
        case 10:
            dez++;
            break;
        }
    }
    printf("%d %d %d %d %d %d %d %d %d %d %d", zero, um, dois, tres, quatro, cinco, seis, sete, oito, nove, dez);
    return 0;
}