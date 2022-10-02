#include <stdio.h>
#include <stdlib.h>
#include "interface.h"


void MSG_MENU( )
{
    system("clear");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. EMPILHAR");
    printf("  \n\t2. PESQUISAR");
    printf("  \n\t3. DESEMPILHAR");
    printf("  \n\t4. IMPRIMIR");
    printf("  \n\t5. SAIR");
}

void MENU(TPilha *Pilha){
    TProduto x;
    TProduto valor;
   
    int opcao=0;
    do
    {
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
                    LerProduto(&x);
                    Empilha(x, Pilha);
                system("PAUSE");
                break;
            case 2:
                 printf("\nDigite o codigo do produto desejado:");
                 scanf("%d", &valor.codigo);
                 if ((Pesquisar(valor, *Pilha) != NULL)) {
                    printf("\nItem pesquisado com sucesso\n");
                    printf("\n#############################\n");
                    ImprimirProduto((Pesquisar(valor, *Pilha))->prox->item);
                    } else {
                        printf("\nItem nao encontrado\n");
                    }
                system("PAUSE");
                break;
            case 3:
                 Desempilha(Pilha, &valor);
                 printf("\nProduto desempilhado:\n");
                 ImprimirProduto(valor);
                system("PAUSE");
                break;
            case 4:
                Imprimir1(Pilha);
                system("PAUSE");
                break;
            case 5:
                system("clear");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<");
                system("PAUSE");
                break;
            default:
                system("clear");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
                Libera(Pilha);
                system("PAUSE");
            } // fim do bloco switch
    } while(opcao != 5);
}
