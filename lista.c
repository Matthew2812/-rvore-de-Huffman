#include "lista.h"
#include <stdbool.h>

Lista* criaLista() {
  Lista *nova = malloc(sizeof(Lista));
  return nova;
}

bool listaVazia(Lista *lista) {
  return lista->cabeca == NULL;
}

void imprimeLista(Lista *lista) {
  if(!listaVazia(lista)) {
    No *i = lista->cabeca;
    while(i != NULL) {
      imprimeNo(i);
      i = i->prox;
    }
  }
}

void insereNo(Lista *lista, No *no) {
  if(listaVazia(lista)) {
    lista->cabeca = no;

  } else if(getFrequencia(lista->cabeca) > getFrequencia(no)) {
    No* aux = lista->cabeca;
    lista->cabeca = no;
    lista->cabeca->prox = aux;
  
  } else if(lista->cabeca->prox == NULL) {
    if(no->frequencia >= lista->cabeca->frequencia) {
      lista->cabeca->prox = no;
    } else {
      No* aux = lista->cabeca;
      lista->cabeca = no;
      lista->cabeca->prox = aux;
    }

  } else {
    No *i = lista->cabeca->prox;
    No *j = lista->cabeca;
    while(i != NULL) {
      if(getFrequencia(i) > getFrequencia(no)) {
        j->prox = no;
        no->prox = i;
        return;
      }
      i = i->prox;
      j = j->prox;
    }

    j->prox = no;
  }
}

No* removeInicio(Lista *lista) {
  No *aux = lista->cabeca;
  lista->cabeca = lista->cabeca->prox;
  return aux;
}