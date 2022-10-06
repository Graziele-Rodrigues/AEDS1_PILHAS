#include "../Pilha/pilha.c"


void inverte1(TPilha *p1, TPilha *p2, TPilha *p3){
    TProduto x;
    printf("\nPilha - original\n");
    Imprimir1(p1);
    while(!Vazia(*p1)){
        Desempilha(p1, &x);
        Empilha(x, p2);
    }
    while(!Vazia(*p2)){
        Desempilha(p2, &x);
        Empilha(x, p3);
    }
    while(!Vazia(*p3)){
        Desempilha(p3, &x);
        Empilha(x, p1);
    }
    printf("\nPilha - invertida\n");
    Imprimir1(p1);
}

/*
void inverte2(TPilha *p1, TFila *f1){
    while(!Vazia(*p1)){
        Desempilha(p1, &x);
        Enfilerar(x, f1);
    }
    while(!Vazia(*f1)){
        Desenfilerar(f1, &x);
        Empilha(x, p1);
    }
    Imprimir1(p1);
}*/


void inverte3(TPilha *p1, TPilha *p2){
    printf("\nPilha - original\n");
    Imprimir1(p1);
    int t1, tam_inicial, repetir=0;
    TProduto aux;
    tam_inicial=Tamanho(*p1);
    t1 = tam_inicial-1;
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
    printf("\nPilha - invertida\n");
    Imprimir1(p1);
}


int main(){
    TPilha p1; 
    TPilha p2;
    TPilha p3;
    TProduto x;
    FPVazia(&p1);
    FPVazia(&p2);
    FPVazia(&p3);
    for(int i=0; i<4; i++){
    LerProduto(&x);
    Empilha(x, &p1);
    }
    inverte3(&p1, &p2);
    //inverte1(&p1, &p2, &p3);
}