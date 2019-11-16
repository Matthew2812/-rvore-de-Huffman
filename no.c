#include "no.h"

No* criaNo(int f, char l) {
  No *nova = malloc(sizeof(No));
  nova->frequencia = f;
  nova->letra = l;
  return nova;
}

void imprimeNo(No *no) {
  printf("\nLetra %c: %d", getLetra(no), getFrequencia(no));
}

int getFrequencia(No *no) {
  return no->frequencia;
}

char getLetra(No *no) {
  return no->letra;
}

void setEsquerda(No *raiz, No *no) {
  raiz->esquerda = no;
}

void setDireita(No *raiz, No *no) {
  raiz->direita = no;
}