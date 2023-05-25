#include <stdio.h>
#include <stdlib.h>

//Ponteiro para próximo e anterior
typedef struct Elemento elemento;
struct Elemento {
	int num;
	elemento *proximo;
	elemento *anterior;
};
//Cria 2 variáveis globais.
elemento *inicio;
elemento *fim;
int tam;

//Cria a lista com 2 elementos nulos
void criaLista() {
	inicio = NULL;
	fim = NULL;
	tam = 0;
}
//Aloca espaço
elemento *aloca(int num) {
	elemento *novo = (elemento*) malloc(sizeof(elemento));
	novo->num = num;
	novo->anterior = NULL;
	novo->proximo = NULL;
	return novo;
}

//Remove elementos exatos da lista
void removeElementoIgual(int num){
	if(num == fim->num){
		removeFim(); //Se o número é do fim da lista, tem prioridade
		printf("Removendo o valor: %d\n", num); //Remove o número desejado
	}
	else{
		if (num == inicio->num){
			removeInicio();
			printf("Removendo o valor: %d\n", num); //Remove o número desejado
		}
		else{ //Remove elemento do meio da lista
			int hd[2000]; //Disco para não perder valores
			int i, tam2 = 0;
			int inf = 654654654;
    		elemento *atual;
			atual = inicio;
			while(atual){
				if((atual->num - num) == 0){ //Detecta o valor
        		    atual->num = inf;
        		    while(atual->num == inf){
						if(fim->num == inf){
							printf("Removendo o valor: %d\n", num); //Remove o número desejado
							removeFim();
							for(tam2 = tam2 - 1; tam2 > -1; tam2--){
								insereFim(hd[tam2]); //Recupera os valores
							}
							tam2 = 0;
							break;
						}
						else{
							for(i = 0; fim->num != inf; i++){
								hd[i] = fim->num; //salva os valores antes de remover
								printf("Salvando: %d\n", hd[i]);
								removeFim();
								tam2++; //numeros de valores retirados
							}
						}
					}
				}
				atual=atual->proximo;
			}
		}

	}
	
}

//Remove um elemento do inicio da lista
void removeInicio() {
	elemento *atual = inicio;
	inicio = atual->proximo;
	inicio->anterior = NULL;
	tam--; //diminui o tamanho lista
}

//Remove um elemento do fim da lista
void removeFim() {
	elemento *atual = fim;
	fim = atual->anterior;
	fim->proximo = NULL;
	tam--;
}

//Insere no inicio da lista
void insereInicio(int num) {
	elemento *novo = aloca(num);   //criar novo elemento
	if(inicio==NULL){ //Se o inicio é nulo, o fim tbm é
		inicio=novo;
		fim=novo;

	}else{
		elemento *atual; //Criar novo elemento caso tenha dado no inicio da lista.
		atual = inicio;
		novo->proximo = atual;
		atual->anterior = novo;
		inicio = novo;
	}
	tam++;
}

//Inserir no fim da lista:
void insereFim(int num) {
	elemento *novo = aloca(num);   //Cria novo elemento e aloca espaço
	if(inicio==NULL){ //msm esquema de inserir no inicio, caso o inicio for nulo.
		inicio=novo;
		fim=novo;
		printf("Inserindo: %d\n", num);
	}else{
		elemento *atual; //cria novo elemento e aloca espaço
		atual = fim; //atual recebe fim já existente
		novo->anterior = atual; //o anterior do novo recebe o fim anterior
		atual->proximo = novo; //o proximo do atual é o novo elemento
		fim = novo; //o fim passa ser o novo elemento
		printf("Inserindo: %d\n", num);
	}
	tam++; //aumenta o tamanho da lista
}


//Função para imprimir a lista:
void imprimeLista() {
	elemento *atual;
	atual = inicio;
	while(atual){
		printf("%d\n",atual->num);
		atual=atual->proximo;
	}
}


int main() {
	criaLista();
	int i;
	for(i=0; i<5; i++){
		insereInicio(i);
	}
	insereFim(40);
    removeElementoIgual(3);
	imprimeLista();
}
