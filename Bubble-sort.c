/*O bubble sort, ou ordenação por flutuação é um algoritmo de ordenação dos mais simples.
 A ideia é percorrer o vector diversas vezes, e a cada passagem fazer flutuar para o topo o maior elemento da sequência.
 Essa movimentação lembra a forma como as bolhas em um tanque de água procuram seu próprio nível, e disso vem o nome do algoritmo.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define T 100000  //Tamanho do vetor
#define G 10 //Quantidade Rand

void bubble_easy (int vetor[], int t);
void bubble_medium(int vetor[],int t);
void bubble_hard(int vetor[],int t);

int main(){
	int i,vetor[T],opcao;
	system("Color 4f");setlocale(LC_ALL,"Portuguese");srand(time(0));
	bubble_hard(vetor,T);
	/*
	printf("\n\t\tBEM VINDO AO MÉTODO BUBBLE SORT\n");
	printf("\nComplexidade computacional ---> ");
	printf("Pior caso: [n²]");
	printf("\tMelhor caso: [n]");
	do{
		printf("\n\nESCOLHA A OPÇÃO DE ORDENAÇÃO DE ACORDO COM O NÍVEL\n\n");
		printf("1. Easy\t\t");
		printf("2. Medium\t\t");
		printf("3. Hard\t\t");
		printf("OU\t4. Para Sair\t\n");
		printf("\nOPÇÃO: ");
		scanf("%d",&opcao);
		system("cls");
		switch(opcao){
			case 1:
				bubble_easy(vetor,T);
				break;
			case 2:
				bubble_medium(vetor,T);
				break;
			case 3:
				bubble_hard(vetor,T);
				break;
			case 4:
				opcao=0;
				break;
			default:
				printf("Opção inválida!!\n");
		}
	}while(opcao!=0);*/
	return 0;
}

/*
//Primeiro metodo
void bubble_easy(int vetor[],int t){
	int i,j,aux;
	printf("Vetor gerado\n\n");
	for(i=0;i<t;i++){
		vetor[i]=rand()%G;printf("[%d]\t",vetor[i]);
	}
	for(i=0;i<t;i++){
		for(j=0;j<t;j++){
			if(vetor[i]<vetor[j]){
				aux=vetor[i];
				vetor[i]=vetor[j];
				vetor[j]=aux;
			}
		}
	}
	printf("\n\nOrdenação  Easy: \n");
	for(i=0;i<t;i++){
		printf("[%d]\t",vetor[i]);
	}
}

//Segundo metodo 
void bubble_medium (int vetor[], int t){
	int i,j,aux;
	printf("Vetor gerado\n\n");
	for(i=0;i<t;i++){
		vetor[i]=rand()%G;printf("[%d]\t",vetor[i]);
	}
	for(i=0;i<t;i++){
		for(j=i+1;j<T;j++){
			if(vetor[i]>vetor[j]){
				aux=vetor[i];
				vetor[i]=vetor[j];
				vetor[j]=aux;
			}
		}
	}
	printf("\n\nOrdenação Easy: \n");
	for(i=0;i<t;i++){
		printf("[%d]\t",vetor[i]);
	}
}*/

//Terceiro metodo 
void bubble_hard(int vetor[],int t){
	int x,y,i,aux;
	printf("Vetor gerado\n\n");
	for(i=0;i<t;i++){
		vetor[i]=rand()%G;printf("[%d]\t",vetor[i]);
	}
	for(x=1;x<t;x++){
		for(y=t-1;y>=x;y--){
			if(vetor[y-1]>vetor[y]){
				aux=vetor[y-1];
				vetor[y-1]=vetor[y];
				vetor[y]=aux;
			}
		}
	}
	printf("\n\nOrdenação Hard: \n");
	for(x=0;x<t;x++){
		printf("[%d]\t",vetor[x]);
	}
	printf("\n");
}
