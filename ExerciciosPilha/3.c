#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Pilha/pilha.c"


void ValidaExpressao(char *expressao, TPilha *P1){
	TProduto x;
	for (int i = 0; expressao[i] != '\0'; i++){
		if (expressao[i] == '(' || expressao[i] == '[' || expressao[i] == '{'){
			x.codigo = expressao[i];
			Empilha(x, TPilha);
		}else if (expressao[i] == ')'){
			if (P1->topo->prox->item.codigo == '('){
				Desempilha(P1, &x);
			}else{
				printf("Incompleta\n");
				return;
			}
		}else if (expressao[i] == ']'){
			if (P1->topo->prox->item.codigo == '['){
				Desempilha(P1, &x);
			}else{
				printf("Incompleta\n");
				return;
			}
		}else if (expressao[i] == '}'){
			if (P1->topo->prox->item.codigo == '{'){
				Desempilha(P1, &x);
			}else{
				printf("Incompleta\n");
				return;
			}
		}
	}
    if(Vazia(*P1))
		printf("Expressao esta correta\n");
	else
		printf("Expressao esta incorreta\n");	
}