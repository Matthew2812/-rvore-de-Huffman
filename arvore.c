#include "arvore.h"

Arvore* criaArvore(No *no) {
  Arvore *nova = malloc(sizeof(Arvore));
  nova->raiz = no;
  return nova;
}