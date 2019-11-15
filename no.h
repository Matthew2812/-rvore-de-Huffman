#ifndef NO_H
#define NO_H
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
  struct No* esq;
  struct No* dir;
  struct No* pai;
  int frequencia;
  char letra;
} No;

No* criaNo(int f, char l);

void imprimeNo(No *no);

#endif