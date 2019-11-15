#include "fila.h"

Fila* criaFila(int tam){
  Fila *nova = malloc(tam*sizeof(Fila));
  nova->tamanho = tam;
  nova->quant = 0;
  return nova;
}

void imprimeFila(Fila *fila) {
  for(int i = 0; i < fila->quant; i++) {
    imprimeNo(fila[i].arvore->raiz);
    printf("\n");
  }
}

void insereFila(Fila *fila, Arvore *arv) {
  fila[fila->quant].arvore = arv;
  fila->quant++;
}

//Ta cagado, tem que arrumar
Arvore* removeFila(Fila *fila) {
  Arvore *aux = fila[fila->quant-1].arvore;
  for(int i = fila->quant-1; i >= 1; i--) {
    fila[i-1].arvore = fila[i].arvore;
  }
  fila->quant--;
  return aux;
}