/* Árvore AVL é uma árvore binária de busca balanceada, ou seja, uma árvore balanceada 
são as árvores que minimizam o número de comparações efetuadas no pior 
caso para uma busca com chaves de probabilidades de ocorrências idênticas. */
# include <windows.h>
# include <stdlib.h>
# include <stdio.h>
# include <conio.h>
# include "avl-tree.h"

/* Funcao que inicia a arvore */
void criaGalhoNulo(arv**raiz)
{ /* Inicio da funcao*/
  *raiz = NULL;  /* Inicia raiz como nula */
}/* Final da funcao */
    
/* Funcao que aloca nos na arvore */
void galho(arv**raiz, int elemento)
{/* Inicio da funcao */
  *raiz = (arv*)malloc(sizeof(arv)); /* Cria dinamicamente o no */
  (*raiz)->num = elemento; /* (*raiz)->num recebe elemento */
  (*raiz)->esq = NULL; /* Ponteiro da esquerda recebe NULL */
  (*raiz)->dir = NULL; /* Ponteiro da direita recebe NULL */

} /* Final da funcao */

/* funcao que insere os elementos */
void insereElemento(arv**raiz, int elemento)
{/* Inicio da funcao */
     if(*raiz == NULL) /* Se a raiz for nula*/
     {
       galho(&*raiz, elemento); /* Insere na raiz */
     }else /* senao */
     {
       if((*raiz)->num > elemento) /* se raiz maior que elemento */
       {
         insereElemento(&(*raiz)->esq,elemento); /* insere ba esquerda */
         /*se o fator de balanceamanto for < -1 ou > 1 */
         if(balanceamento(*raiz) < -1 || balanceamento(*raiz) > 1)
         {
           /*se o elemento for menor que raiz esquerda */
           if(elemento < (*raiz)->esq->num)
           {
             aviso(); /*Mostra um aviso na tela*/
             /*Realiza a rotacao para direita*/
             *raiz = rotacaoDireita(*raiz); return;
           }else /*Senao*/
           {
             aviso1(); /*Mostra um aviso na tela*/
             /*Realiza a rotacao dupla para esquerda */
             *raiz = duplaEsquerda(*raiz); return;
           }
         }
       }
       /* Se o raiz for maior que o elemento */
       if((*raiz)->num < elemento)
       {
         /*insere o elemento na direita da arvore */
         insereElemento(&(*raiz)->dir,elemento);
         /*se o fator de balanceamanto for < -1 ou > 1 */
         if(balanceamento(*raiz) < -1 || balanceamento(*raiz) > 1)
         {
           /* Se o elemento for maior que a raiz direita */
           if(elemento > (*raiz)->dir->num)
           {
             aviso2(); /*Mostra um aviso na tela*/
             /* Realiza a rotacao para esquerda */
             *raiz = rotacaoEsquerda(*raiz); return;
           }else /* Senao */
           {
             aviso3();/*Mostra um aviso na tela*/
             /*Realiza a rotcao dupla para direita*/
             *raiz = duplaDireita(*raiz); return;
           }
         }
       }
       /*Se a raiz for igual ao elemento*/  
       if((*raiz)->num == elemento)
       {
         mensagem();/*Mostra um aviso na tela*/
       }
     } 
}/* Final da funcao */


/* Funcao que mostra a arvore na tela */
void impressao(arv*raiz)
{/* Inicio da funcao*/
  /* Se a raiz for diferente de NULL*/
  if(raiz!=NULL)
  {
   printf("(");
   printf("%d",(raiz)->num); /*Imprime  a raiz*/
   printf(",(");
   /*Imprime  a raiz esquerda*/
   impressao(raiz->esq);
   printf("),(");
   /*Imprime  a raiz direita*/
   impressao(raiz->dir);
   printf(")");
   printf(")");
   
  }
}/*Final da funcao */

