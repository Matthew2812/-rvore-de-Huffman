#ifndef ARVORE_H
#define ARVORE_H
#include <stdlib.h>
#include <stdbool.h>
#include "no.h"
#include "lista.h"

typedef struct Arvore {
  No* raiz;
} Arvore;

Arvore* criaArvore();

bool vazia(Arvore *arv);

void imprimeArvore(No *no);

bool pai(No *no);

void criaHuffman(Arvore *arv, Lista *lista);

void criaCodigos(No *no, int i, No* raiz, char *codigo, bool esq);

#endif