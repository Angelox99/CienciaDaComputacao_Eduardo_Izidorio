/**
 * Discente: Eduardo Henrique de Almeida Izidorio
 * Matrícula: 2020000315
 * Exercício 04 – Lista Duplamente Encadeada e Lista Circular
 * 
 * Questão 5) Escreva uma função que concatena duas listas encadeadas (isto é, "amarra" a segunda no
 * fim da primeira).
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
// concatenar duas listas
void ConcatenacaoLista(DoublyNode **p0, DoublyNode **p1)
{
  DoublyNode *p3 = NULL; // Nó auxiliar
  if (p0 == NULL && p1 == NULL)
  {
    printf("\nERRO");
  }
  else
  {
    p3 = (DoublyNode *)malloc(sizeof(DoublyNode));

    if (p3 == NULL)
    {
      printf("\nERRO");
    }
    else
    {
      p3 = *p0;

      while (p3->next != NULL)
      {
        p3 = p3->next;
      }

      p3->next = (*p1);
      (*p1)->prev = p3;
    }
  }
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

// Questão 04) -- Teste
int main() {
  int vet[] = {4, 8, 15, 16, 23, 42};
  int size = sizeof(vet) / sizeof(vet[0]);

  ListaDupLigada *L = List_create();
  int i = 0;
  while (size--) {
    List_add_last(L, vet[i++]);
  }

  List_print(L);

  return 0;
}