/* Funcao que retorna o menor elemento da direita */
arv** menorDireito(arv*raiz)
{ 
  arv** aux = &raiz;  /* variavel auxiliar */
  if((*aux)->dir != NULL) /*se (*aux)->dir for diferente de NULL */
  {
    aux = &(*aux)->dir;   /* Aux recebe &(*aux)->dir*/
    while((*aux)->esq != NULL) /* enguanto (*aux)->esq for diferente de NULL*/
    {
      aux = &(*aux)->esq; /* aux recebe &(*aux)->esq*/
    }
  }
  return aux; /* retorna aux */
}

/* Funcao que retorna o maior da esquerda */
arv** maiorEsquerdo(arv*raiz)
{
  arv** aux = &raiz; /* variavel auxiliar */
  if((*aux)->esq != NULL) /* Se (*aux)->esq for difirente de NULL */
  {
    aux = &(*aux)->esq;  /* Aux rcebe &(*uax)->esq */
    while((*aux)->dir != NULL) /* Enguanto (*uax)->dir for diferente de NULL */
    {
      aux = &(*aux)->dir; /* Aux recebe &(*aux)->dir */
    }
  }
  return aux;  /*Retornar aux */
}

/*Funcao que busca determinado elemento*/
void busca(arv *raiz, int elemento)
{/*Inicio da funcao */

  /* Se raiz for diferente de NULL*/
  if(raiz != NULL)
  {
    /* Se raiz maior que elemento*/
    if((raiz)->num > elemento)
    {
     /* Busca para esquerda */
      printf("%3d,",raiz->num);
      /* enviando os dados buscados para esquerda*/
      busca(raiz->esq, elemento);
      
      /* senao */
    }else
    {
      /*Se raiz menor que elemento */
      if(raiz->num < elemento)
      {
      /* Busca para direita  */
        printf("%3d,",raiz->num);
         /* enviando os dados buscados para direita*/
        busca(raiz->dir, elemento);
        
      }else /*Senao*/
      {
        /* Se raiz igual ao elemento */
        if(raiz->num == elemento)
        {
          /* Encontrou o elemento */
          printf("%3d",raiz->num);
        }
      }
    }
    /* Senao */
  }else
  {
    /* Imprime uma mensagem na tela */
    cor(11); posicao(25,1),linha(1,201);linha(30,205),linha(1,187);
    posicao(25,2);printf("\272 Numero n\xc6o encontrado!!\t\272");
    posicao(25,3);linha(1,200);linha(30,205),linha(1,188);
    getch(); system("cls");
  
  }
}/*Final da funcao*/


