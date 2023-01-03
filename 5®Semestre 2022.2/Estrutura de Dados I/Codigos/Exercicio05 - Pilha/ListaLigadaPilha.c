/* ----------------------------------------------------
* Resposta ao exercício: Exercício 05 - Pilha: Questão 2
* Autor(a): Eduardo Henrique de Almeida Izidorio
* Matrícula: 2020000315
------------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no
{
  int valor;
  struct no *ant;
  struct no *prox;
} No;

typedef struct lista
{
  No *ini;
  No *fim;
  int tam;
} Lista;

No *CriarNo(int valor)
{
  No *newNode = malloc(sizeof(No));
  newNode->ant = NULL;
  newNode->prox = NULL;
  newNode->valor = valor;

  return newNode;
}

Lista *CriarLista()
{
  Lista *L = malloc(sizeof(Lista));
  L->ini = NULL;
  L->fim = NULL;
  L->tam = 0;

  return L;
}

void ApagarLista(Lista **L_ref)
{
  Lista *L = *L_ref;

  No *p = L->ini;
  No *aux = NULL;

  while (p != NULL)
  {
    aux = p;
    p = p->prox;
    free(aux);
  }
  free(L);

  *L_ref = NULL;
}

bool ListaVazia(Lista *L) { return L->tam == 0; }

void InserirLista(Lista *L, int valor)
{
  No *p = CriarNo(valor);
  p->ant = L->fim;

  if (ListaVazia(L))
  {
    L->ini = p;
  }
  else
  {
    L->fim->prox = p;
  }

  L->fim = p;
  L->tam++;
}

// imprime lista
void ImprimeLista(Lista *L)
{
  No *p = L->ini;

  printf("L -> ");

  while (p != NULL)
  {
    printf("%d -> ", p->valor);
    p = p->prox;
  }
  printf("NULL\n");

  if (L->fim == NULL)
  {
    printf("L->end = NULL\n");
  }
  else
  {
    printf("L->end = %d\n", L->fim->valor);
  }

  printf("Size: %d\n", L->tam);
  puts("");
}

// remove da lista
int RemovedaLista(Lista *L)
{
  if (!ListaVazia(L))
  {
    No *fim = L->fim;

    No *aux = fim->ant;
    L->fim = aux;
    aux->prox = NULL;
    L->tam--;

    return fim->valor;
    free(fim);
  }
}

typedef struct pilha
{
  int tam;
  int topo;
  int *array;
} Pilha;

// CRIAÇÃO DA PILHA
Pilha *criaPilha(int tam)
{
  Pilha *P = malloc(sizeof(Pilha));
  P->topo = -1;
  P->tam = tam;
  P->array = malloc(tam * sizeof(int));
  return P;
}

void push(Pilha *P, int val, Lista *L)
{
  InserirLista(L, val);
  P->topo = P->topo + 1;
  P->array[P->topo] = val;
}

int qtdElementos(Pilha *P)
{
  return P->topo + 1;
}

int printPilha(Pilha *P)
{
  if (P->topo == -1)
  {
    printf("Pilha Vazia\n");
  }
  else
  {
    for (int i = P->topo; i > -1; i--)
    {
      printf("%d\n", P->array[i]);
    }
  }
  printf("\n");
}

int pop(Pilha *P, Lista *L)
{
  int val;
  val = RemovedaLista(L);
  P->topo--;
  return val;
}

int peek(Pilha *P)
{
  int val;
  val = P->array[P->topo];
  return val;
}

int main()
{
  Lista *L = CriarLista();

  Pilha *P = criaPilha(10);
  push(P, 30, L);
  push(P, 51, L);
  push(P, 67, L);
  push(P, 12, L);
  printPilha(P);
  ImprimeLista(L);
  printf("");

  int valorRetirado = pop(P, L);
  printf("POP: %d\n", valorRetirado);
  printPilha(P);
  ImprimeLista(L);
  printf("");

  int valorPeekeado = peek(P);
  printf("PEEK: %d\n", valorPeekeado);
  printPilha(P);
  ImprimeLista(L);
  printf("");

  return 0;
}