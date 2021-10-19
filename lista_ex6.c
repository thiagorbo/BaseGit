/*6. Elabore uma sub-rotina que retorne ao programa principal um vetor com os três
primeiros números perfeitos. Sabe-se que um número é perfeito quando é igual à soma
de seus divisores (exceto ele mesmo). Exemplo: os divisores de 6 são 1, 2 e 3 e 1 + 2 +
3 = 6, logo, 6 é perfeito.*/

#include <stdio.h>
#define T 4
#define TRUE 1

int soma_divisores(int);
int valida_numero_perfeito(int, int);

int main(void){

    int vet[T];
    int i, j;
    int numero_teste;

    j = 0;

    for(i = 4; j < T; i++){ /*2 e 3 sao primos*/
        numero_teste = soma_divisores(i);
        if(valida_numero_perfeito(numero_teste, i)){
            vet[j] = i;
            j++;
        }
    }

    printf("Os numeros perfeitos sao: \n");
    for(i = 0; i < T; i++){
        printf("%d\n", vet[i]);
    }

return 0;
}

int soma_divisores(int num){

    int i, soma;

    soma = 0;

    for(i = 1; i <= num / 2; i++){
        if(!(num % i)){
            soma += i;
        }
    }

return soma;
}

int valida_numero_perfeito(int soma, int num){
    return soma == num;
}
