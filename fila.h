#ifndef FILA_H
#define FILA_H
#include "arvore.h"
#include <stdlib.h>

typedef struct Fila {
  Arvore *arvore;
  int tamanho;
  int quant;
} Fila;

Fila* criaFila(int t);

void imprimeFila(Fila *fila);

void insereFila(Fila *fila, Arvore *arv);

Arvore* removeFila(Fila *fila);

#endif