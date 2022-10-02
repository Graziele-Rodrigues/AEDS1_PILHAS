#include <stdio.h>
#include <stdlib.h>
#include "pilha.c"
#include "interface.c"

//include "interface.h" é o correto a se incluir, mas por estar no vscode coloca o .c no main


int main() {
  TPilha P1;
  FPVazia(&P1);
  MENU(&P1);
  return 0;
}