
/* se ja existe biblioteca, existe o arquivo objeto o lista.h nao é compilado novamente */

#ifndef header_lista // macro inicial
#define header_lista //macro inicial

#include <stdlib.h>
#include <stdio.h>

//structs: TProduto, TCelula, TLista
//assinatura das funcoes: LerProduto, ImprimirProduto, FLVazia, Inserir, Pesquisar, Excluir, Imprimir


typedef struct {
  int codigo;
  //outros elementos
} TProduto;

typedef struct celula {
  TProduto item;
  struct celula *prox;
} TCelula;

typedef struct {
  TCelula *topo;
  TCelula *fundo;
  int tamanho;
} TPilha;

void LerProduto(TProduto *x);
void ImprimirProduto(TProduto x);
void FPVazia(TPilha *Pilha);
int Vazia(TPilha Pilha);
int Tamanho(TPilha Fila);
void Empilha(TProduto x, TPilha *Pilha);
void Desempilha(TPilha *Pilha, TProduto *Item);
void Imprimir1(TPilha *P1);
void Imprimir2(TPilha *P1);
void Libera(TPilha *Pilha);
TCelula *Pesquisar(TProduto Item, TPilha Pilha);



#endif //macro final