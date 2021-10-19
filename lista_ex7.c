/*7. Elabore uma sub-rotina que receba como parâmetro uma matriz A (6,6) e multiplique
cada linha pelo elemento da diagonal principal daquela linha. A sub-rotina deverá
retornar a matriz alterada pra ser mostrada no programa principal. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define T 3

void preenche_matriz_aleatorio(int[T][T]);
void multiplica_diagonal_principal(int[T][T]);
void mostra_nova_matriz(int[T][T]);

int main(){

    int matriz[T][T];

    srand(time(NULL));

    preenche_matriz_aleatorio(matriz);
    multiplica_diagonal_principal(matriz);
    mostra_nova_matriz(matriz);

return 0;
}

void preenche_matriz_aleatorio(int mat[T][T]){

    int i, j;

    for(i = 0; i < T; i++)
        for(j = 0; j < T; j++)
            mat[i][j] = rand() % 11;
}

void multiplica_diagonal_principal(int mat[T][T]){
    int i, j;

    for(i = 0; i < T; i++)
        for(j = 0; j < T; j++)
            mat[i][j] *= mat[i][i];
}

void mostra_nova_matriz(int mat[T][T]){

    int i, j;

    for(i = 0; i < T; i++){
        for(j = 0; j < T; j++)
            printf("m[%d][%d] = %d\t", i, j, mat[i][j]);
        printf("\n");
    }

}