/* Funcao que exclui determinados elementos da arvore */
void excluirElemento(arv**raiz, int elemento)
{
  arv **aux1, *aux2; /*Variaveis auxiliares*/
  arv* aux = *raiz; /* Variavel auxiliar */
  
  if(*raiz != NULL) /* Se *raiz fo diferente de NULL*/
  {
    if((*raiz)->num == elemento)  /* Se (*raiz)->num for igual ao numero */
    {
      if((*raiz)->esq == (*raiz)->dir) /* Se (*raiz)->esq igual (*raiz)->dir*/
      {
         printf("\nr = %d\n",elemento); /*mostra uma mensagemna tela */
        free(*raiz);  /*Apaga (*raiz)*/
        *raiz = NULL; /* Raiz recebe NULL*/
      }else /* Senao */
      {
        if((*raiz)->esq != NULL) /*Se (*raiz)->esq diferente de NULL*/
        {
          aux1 = maiorEsquerdo(*raiz); /*aux1 recebe o maior esquerdo da arvore*/
          aux2 = *aux1; /*aux2 recebe *aux1*/
          (*aux1) = (*aux1)->esq; /*(*aux1) recebe (*aux1)->esq*/
        }else /*Senao*/
        {
          aux1 = menorDireito(*raiz);/* aux1 recebe o menor direito da arvore*/
          aux2 = *aux1; /* Aux2 recebe (*aux1)*/
          (*aux1) = (*aux1)->dir; /* (*aux1) recebe (*aux1)->dir */
        }
        (*raiz)->num = aux2->num; /* (*raiz)->num recebe aux2->num*/
        free(aux2); /* Libera aux2*/
        aux2 = NULL; /* aux2 recebe NULL*/
      }
    }else /* Senao*/
    {
     if((*raiz)->num < elemento) /*se (*raiz)->num menor que numero */
     {
       /*Envia o numero para a direita da arvore*/
       excluirElemento(&(*raiz)->dir,elemento); 
       /*Se o numero for apagado a arvore é atualizada e balanceada*/
       atualizaEsq(&(*raiz),elemento);
     }
     if((*raiz)->num > elemento) /* Se (*raiz)->num maior que numero*/
     {
      /*Envia o numero para esquerda da arvore*/
       excluirElemento(&(*raiz)->esq,elemento);
       /*Se o numero for apagado a arvore é atualizada e balanceada*/
       atualizaDir(&(*raiz),elemento);
     }         
    }
  }else /*Senao*/
  {
   /*Mostra uma mensagem colorida na tela*/
    cor(11); posicao(25,1),linha(1,201);linha(30,205),linha(1,187);
    posicao(25,2);printf("\272 Numero n\xc6o encontrado!!\t\272");
    posicao(25,3);linha(1,200);linha(30,205),linha(1,188);
    getch(); system("cls");
  }
 // impressao(aux3);
}


/* Funcao que conta a altura da esquerda*/
int contEsq(arv*raiz)
{
  arv* aux = raiz; /*variavel auxiliar*/
  int cont = 0; /* variavel do tipo inteiro recebe 0*/
  
  if(aux->esq == NULL) /* se aux->esq == NULL*/
  {
    return 0; /*Retorna 0*/
  }else /* Senao */
  {
    while(aux->esq != NULL) /* Enquanto aux->esq diferente de NULL*/
    {
      aux = aux->esq; /*aux recebe aux->esq*/
      cont = cont + 1; /* cont recebe cont + 1*/
      /* Se aux-<esq igual a NULL e aux->dir diferente de NULL*/
      if(aux->esq == NULL && aux->dir != NULL)
      {
        while(aux->dir != NULL) /*Enquanto aux->dir diferente de NULL*/
        {
         cont = cont + 1; /* cont recebe cont + 1*/
         aux = aux->dir; /*aux recebe aux->dir*/
        }
      }
    }
    return cont; /*retornar cont*/
  }
}

/* Funcao que conta a altura da direita */
int contDir(arv*raiz)
{
  arv* aux = raiz; /* variavel auxiliar */
  int cont = 0; /*variaavel to tipo inteiro recebe 0*/
  
  if(aux->dir == NULL) /*Se aux->dir for igual a 0*/
  {
    return 0; /*Retorna zero*/
  }else /* Senao*/
  {
    while(aux->dir != NULL) /*enquanto aux->dir for diferente de NULL*/
    {
      aux = aux->dir; /*aux recebe aux->dir */
      cont = cont + 1; /*cont recebe cont + 1*/
      /*Se aux->dir == NULL e aux->esq diferente NULL*/
      if(aux->dir == NULL && aux->esq != NULL)
      {
        while(aux->esq != NULL) /*enquanto aux->esq diferente de NULL*/
        {
         cont = cont + 1; /*cont recebe cont + 1 */
         aux = aux->esq; /*aux recebe aux +1 */
        }
      }
    }
    return cont; /*retorna cont */
  }
}

/* Funcao que calcula o fator de balanceamento*/
int balanceamento(arv*raiz)
{
  arv* aux = raiz; /*Variavel auxiliar*/
  int bl = 0; /* variavel do tipo inteiro recebe 0*/
  /*bl recebe contDir(aux) - contEsq(aux)*/
  bl = contDir(aux) - contEsq(aux);
  return bl; /*ratorna bl*/
}

