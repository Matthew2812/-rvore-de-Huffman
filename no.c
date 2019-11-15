#include "no.h"

No* criaNo(int f, char l) {
  No *nova = malloc(sizeof(No));
  nova->frequencia = f;
  nova->letra = l;
  return nova;
}

void imprimeNo(No *no) {
  printf("Letra %c: %d", no->letra, no->frequencia);
}