#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../Pilha/pilha.c"


void Soma(int *n1, int t1, int *n2, int t2){
	int i, resultado = 0;
	TPilha P1, P2, PSOMA;
	FPVazia(&P1);
    FPVazia(&P2);
    FPVazia(&PSOMA);
	TProduto item1, item2, item3;
	for (i = 0; i < t1; i++){
		item1.codigo = n1[i];
		Empilha(item1, &P1);
	}
	for (i = 0; i < t2; i++){
		item2.codigo = n2[i];
		Empilha(item2, &P2);
	}
	while (!Vazia(P1) && !Vazia(P2)){
		Desempilha(&P1, &item1);
        Desempilha(&P2, &item2);
		resultado = resultado + item1.codigo + item2.codigo;
		if (resultado < 9){
			item1.codigo = resultado;
			Empilha(item1, &PSOMA);
			resultado = 0;
		}else{
			item1.codigo = resultado % 10;
			Empilha(item1, &PSOMA);
			resultado = 1;
		}
	}
    //CORRECAO QUANDO TAMANHO DE UM EH MAIOR QUE OUTRO
	while (!Vazia(P1)){
		Desempilha(&P1, &item1);
		resultado = resultado + item1.codigo;
		item1.codigo = resultado;
		Empilha(item1, &PSOMA);
		resultado = 0;
	}
	while (!Vazia(P2)){
		Desempilha(&P2, &item2);
		resultado = resultado + item2.codigo;
		item2.codigo = resultado;
		Empilha(item2, &PSOMA);
		resultado = 0;
	}
    
	resultado = 0;
	int maximo = Tamanho(PSOMA)-1;
	while (!Vazia(PSOMA)){
		Desempilha(&PSOMA, &item3);
		resultado = resultado + (item3.codigo * pow(10, maximo));
		maximo--;
	}
    
	printf("Resultado: %d", resultado);
	Libera(&P1);
    Libera(&P2);
    Libera(&PSOMA);
}

int main(){
    int t1=3;
    int t2=4;
    int n1[3]={5, 9, 2};
    int n2[4]={3,7,8,4};
    Soma(n1,t1,n2,t2);
}