#include "pilha.c"

int main(){
    TPilha P1;
    TProduto p;
    FPVazia(&F1);
    for(int i=0; i<5; i++){
    LerProduto(&p);
    Enfileirar(p, &P1);
    }
}