/* Funcao que realiza a rotacao dupla  para esquerda */
arv* duplaEsquerda(arv*raiz)
{
     arv* aux = raiz; /*variavel auxiliar*/
     /*aux->esq recebe rotacaoEsquerda(aux)->esq*/
     aux->esq = rotacaoEsquerda(aux->esq);
     /*aux recebe rotacaoDireita(aux)*/
     aux = rotacaoDireita(aux);
     return aux; /*retorna aux*/
}

/* Funcao que realiza a rotacao dupla para direita */
arv* duplaDireita(arv*raiz)
{
  arv* aux = raiz; /*variavel auxiliar*/
  /*aux->dir recebe rotacaoDireita(aux->dir)*/
  aux->dir = rotacaoDireita(aux->dir);
  /*aux recebe rotacaoEsquerda(aux)*/
  aux = rotacaoEsquerda(aux);
  return aux; /*retorna aux*/
}

/* Funcao que realiza a rotacao para direita*/
arv* rotacaoDireita(arv*raiz)
{
  arv* aux = raiz; /*variavel auxiliar*/
  arv* A = aux; /*variavel auxiliar A recebe aux*/
  arv* B = aux->esq; /*Variavel auxiliar B recebe aux->esq*/
  
   A->esq = B->dir; /*A->esq recebe B->dir*/
   B->dir = A; /*B->dir recebe A*/
   return B; /*retorno B*/
}

/* Funcao que realiza a rotacao para Esquerda*/
arv* rotacaoEsquerda(arv*raiz)
{
  arv* aux = raiz; /*Variavel auxiliar*/
  arv* A = aux; /* Variavel auxiliar A recebe aux*/
  arv* B = aux->dir; /* Variavel auxilar B recebe aux->dir*/
  
  A->dir = B->esq; /*A->dir recebe B->esq*/
  B->esq = A; /*B->eesq recebe A*/
  return B; /*retorna B*/
}

/* Funcao que faz os balanceamentos apos a exclusao */
void atualizaDir(arv**raiz, int elemento)
{
  arv* aux1 = (*raiz)->dir; /*variavel auxiliar aux1 recebe (*raiz)->dir*/
  arv* aux = *raiz; /*variavel auxiliar*/
  
  while((aux) != NULL) /*enquanto aux for diferente de NULL*/
  {
     /*se balanceamanto(aux) for menor que -1 ou maior que 1*/
     if(balanceamento(aux) < -1 || balanceamento(aux) > 1)
     {
       if(aux1->dir != NULL)/*se aux1->dir for diferente de NULL*/
       {                      
        /*(*raiz) recebe rotacaoEsquerda(*raiz)*/
        *raiz = rotacaoEsquerda(*raiz); 
        break;/*termina a funcao*/
       }else /* senao*/
       {
        /*(*raiz) recebe duplaDireita(*raiz)*/
        *raiz = duplaDireita(*raiz);
        break; /*Termina funcao*/
       }
       
     }
     /*aux recebe aux->dir*/
     (aux) = (aux)->dir;
  }
}

/* Funcao que faz os balanceamentos apos a exclusao */
void atualizaEsq(arv**raiz, int elemento)
{
  /*variavel auxiliar aux1 recebe (*raiz)->esq*/
  arv* aux1 = (*raiz)->esq;
  arv* aux = *raiz; /*variavel auxiliar*/
 
  while(aux != NULL) /*enquanto aux for diferente de NULL*/
  {
     /*se balanceamanto(aux) for menor que -1 ou maior que 1*/
     if(balanceamento(aux) < -1 || balanceamento(aux) > 1)
     {
       if(aux1->esq == NULL) /* Se aux1_>esq for iguala NULL*/
       {                      
        /*(*raiz) recebe duplaEsquerda(*raiz)*/
        *raiz = duplaEsquerda(*raiz); 
        break;/*Termina a funcao*/
       }else /* Senao*/
       {
         /* (*raiz) recebe rotacaoDireita(*raiz)*/
        *raiz = rotacaoDireita(*raiz);
        break; /*Termina a funcao*/
       }
       
     
     }
     /*aux recebe aux->esq*/
     (aux) = (aux)->esq;
  }
}


