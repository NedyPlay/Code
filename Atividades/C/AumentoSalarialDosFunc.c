#include<stdio.h>
#include <stdlib.h>

struct DATA {
    int dia;
    int mes;
    int ano;
} Data;

struct FUNCIONARIO {
    int matricula;
    int dia;
    int mes;
    int ano;
    float salario;
} Funcionario;

int main(void) {
    FILE *func;
    struct FUNCIONARIO;
    struct DATA;
    char nome[20];
    int diaat, mesat, anoat, difano, i, j;
    float salariomin, resultado, porcentagem, aumento = 0, salarioinicial;
    scanf("%s", nome);
    scanf("%d %d %d\n", &diaat, &mesat, &anoat);
    scanf("%f", &salariomin);

    if((func = fopen(nome,"rb")) == NULL)
	{
		puts("Arquivo nao pode ser aberto");
		return 1;
	}
    for(j = 0; j < 3; j++){
        aumento = 0;
        porcentagem = 0;
        
        fread(&Funcionario, sizeof(Funcionario) , 1, func);
        /*fscanf(func, "%d %d %d %d %f", &Funcionario.matricula, &DATA.dia, &DATA.mes, &DATA.ano, &Funcionario.salario);
        fscanf*(func,"\n");*/
        
        
        printf("%d ", Funcionario.matricula);
        printf("R$%.2f ", Funcionario.salario);
        difano = anoat - Funcionario.ano;
        salarioinicial = Funcionario.salario;
        
        
            if(Funcionario.salario<(3*salariomin)){
                resultado = Funcionario.salario*1.15;
                aumento = aumento + Funcionario.salario*0.15;
                Funcionario.salario = resultado;
            }
            else if(Funcionario.salario<(5*salariomin) && Funcionario.salario >(3*salariomin)){
                resultado = Funcionario.salario*1.125;
                aumento = aumento + Funcionario.salario*0.125;
                Funcionario.salario = resultado;
            }
            else if(Funcionario.salario<(10*salariomin) && Funcionario.salario >(5*salariomin)){
                resultado = Funcionario.salario*1.10;
                aumento = aumento + Funcionario.salario*0.1;
                Funcionario.salario = resultado;
                
            }
            else if(Funcionario.salario >(10*salariomin)){
                resultado = Funcionario.salario*1.05;
                aumento = aumento + Funcionario.salario*0.05;
                Funcionario.salario = resultado;
            }
            printf("%d", Data.ano);
            if(difano >= 10){
                resultado = Funcionario.salario*1.10;
                aumento = aumento + Funcionario.salario*0.1;
                Funcionario.salario = resultado;
            }

        printf("R$%.2f ",resultado);
        porcentagem = (aumento*100)/salarioinicial;
        printf("%.1f%%\n", porcentagem);
    }
    return 0;
}
