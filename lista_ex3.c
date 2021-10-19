/*3. Faça um programa que preencha um vetor com dez números inteiros. Calcule e
mostre um vetor resultante ordenado de maneira decrescente.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10
#define LIMITE 99 + 1

void preenche_vetor(int[]);
void ordena_vetor(int[]);
void mostra_vetor(int[]);

int main(){
    int vet[TAM];

    preenche_vetor(vet);
    ordena_vetor(vet);
    mostra_vetor(vet);
return 0;
}

void preenche_vetor(int preenche[]){
    int i;

    srand(time(0));

    for(i = 0; i < TAM; i++){
        preenche[i] = rand() % LIMITE;
    }
}

void ordena_vetor(int ord[]){

    int i, j;
    int temp;

    for(i = 0; i < TAM - 1; i++)
        for(j = i + 1; i < TAM; j++)
            if(ord[i] < ord[j]){
                temp = ord[i];
                ord[i] = ord[j];
                ord[j] = temp;
            }
}

void mostra_vetor(int mos[]){
    int i;

    for(i = 0; i < TAM; i++){
        printf("vet[%02d]: %d", i + 1, mos[i]);
    }
}
