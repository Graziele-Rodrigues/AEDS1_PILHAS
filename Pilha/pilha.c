#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"  //usa aspas duplas pois esta na raiz do projeto

/* corpo das funcoes que possuem assinatura em lsita.h */

void LerProduto(TProduto *x) { //passando por referencia -> alteraçoes afetam fora da funcao
  printf("\nDigite o codigo:");
  scanf("%d", &x->codigo);
}

void ImprimirProduto(TProduto x) { // passagem por valor
  printf("Codigo: %d\n", x.codigo);
}


void FPVazia(TPilha *Pilha){
  Pilha->topo = (TCelula*) malloc(sizeof(TCelula));
  Pilha->fundo = Pilha->topo;
  Pilha->topo->prox = NULL;
  Pilha->tamanho =0;
}

int Vazia(TPilha Pilha){
  return (Pilha.topo == Pilha.fundo);
}

int Tamanho(TPilha Fila) { return Fila.tamanho; } 


void Empilha(TProduto x, TPilha *Pilha){
  TCelula *Aux;
  Aux = (TCelula*) malloc(sizeof(TCelula));
  Pilha->topo->item = x;
  Aux->prox = Pilha->topo;
  Pilha->topo =  Aux;
  Pilha->tamanho++;
}

void Desempilha(TPilha *Pilha, TProduto *Item){
  TCelula *q;
  if(Vazia(*Pilha)){
    printf("Lista Vazia!\n");
  }
  q = Pilha->topo;
  Pilha->topo = q->prox;
  *Item = q->prox->item;
  free(q);
  Pilha->tamanho--;
}

void Imprimir1(TPilha *P1){
  TProduto x;
  TPilha P2;
  FPVazia(&P2);

  while(!Vazia(*P1)){
    Desempilha(P1, &x);
    ImprimirProduto(x);
    Empilha(x, &P2);
  }
  while(!Vazia(P2)){
    Desempilha(&P2, &x);
    Empilha(x, P1);
  }
  Libera(&P2);
}

void Imprimir2(TPilha *P1){
  TProduto x;
  TPilha P2;
  FPVazia(&P2);
  int n1 = Tamanho(*P1);
  while(n1!=0){
    Desempilha(P1, &x);
    ImprimirProduto(x);
    Empilha(x, &P2);
    n1--;
  }
  int n2 = Tamanho(P2);
  while(n2!=0){
    Desempilha(&P2, &x);
    Empilha(x, P1);
    n2--;
  }
  Libera(&P2);
}


TProduto Pesquisar(TPilha *P1, TProduto x){
  TPilha P2;
  FPVazia(&P2);
  TProduto y, z;
  int flag=0;
  while(!Vazia(*P1)){
    Desempilha(P1, &y);
    Empilha(y, &P2);
    if(y.codigo == x.codigo){
      flag = 1;
      z =y;
    }
  }

  while(!Vazia(P2)){
    Desempilha(&P2, &y);
    Empilha(y, P1);
  }
  if(flag==1){
    return z;
  }
  else{
    z.codigo=-1;
    return z;
  }
}


void Libera(TPilha *Pilha){
  TProduto x;
  while(!Vazia(*Pilha)){
    Desempilha(Pilha, &x);
  }
  free(Pilha->topo);
}