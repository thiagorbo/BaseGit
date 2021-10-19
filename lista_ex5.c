/*5. Faça um programa que preencha três vetores com cinco posições cada. O primeiro
vetor recebera os nomes de cinco funcionários. O segundo e o terceiro vetor receberão,
respectivamente, o salário e o tempo de serviço de cada um. Mostre um primeiro
relatório apenas com os nomes dos funcionários que não terão aumento; mostre o
segundo relatório apenas com os nomes e os novos salários dos funcionários que terão
aumento. Sabe-se que os funcionários que terão direito ao aumento são aqueles que
possuem tempo de serviço superior a cinco anos ou salário inferior a R$ 400,00. Sabese,
ainda, que se o funcionário satisfizer as duas condições anteriores (tempo de serviço
e salário) o aumento será de 35%; para o funcionário que satisfizer apenas a condição de
tempo de serviço, o aumento será de 25%; para o funcionário que satisfizer apenas a
condição de salário, o aumento será de 15%.*/

#include <stdio.h>
#include <stdlib.h>
#define T 2 /*?? Ver erro quando T == 1*/
#define LIMPA_BUFFER __fpurge(stdin)/*?? Tem outra alternativa?*/

void valida_salario(void);
void relatorio_sem_aumento(void);
void relatorio_com_aumento(void);

struct ficha_funcionario{ /*Definindo estrutura de dados para tratar cada funcionario*/
    char nome[25];
    float salario;
    unsigned short tempo_servico;
    unsigned short cond_salario; /*0 - Sem aumento, 1- Aumento de 35%, 2 - Aumento de 25%, 3 - Aumento de 15%*/
};

typedef struct ficha_funcionario Aumento; /*Definindo o nome 'Aumento' para esta estrutra*/

Aumento funcionario[T]; /*Cria vetor para cada enesimo funcionario*/

int main(){

    int i;

    /*Preenchimento dos dados dos funcionarios*/
    for(i = 0; i < T; i++){
        printf("Funcionario %d", i + 1);
        printf("\nDigite o nome do funcionario: ");
        fgets(funcionario[i].nome, T, stdin);
        LIMPA_BUFFER;
        printf("Digite o salario do funcionario: ");
        scanf("%f%*c", &funcionario[i].salario);
        printf("Digite o tempo de casa funcionario: ");
        scanf("%hu%*c", &funcionario[i].tempo_servico);
        printf("\n\n");
    }

    valida_salario(); /*Faz a verificacao de condicao de aumento*/
    relatorio_sem_aumento(); /*Relatorio dos que nao receberao aumento*/
    relatorio_com_aumento(); /*Relatorio dos que receberao aumento*/

return 0;
}

void valida_salario(void){

    int i;

    for(i = 0; i < T; i++){ /*LaÃ§o para verificacao de condicoes*/
        if(funcionario[i].tempo_servico >= 60 || funcionario[i].salario <= (float)400.00){
            if(funcionario[i].tempo_servico >= 60 && funcionario[i].salario <= (float)400.00)
                funcionario[i].cond_salario = 1; /*Atribui um 'codigo' para cada condicao*/
            else if(funcionario[i].tempo_servico >= 60 && funcionario[i].salario > (float)400.00)
                funcionario[i].cond_salario = 2; /*Atribui um 'codigo' para cada condicao*/
            else if(funcionario[i].salario > (float)400.00 && funcionario[i].tempo_servico < 60)
                funcionario[i].cond_salario = 3; /*Atribui um 'codigo' para cada condicao*/
        }
        else
            funcionario[i].cond_salario = 0; /*Atribui um 'codigo' para cada condicao*/
    }
}

void relatorio_sem_aumento(void){

    int i;

    printf("\n\n*****RELATORIO: FUNCIONARIOS SEM AUMENTO*****\n\n");

    for(i = 0; i < T; i++)
        if(!funcionario[i].cond_salario){
            printf("Funcionario: ");
            puts(funcionario[i].nome); /*?? Esta imprimindo apenas os caracteres T*/
        }
}

void relatorio_com_aumento(void){
    int i;

    printf("\n\n*****RELATORIO: FUNCIONARIOS COM AUMENTO*****\n\n");

    for(i = 0; i < T; i++){
        switch (funcionario[i].cond_salario){
            case 1:
                printf("Funcionario: ");
                puts(funcionario[i].nome); /*?? Esta imprimindo apenas os caracteres T*/
                printf("Salario Atual: %.2f\nNovo Salario: %.2f\n", funcionario[i].salario, funcionario[i].salario * 1.35);
                break;
            case 2:
                printf("Funcionario: ");
                puts(funcionario[i].nome); /*?? Esta imprimindo apenas os caracteres T*/
                printf("Salario Atual: %.2f\nNovo Salario: %.2f\n", funcionario[i].salario, funcionario[i].salario * 1.25);
                break;
            case 3:
                printf("Funcionario: ");
                puts(funcionario[i].nome); /*?? Esta imprimindo apenas os caracteres T*/
                printf("Salario Atual: %.2f\nNovo Salario: %.2f\n", funcionario[i].salario, funcionario[i].salario * 1.15);
                break;
        }
    }
}
