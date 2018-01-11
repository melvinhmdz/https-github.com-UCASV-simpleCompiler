#include <stdlib.h>
#include <stdio.h>
#include "parser.h"
#include "backend.h"
int value;
static void Gen_codigo_expresion(Expresion *expr) {
  switch(expr->tipo) {
    case 'D':
      printf("PUSH %d\n",expr->valor);
      break;
    case 'P':
      Gen_codigo_expresion(expr->izquierda);
      Gen_codigo_expresion(expr->derecha);
      switch (expr->oper) {
        case '+':
          printf("ADD\n");
          value = expr->izquierda->valor + expr->derecha->valor;
          break;
        case '*':
          printf("MULT\n");
          value = expr->izquierda->valor * expr->derecha->valor;
          break;
      }
      break;
  }
}


void Procesar(nodo_AST *codigoi){
  Gen_codigo_expresion(codigoi);
  printf("PRINT %d\n",value);
}
