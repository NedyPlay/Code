#include <stdio.h>


int main (){
 int dia, diad, mes, mesd, ano, total = 0, subd, subm, suba, anosbis[100], falta = 0, anoebis = 0, ano1ebis = 0;
    int casos, i, j, k = 0, l = 0;
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
                if(ano == anosbis[l]){
                    anoebis = 1;
                }
                if(ano+1 == anosbis[l]){
                    ano1ebis = 1;
                }
               l++;
            }
            falta = anosbis[l] - ano;   
        int jan, fev, mar, abr, maio, jun, jul, ago, set, out, nov, dez;
        
        jan= 31;

        if(mesd < mes && anoebis = 1){
            fev = 29;
        }
        else if(ano1ebis = 1 && mesd > 2){
            fev = 29;
        }
        else{
            fev = 28;
        }
        mar = 31;
        abr = 30;
        maio = 31;
        jun = 30;
        jul = 31;
        ago = 31;
        set = 30;
        out = 31;
        nov = 30;
        dez = 31;

    if(mes == 01){
        subm = jan - dia;
    }
    if(mes == 02){
        subm = fev - dia;
    }
    if(mes == 03){
        subm = mar - dia;
    }
    if(mes == 04){
        subm = abr - dia;
    }
    if(mes == 05){
        subm = maio - dia;
    }
    if(mes == 06){
        subm = jun - dia;
    }
    if(mes == 07){
        subm = jul - dia;
    }
    if(mes == 08){
        subm = ago - dia;
    }
    if(mes == 09){
        subm = set - dia;
    }
    if(mes == 10){
        subm = out - dia;
    }
    if(mes == 11){
        subm = nov - dia;
    }
    if(mes == 12){
        subm = dez - dia;
    }
    }
    if (mesd > mes){

    }

        
}