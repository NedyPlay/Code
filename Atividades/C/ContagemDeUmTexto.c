#include <stdio.h>


int main (){
    FILE *func;
    char nome[100], digt[1000];
    int i, frase = 0, digitos, palavras = 0, flag = 0, caa = 0;
    scanf("%s", nome);
    if((func = fopen(nome,"r")) == NULL)
	{
		puts("Arquivo nao pode ser aberto");
		return 1;
	}

    while(digt != EOF){
        fscanf(func, "%c", digt);
        digitos++;
        if(digt == '.'){
            frase++;
        }
        else if(digt == ' '){
            palavras++;
            flag = 1;
        }
        if(digt == 'a' && flag == 1){
            flag = 2;
        }
        
    }

    return 0;
}