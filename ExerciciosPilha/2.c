#include "../Pilha/pilha.c"

void transfere(TPilha *p1, TPilha *p2){
    printf("\nPilha 1 - original\n");
    Imprimir1(p1);
    int t1, tam_inicial, repetir=0;
    TProduto aux;
    t1 = Tamanho(*p1)-1;
    tam_inicial=Tamanho(*p1);
    TProduto x;
    while(tam_inicial!=repetir){
        Desempilha(p1, &x);
        aux = x;
        for(int i=0; i<t1; i++){
            Desempilha(p1, &x);
            Empilha(x, p2);
        }
        Empilha(aux, p1);
        while(!Vazia(*p2)){
            Desempilha(p2, &x);
            Empilha(x, p1);
        }
        t1--;
        repetir++;
    }
    printf("\nPilha 1 - invertida\n");
    Imprimir1(p1);
    while(!Vazia(*p1)){
        Desempilha(p1, &x);
        Empilha(x, p2);
    }
    printf("\nPilha 2 - transferencia\n");
    Imprimir1(p2);
}


int main(){
    TPilha p1; 
    TPilha p2;
    TProduto x;
    FPVazia(&p1);
    FPVazia(&p2);
    for(int i=0; i<5; i++){
    LerProduto(&x);
    Empilha(x, &p1);
    }
    transfere(&p1, &p2);
}