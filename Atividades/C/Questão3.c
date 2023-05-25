#include <stdio.h>

int main (){
    int dia, diad, mes, mesd, ano, total = 0, subd, subm, suba, anosbis[100], falta = 0;
    int casos, i, j, k = 0, l = 0, m1 = 0;
    scanf("%d", &casos);
    for (j = 1900; j < 2099; j++){
        if(j%4 == 0){
            anosbis[k] = j;
            k++;
        }
    }
    for (i = 0; i < casos; i++){
        total = 0;
        scanf("%d %d, %d %d %d", &diad, &mesd, &dia, &mes, &ano);
            while(anosbis[l] < ano){
               l++;
            }
            falta = anosbis[l] - ano;
        if(diad == 29 && mesd == 2){
            total = total + (falta*365);
        }
        if (mesd == mes && diad > dia){
            subd = diad - dia;
            total = total + (subd);
        }
        if (diad == dia && mesd == mes){
            total = 365;
            if(falta == 1){
                total++;
            }
        }
        if (mesd == mes && diad < dia){
            if(ano%4 == 0){
                total = total + 1;
            }
            subd = dia-diad;
            total = total + (365-subd);
        }
        if (mesd > mes){
            subm = mesd - mes;
            total = total + (subm*30); 
            if(ano%4 == 0 && mes < 2 && mesd > 2){
                total = total + 1;
            }
            for (m1 = mes; m1 < mesd; m1++){
                if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12){
                    total++;
                }
            }
        }
        if (mesd < mes){
            subm = mesd - mes;
            if(subm < 0 || subm == 0){
                subm = mesd - mes;
                subm = subm + 1;
                total = total - 4;
            }
            total = total + (365 - (subm*30));
            if(ano%4 == 0){
                total = total + 1;
            }
            for (m1 = mesd; m1 < mes; m1++){
                if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12){
                    total++;
                }
            }
        }
        if (diad > dia){
            total = total + (diad - dia);
        }
        printf("%d\n", total);
    }

    return 0;
}

/*Professor, provavelmente o caso 2, que acertei antes, dará errado... Me falaram que o output é 0 porém ajustei para mostrar a data do próximo aniversário que seria 365.
No caso 3, parece que o output não está contando 2020 como um ano bissexto, meu código dá 366 e o output é 365 (ou acerta o caso 2 ou o 3 com esses output).

Ajeitei os casos 4 e 5, erro meu não ter contado os meses com 31 dias, faltou um 'for' para saber qual tinha 31 dias e qual não.*/