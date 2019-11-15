#ifndef ARVORE_H
#define ARVORE_H
#include <stdlib.h>
#include "no.h"

typedef struct Arvore {
  No* raiz;
} Arvore;

Arvore* criaArvore();

#endif