#include "arvore.h"
#include "no.h"
#include "lista.h"
#include <stdbool.h>

Arvore* criaArvore() {
  Arvore *nova = malloc(sizeof(Arvore));
  return nova;
}

bool vazia(Arvore *arv) {
  return arv->raiz == NULL;
}

void imprimeArvore(No* no) {
  if(no != NULL) {
    imprimeNo(no);
    imprimeArvore(no->esquerda);
    imprimeArvore(no->direita);
  }
}

void criaHuffman(Arvore *arv, Lista *lista) {
  char letra = 'A';

  while(lista->cabeca->prox != NULL) {
    No* esq = removeInicio(lista);
    No* dir = removeInicio(lista);
    int f = getFrequencia(esq) + getFrequencia(dir);
    char l = letra;
    letra++;
    arv->raiz = criaNo(f, l);
    setEsquerda(arv->raiz, esq);
    setDireita(arv->raiz, dir);
    insereNo(lista, arv->raiz);
  }
}

bool pai(No *no) {
  if(no->esquerda == NULL)
    return false;
  else if(no->direita == NULL)
    return false;
  else if(no->esquerda->esquerda == NULL)
    return false;
  else if(no->direita->direita == NULL)
    return false;
  else
    return true;
}

void criaCodigos(No *no, int i, No* raiz, char *codigo, bool esq) {
  if(no != NULL) {
    if(esq && getFrequencia(no) != getFrequencia(raiz)) {
      codigo[i] = '0';
      i++;
    } else if(!esq && getFrequencia(no) != getFrequencia(raiz)){
      codigo[i] = '1';
      i++;
    }

    if (!pai(no)) {
      if(no->esquerda != NULL && getLetra(no->esquerda)-65 > 25) {
        imprimeNo(no->esquerda);
        printf(" Código: ");
        for(int j = 0; j < i; j++) {
          printf("%c", codigo[j]);
        }
        printf("%d", 0);
      }
      if(no->direita != NULL && getLetra(no->direita)-65 > 25) {
        imprimeNo(no->direita);
        printf(" Código: ");
        for(int j = 0; j < i; j++) {
          printf("%c", codigo[j]);
        }
        printf("%d", 1);
      }
    }

    if(getFrequencia(no) == getFrequencia(raiz->direita)){
      i = 0;
      codigo[i] = '1';
      i++;
    } 
    
    if(getFrequencia(no) == getFrequencia(raiz->esquerda)) {
      i = 0;
      codigo[i] = '0';
      i++;
    }

    criaCodigos(no->esquerda, i, raiz, codigo, true);
    criaCodigos(no->direita, i, raiz, codigo, false);
  }
}
/*            13
        5               8
    2     3         4       4
  1   1           2   2   2   2
                         1 1 1 1


*/