/* Funcao que mostra um aviso na tela */
void aviso()
{
 /*Mostra uma mensagem colorida na tela*/
  cor(11); posicao(20,1),linha(1,201);linha(48,205),linha(1,187);
  posicao(20,2);printf("\272Ser\xa0 realizado uma rota\x87\xc6o simples a direita!...\272");
  posicao(20,3);linha(1,200);linha(48,205),linha(1,188);
}

/* Funcao que mostra um aviso na tela */
void aviso1()
{
  /*Mostra uma mensagem colorida na tela*/
  cor(11); posicao(16,1),linha(1,201);linha(47,205),linha(1,187);
  posicao(16,2);printf("\272Ser\xa0 realizado uma rota\x87\xc6o dupla a esquerda!...\272");
  posicao(16,3);linha(1,200);linha(47,205),linha(1,188);
}

/* Funcao que mostra um aviso na tela */
void aviso2()
{
  /*Mostra uma mensagem colorida na tela*/
  cor(11); posicao(16,1),linha(1,201);linha(49,205),linha(1,187);
  posicao(16,2);printf("\272Ser\xa0 realizado uma rota\x87\xc6o simples a esquerda!...\272");
  posicao(16,3);linha(1,200);linha(49,205),linha(1,188);
}

/* Funcao que mostra um aviso na tela */
void aviso3()
{
  /*Mostra uma mensagem colorida na tela*/
  cor(11); posicao(16,1),linha(1,201);linha(46,205),linha(1,187);
  posicao(16,2);printf("\272Ser\xa0 realizado uma rota\x87\xc6o dupla a direita!...\272");
  posicao(16,3);linha(1,200);linha(46,205),linha(1,188);
   
}

/* Funcao que mensagem um aviso na tela */
void mensagem()
{
     /*Mostra uma mensagem colorida na tela*/
     cor(11); posicao(25,1),linha(1,201);linha(30,205),linha(1,187);
     posicao(25,2);printf("\272Este numero j\xa0 esta na lista !\272");
     posicao(25,3);linha(1,200);linha(30,205),linha(1,188);
}

/* Mostra um menu de opcoes na tela */
void menu(int *op)
{
     /*Mostra um menu colorido na tela*/
cor(11);posicao(25,1),linha(1,201);linha(30,205);linha(1,187);
posicao(25,2);printf("\272 1  \x1a Insere numeros \t\t\272");
posicao(25,3);linha(1,204);linha(30,205);linha(1,185);
posicao(25,4);printf("\272 2  \x1a  Visualizar    \t\t\272");
posicao(25,5);linha(1,204);linha(30,205);linha(1,185);
posicao(25,6);printf("\272 3  \x1a Buscar elemento\t\t\272");
posicao(25,7);linha(1,204);linha(30,205);linha(1,185);
posicao(25,8);printf("\272 4  \x1a     Excluir    \t\t\272");
posicao(25,9);linha(1,204);linha(30,205);linha(1,185);
posicao(25,10);printf("\272 5 \x1a ABRIR O ARQUIVO DE TEXTO\t\272");
posicao(25,11);linha(1,204);linha(30,205);linha(1,185);
posicao(25,12);printf("\272 6 \x1a       Sair      \t\t\272");
posicao(25,13);linha(1,200);linha(30,205);linha(1,188);
posicao(25,16);cor(10);printf("Digite uma op\x87\xc6o \x1a ");
scanf("%d",op);
}

