/* O quicksort adota a estratégia de divisão e conquista. A estratégia consiste em rearranjar 
as chaves de modo que as chaves "menores" precedam as chaves "maiores". Em seguida o quicksort 
ordena as duas sublistas de chaves menores e maiores recursivamente até que a lista completa 
se encontre ordenada.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define T 100000
#define V 100000
 
void quick_sort(int *a, int esquerda, int direita);
 
int main(int argc, char** argv){
 int i, vet[T];
 srand(time(0));

 for(i = 0; i < T; i++){
  vet[i]=rand()%V;
  printf("[%d]\t",vet[i]);
 }
 
 quick_sort(vet, 0, T - 1);
 
 printf("\nValores ordenados\n");
 for(i = 0; i < T; i++){
  printf("[%d]\t", vet[i]);
 }
 printf("\n");
 return 0;
}
 
// Função de Ordenação por Seleção

void quick_sort(int *a, int esquerda, int direita) {
    int i, j, x, y;
     
    i = esquerda;
    j = direita;
    x = a[(esquerda + direita) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < direita) {
            i++;
        }
        while(a[j] > x && j > esquerda) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > esquerda) {
        quick_sort(a, esquerda, j);
    }
    if(i < direita) {
        quick_sort(a, i, direita);
    }
}