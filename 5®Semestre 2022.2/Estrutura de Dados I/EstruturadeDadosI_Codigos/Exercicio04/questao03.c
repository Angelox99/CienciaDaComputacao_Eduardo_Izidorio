/**
 * Discente: Eduardo Henrique de Almeida Izidorio
 * Matrícula: 2020000315
 * Exercício 04 – Lista Duplamente Encadeada e Lista Circular
 *
 * Questão 3) Escreva uma função recursiva que remova de uma lista
 * encadeada simples uma célula cujo conteúdo é mínimo. Documente sua
 * função.
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// ----- ESTRUTURA DE DADOS - TAD NODE E TAD LISTA
typedef struct node {
  int val;
  struct node *prev;
  struct node *next;
} NodeDuplo;

typedef struct listaDupLigada {
  NodeDuplo *begin;
  NodeDuplo *end;
  int size;
} ListaDupLigada;

ListaDupLigada *L;

// ----- CONSTRUTORES
NodeDuplo *Node_create(int val) {
  NodeDuplo *newNode = malloc(sizeof(NodeDuplo));
  newNode->prev = NULL;
  newNode->next = NULL;
  newNode->val = val;
  return newNode;
}
ListaDupLigada *List_create() {
  ListaDupLigada *L = malloc(sizeof(ListaDupLigada));
  L->begin = NULL;
  L->end = NULL;
  L->size = 0;
  return L;
}

// Lista Global por questão de praticidade
ListaDupLigada *L;

// ----- Funções Utilitárias
bool List_is_empty(ListaDupLigada *L) { return L->size == 0; }

void List_print(ListaDupLigada *L) {
  NodeDuplo *aux = L->begin;
  printf("L -> ");
  while (aux != NULL) {
    printf("%d -> ", aux->val);
    aux = aux->next;
  }
  printf("NULL\n");
}

NodeDuplo *buscaRec(NodeDuplo *atual, int x) {
  if (atual == NULL) return NULL;
  if (atual->val == x) return atual;
  buscaRec(atual->next, x);
}

// buscaMinRec(L->begin,L->begin)
NodeDuplo *buscaMinRec(NodeDuplo *min, NodeDuplo *atual) {
  if (atual == NULL) {
    return min;
  }
  if (atual->val < min->val) {
    return buscaMinRec(atual, atual->next);
  }
  buscaMinRec(min, atual->next);
}

NodeDuplo buscaMinRecRemove(NodeDuplo *min, NodeDuplo *atual) {
  if (atual == NULL) {
    NodeDuplo aux = *min;
    // Remover o minimo da lista
    if (min->prev == NULL) {  // primeiro
      min->next->prev = NULL;
      L->begin = min->next;
    } if (min->next == NULL) {  // ultimo
      min->prev->next = NULL;
      L->end = min->prev;
    } else {  // meio
      min->prev->next = min->next;
      min->next->prev = min->prev;
    }
    free(min);
    return aux;
  }
  if (atual->val < min->val) {
    return buscaMinRecRemove(atual, atual->next);
  }
  return buscaMinRecRemove(min, atual->next);
}

// ----- Funções de ADIÇÃO
void List_add_last(ListaDupLigada *L, int val) {
  NodeDuplo *newNode = Node_create(val);
  newNode->prev = L->end;

  if (List_is_empty(L)) {
    L->begin = newNode;
  } else {
    L->end->next = newNode;
  }

  L->end = newNode;
  L->size++;
}

int main() {
  L = List_create();

  List_add_last(L, 10);
  List_add_last(L, 14);
  List_add_last(L, 2);
  List_add_last(L, 28);
  List_add_last(L, 56);
  List_add_last(L, 766);

  List_print(L);

  // printf("%s\n", (buscaRec(L->begin, 56) && 1 == 1) ? "Achou!" : "Não
  // achou!!");
  // printf("min: %d\n", buscaMinRec(L->begin, L->begin->next)->val);
  printf("min removido: %d\n", buscaMinRecRemove(L->begin, L->begin).val);

  List_print(L);

  return 0;
}