/*Funcao  que decide a cor de fundo ou de texto */
void cor(WORD cor)
{
 HANDLE SaidaSTD = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(SaidaSTD, cor);
}

/*Funcao que desenha caracteres na tela(determina caracter e tamanho */
void linha(int q, int a)
{
  int j;
  for(j = 1; j <= q; j++)
   printf("%c",a);
}    

/* Funcao que decida as coordenadas da tela como um plano carteziano*/
void posicao(int x, int y)
{
 HANDLE SaidaSTD = GetStdHandle(STD_OUTPUT_HANDLE);
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(SaidaSTD, coord);
}

/* Funcao que ler os numeros */
void lerNumero(int *numero)
{
 system("cls");     
cor(11); printf("\nDigite um numero = ");
cor(12); scanf("%d",numero);
 system("cls");
}

/*Funcao que carrega os dados gravados no arquivo */
int carregaArquivo(arv**raiz)
{
    int elemento; /* variavel do tipo inteiro*/
    FILE* arquivo; /*variavel do tipo FILE*/
    arquivo = fopen("avl.txt","r"); /*arquivo aberto para leitura*/
    fseek(arquivo,0,SEEK_END); /*recebendo coordenadas do arquivo*/
    
    if(ftell(arquivo) == 0) /* se ftell(arquivo) for igual a 0 Bites*/
    {
      return 0; /*retorna 0*/
    }
    
      fseek(arquivo,0,SEEK_SET); /*recebendo coordenadas do arquivo */
      
      if(arquivo == NULL) /* se arquivo for igual a NULL*/
      {
        return 0; /* Retorna 0*/
      }else /*senao*/
      {
        while(!feof(arquivo))/*se feof(arquivo)for diferente de NULL*/
        {
          fscanf(arquivo,"%d",&elemento); /*retira os elemento do arquivo*/
          /*insere os elementos do arquivo na arvore*/
          insereElemento(&(*raiz),elemento);
        }
        system("cls");
      }
      /*fecha o arquivo*/
      fclose(arquivo);
        return 1; /*retorna 1*/
}

/* Funcao que cria o arquivo para armazenar os elemento digitados */
void criarArquivo(FILE* arquivo)
{
/* abre arquivo para leitura*/
 arquivo = fopen("avl.txt", "r");
 if(arquivo == NULL) /* se arquivo for igual a NULL*/
 {
  /*Abre arquivo para leitura e escrita*/
  arquivo = fopen("avl.txt", "a");
  fclose(arquivo);  /*fecha arquivo*/
 }else /*senao*/
 {
  return; /*retorna*/
  }

}

/* Funcao que escreve os elementos inseridos na arvore , no arquivo*/
void EscreverArquivo(FILE* arquivo, int elemento)
{
 /*Abre arquivo para escritae leitura */
  arquivo = fopen("avl.txt", "a");    
  /*escreve no arquivo o elemento*/  
  fprintf(arquivo,"%3d",elemento);
  /*fecha o arquivo*/
  fclose(arquivo);
}

/*funcao que atualiza o arquivo*/
void salva(arv *raiz)
{
  /*variavel do tipo FILE*/ 
  FILE* arquivo;
  
  /*Abre arquivo para escrita*/
  arquivo = fopen("avl.txt", "w");
  /*escreve os elementos no arquivo*/
  grava(raiz,arquivo);
  /*fecha o arquivo*/
  fclose(arquivo);
}
  
/*funcao que escreve no arquivo os elementos atualizados da arvore*/
void grava(arv*raiz, FILE* arquivo)
{
  if(raiz != NULL) /*se raix for diferente de NULL*/
  {
   grava(raiz->esq,arquivo); /*busca os elementos na esquerda da arvore*/
   fprintf(arquivo,"%3d", raiz->num); /*grava os elementos no arquivo*/
   grava(raiz->dir,arquivo);/*busca os elementos na direita da arvore */
  }
}
