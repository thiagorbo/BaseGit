/* 1. Pedro comprou um saco de ração com peso em quilos. Ele possui dois gatos, para os
quais fornece uma quantidade de ração em gramas. A quantidade diária de ração
fornecida para cada gato é sempre a mesma. Faça um programa que recebe o peso do
saco de ração e a quantidade de ração fornecida para cada gato, calcula e mostra quanto
restará de ração no saco após cinco dias.*/ 

#include <stdio.h>
#define DIA_CONSUMO 5
#define QNT_GATOS 2

void racao (void);
void solicita_peso (void);
float recebe_peso (void);
void solicita_racao_gato(void);
float calcula_resta_racao (float, float);
void informa_resto (float);
void quantidade_insuficiente(void);

int main(){

racao();

return 0;
}

void racao(){

float peso_racao, peso_racao_gato, resto_racao;

solicita_peso();
peso_racao = recebe_peso();

solicita_racao_gato();
peso_racao_gato = recebe_peso();

resto_racao = calcula_resta_racao(peso_racao, peso_racao_gato);
if(resto_racao < 0)
quantidade_insuficiente();
else
informa_resto(resto_racao);
}

void solicita_peso(){
printf("Informe o peso do saco de racao (em kg): ");
}

float recebe_peso(){

float peso;

scanf("%f", &peso);

return peso;
}

void solicita_racao_gato(){
printf("Informe a quantidade de racao fornecida p/ cada gato (em g): ");
}

float calcula_resta_racao(float racao_kg, float racao_g){
return (racao_kg * 1000) - (racao_g * QNT_GATOS * DIA_CONSUMO);
}

void informa_resto(float resto_g){
printf("\nAo final de %d dias, restara %.0f gramas de racao (%.2f kg)\n", DIA_CONSUMO, resto_g, resto_g / 1000);
}

void quantidade_insuficiente(){
printf("\nA quantidade disponivel sera insuficiente");
}
