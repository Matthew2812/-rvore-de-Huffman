#ifndef NO_H
#define NO_H
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
  struct No* prox;
  struct No* esquerda;
  struct No* direita;
  int frequencia;
  char letra;
} No;

No* criaNo(int f, char l);

void imprimeNo(No *no);

int getFrequencia(No *no);

char getLetra(No *no);

void setEsquerda(No *raiz, No *no);

void setDireita(No* raiz, No *no);

#endif