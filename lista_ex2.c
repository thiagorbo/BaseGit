/*2. Faça um programa que apresente o menu de opções a seguir, permita ao usuário
escolher a opção desejada, receba os dados necessários para executar a operação e
mostre o resultado. Verifique a possibilidade de opção inválida e não se preocupe com
restrições, como salário negativo.

Menu de opções:
1. Imposto
2. Novo Salário
3. Classificação

Digite a opção desejada:

Na opção 1: receber o salário de um funcionário, calcular e mostrar o valor do imposto
usando as regras a seguir:
Salários Percentual do Imposto
Menor que R$ 500,00 5%
De R$ 500,00 a R$ 850,00 10%
Acima de R$ 850,00 15%

Na opção 2: receber o salário de um funcionário, calcular e mostrar o valor do novo
salário, usando as regras a seguir:

Salário Aumento
Maiores que R$ 1.500,00 R$ 25,00
De R$ 750,00 (inclusive) a R$ 1.500,00 (inclusive) R$ 50,00
De R$ 450,00 (inclusive) a R$ 750,00 R$ 75,00
Menores que R$ 450,00 R$ 100,00

Na opção 3: receber o salário de um funcionário e mostrar sua classificação usando a
tabela a seguir:

Salário Classificação
Até R$ 700,00 (inclusive) Mal remunerado
Maiores que R$ 700,00 Bem remunerado */ 

#include <stdio.h>
#define TRUE 1
#define FALSE 0

/*Prototipos de saida de dados*/
void solicita_opcao(void);
void informa_erro(void);
void solicita_salario(void);
void mostra_imposto (float);
void mostra_novo_salario (float);
void mostra_classificacao (int);
/*Prototipos de entrada de dados*/
int recebe_opcao(void);
float recebe_salario(void);
/*Prototipos de direcionamentos*/
void programa_calcula_salario (void);
void direciona_opcao(int);
void opcao_um (void);
void opcao_dois (void);
void opcao_tres (void);
/*Prototipos de calculos*/
int valida_opcao(int);
float calcula_imposto (float);
float calcula_novo_salario (float);
int calcula_classificacao (float);

int main(){

    programa_calcula_salario();

return 0;
}

void programa_calcula_salario(){

    int opcao, ver_erro;

    ver_erro = 0;


    do{
        if(ver_erro)
            informa_erro();
        solicita_opcao();
        opcao = recebe_opcao();

        ver_erro++;
    }while (valida_opcao(opcao));

    direciona_opcao(opcao);

}

void solicita_opcao(){
    printf("Menu de Opcoes:\n\n1. Imposto\n2. Novo Salario\n3. Classificacao\n\nDigite a opcao desejada: ");
}

int recebe_opcao(){
    int opc;

    scanf("%d", &opc);

return opc;
}

int valida_opcao(int op){
    if(op < 1 || op > 3)
        return TRUE;
    else
        return FALSE;
}

void informa_erro(){
    printf("\nInvalido! Tente novamente\n\n");
}

void direciona_opcao(int opcao){

    switch (opcao){
        case 1:
            opcao_um();
            break;
        case 2:
            opcao_dois();
            break;
        case 3:
            opcao_tres();
            break;
    }

}

void opcao_um(){
    float salario, imposto;

    solicita_salario();
    salario = recebe_salario();
    imposto = calcula_imposto(salario);
    mostra_imposto(imposto);

}

void solicita_salario(){
    printf("\nDigite seu salario: ");
}

float recebe_salario(void){
    float salario;

    scanf("%f", &salario);

return salario;
}

float calcula_imposto(float salario){

    if(salario < (float)500.00)
        return salario * 0.05;
    else if (salario >= (float)500.00 && salario <= (float)850.00)
        return salario * 0.1;
    else
        return salario * 0.15;
}

void mostra_imposto(float imposto){
    printf("\nO imposto a ser pago sera de R$ %.2f", imposto);
}

void opcao_dois(){
    float salario, novo_salario;

    solicita_salario();
    salario = recebe_salario();
    novo_salario = calcula_novo_salario(salario);
    mostra_novo_salario(novo_salario);

}

float calcula_novo_salario(float salario){

    if(salario < (float)450.00)
        return salario + 100.00;
    else if (salario >= (float)450.00 && salario < (float)750.00)
        return salario + 75.00;
    else if (salario >= (float)750.00 && salario <= (float)1500.00)
        return salario + 50.00;
    else
        return salario + 25.00;
}

void mostra_novo_salario(float salario){
    printf("\nO novo salario sera de %.2f", salario);
}

void opcao_tres(){
    float salario;

    solicita_salario();
    salario = recebe_salario();
    mostra_classificacao(calcula_classificacao(salario));

}

int calcula_classificacao(float salario){

    if(salario <= (float)700.00)
        return TRUE;
    else
        return FALSE;
}

void mostra_classificacao(int sim_ou_nao){
    printf("O salario: %s", sim_ou_nao ? "Mal remunerado" : "Bem remunerado");

}

