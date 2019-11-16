/* Arvore de Huffman  
Nome: Joao Pedro Colafati Pedroso         TIA: 31819656
Nome: Matheus Soares Santos               TIA: 31895263
Nome: Wanderson Bezerra de Lima           TIA: 31895591
*/
#include "arvore.h"
#include "lista.h"
#include <stdio.h>
#define ASCII 97
#define TAM 1000

int contaLetras(char *letras) {
  int cont = 0;
  for(int i = 0; i < 26; i++) {
    if(letras[i] > 0)
      cont++;
  }
  return cont;
}

int main() {
  char letras[26] = {0};
  char texto[TAM];

  printf("\nType some thing:");
  fgets(texto, TAM, stdin);
  printf("\nText: %s", texto);

  for(int i = 0; texto[i] != 0; i++) {
    if(texto[i] != ' ')
      letras[texto[i] - 97]++;
  }

  int quant = contaLetras(letras);
  printf("\nQuantidade de letras no texto: %d\n", quant);

  for(char t = 'A'; t <= 'Z'; t++) {
    printf("%c ", t);
  }

  Lista *lista = criaLista();

  printf("\n");

  for(int j = 0; j < 26; j++) {
    printf("%d ", letras[j]);
    if(letras[j] > 0) {
      int f = letras[j];
      char l = 97 + j;
      No *novo = criaNo(f, l);
      insereNo(lista, novo);
    }
  }

  printf("\n\nLista");
  imprimeLista(lista);

  Arvore *arv = criaArvore();
  criaHuffman(arv, lista);
  printf("\n\nArvore pre-ordem");
  imprimeArvore(arv->raiz);
  printf("\n");

  char codigo[arv->raiz->letra-66];
  criaCodigos(arv->raiz, 0, arv->raiz, codigo, true);
  printf("\n");
  return 0;
}