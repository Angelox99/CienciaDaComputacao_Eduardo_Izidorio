/* --------------------------------------------------------
* Exercício:  Questão 01
* Autor: Eduardo Henrique de Almeida Izidorio
* Matrícula: 2020000315
----------------------------------------------------------*/

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

NodeDuplo *retornaMeioDaLista(ListaDupLigada *L) {
  NodeDuplo *auxInicio = L->begin;
  NodeDuplo *auxFim = L->end;
  while (auxInicio != auxFim) {
    if (auxInicio->next == auxFim && auxFim->prev == auxInicio) break;
    auxInicio = auxInicio->next;
    auxFim = auxFim->prev;
  }
  // AQUI!!!
  return auxInicio;
}

int main() {
  ListaDupLigada *Limpar = List_create();

  List_add_last(Limpar, 12);
  List_add_last(Limpar, 17);
  List_add_last(Limpar, 22);
  List_add_last(Limpar, 13);
  List_add_last(Limpar, 56);

  List_print(Limpar);

  printf("Meio: %d\n", retornaMeioDaLista(Limpar)->val);

  ////// --------------------

  ListaDupLigada *Lpar = List_create();

  List_add_last(Lpar, 10);
  List_add_last(Lpar, 74);
  List_add_last(Lpar, 2);
  List_add_last(Lpar, 25);
  List_add_last(Lpar, 58);
  List_add_last(Lpar, 766);
  List_print(Lpar);

  printf("Meio: %d\n", retornaMeioDaLista(Lpar)->val);

  return 0;
}