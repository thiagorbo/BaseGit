/*4. Faça um programa para corrigir provas de múltiplas escolhas. Cada prova tem 8
questões e cada questão vale 1 ponto. O primeiro conjunto de dados a ser lido é o
gabarito da prova. Os outros dados são os números dos alunos e suas respectivas
respostas que deram as questões. Existem 10 alunos matriculados. Calcule e mostre: (1)
Para cada aluno seu numero e sua nota; (2) A percentagem de aprovação, sabendo-se
que a nota mínima é 6,0.*/

#include <stdio.h>
#define QUESTOES 5
#define QNT_ALUN 3
#define LIMPA_TELA "clear" /*Tornar o codigo minimamente portavel*/

/*Prototipo das funcoes*/
void recebe_gabarito_prova(char[]);
float corrige_prova_aluno(char[], char[]);

/*Estrutura para os dados do aluno*/
struct ficha_aluno{
    unsigned int numero_cad;
    char resposta[QUESTOES];
    float media;
};
/*Definicao da estrutura para etiqueta Aluno*/
typedef struct ficha_aluno Aluno;

int main(){
    Aluno aluno[QNT_ALUN]; /*A ficha sera criada para QNT_ALUN alunos*/
    char gabarito[QUESTOES];
    int i;
    float percentagem_aprovacao;

    printf("Digite o gabarito da prova!\n\n");
    recebe_gabarito_prova(gabarito);

    /*Entrada e processamento dos dados*/
    for(i = 0; i < QNT_ALUN; i++){

        system(LIMPA_TELA); /*Para nenhum aluno colar*/

        printf("** Aluno %d**\n", i + 1);
        printf("Digite o RA: ");
        scanf("%u%*c", &aluno[i].numero_cad);

        recebe_gabarito_prova(aluno[i].resposta); /*Recebe as respostas do aluno i*/

        aluno[i].media = 10.0 / QUESTOES * corrige_prova_aluno(gabarito, aluno[i].resposta); /*Compara os gabaritos e calcula a media*/
    }

    /*Saida das notas*/
    percentagem_aprovacao = 0;

    for(i = 0; i < QNT_ALUN; i++){
        printf("RA: %hu / Nota: %.2f / Situacao: ", aluno[i].numero_cad, aluno[i].media);
        if(aluno[i].media >= (float)6.0){
            printf("APROVADO!\n");
            percentagem_aprovacao++;
        }
        else
            printf("REPROVADO!\n");

    }

    printf("\nProfessor, sua sala teve %.2f%% de aprovacao!", percentagem_aprovacao / QNT_ALUN * 100);

return 0;
}

void recebe_gabarito_prova(char resp_prova[]){

    int i, erro;

    for(i = 0; i < QUESTOES; i++){
        erro = 0;
        do{
            if(erro)
                printf("Opcao incorreta! Digite novamente!\n");
            printf("Gabarito** Questao %d: ", i + 1);

            scanf("%c%*c", &resp_prova[i]);
            erro++;
        }while(resp_prova[i] < 'a' || resp_prova[i] > 'f');
    }
}

float corrige_prova_aluno(char prova_aluno[], char prova_gabarito[]){
    int i;
    float nota;

    nota = 0.0;

    for(i = 0; i < QUESTOES; i++){
        if(prova_aluno[i] == prova_gabarito[i])
            nota++;

    }
return nota;
}
