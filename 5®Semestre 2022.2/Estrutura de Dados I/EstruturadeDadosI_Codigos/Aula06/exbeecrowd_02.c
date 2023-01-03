/* -----------------------------------------------------------------------------
Exercício: Ex 03 Listas Encadeadas – Lista da Morte de Arya – beecrowd
Autor(a): Eduardo Henrique de Almeida Izidorio
Matrícula: 2020000315
-------------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  long long value;
  struct node *next;
} Node;

typedef struct linkedList {
  Node *begin;
  Node *end;
  long long size;
} LinkedList;

Node *create_node(long long value) {
  Node *newNode = malloc(sizeof(Node));
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}
//Criando a Lista encadeada
LinkedList *create_list() {
  LinkedList *newL = malloc(sizeof(LinkedList));
  newL->begin = NULL;
  newL->end = NULL;
  newL->size = 0;
  return newL;
}

int linkedList_isEmpty(LinkedList *L){
  return L->size == 0;
}

void insert_final_fast(LinkedList *L, long long value){
  Node *newNode = create_node(value);
  
  //1° Caso - Lista Vazia
  if(linkedList_isEmpty(L)){
    L->begin = newNode;
    L->end = newNode;
    L->size++;
  } else{ //2° Caso - Lista tem UM ou +1 elemento
    L->end->next = newNode;
    L->end = newNode;
  }
  L->size++;

}

void insert_middle(LinkedList *L, long long p, long long e){
  Node *newNode = create_node(p);
  Node *aux = L->begin;
  //1° Caso - Lista Vazia
  if(linkedList_isEmpty(L)){
    L->begin = newNode;
    L->end = newNode;
  } else{ //2° Caso - Lista tem UM ou +1 elemento
    while(aux != NULL){
      if(aux->value == e){
        newNode->next = aux->next;
        aux->next = newNode;
      }
      aux = aux->next;
    }
  }
  L->size++;
}

// R e (1 ≤ e ≤ 10^9): Remova o inimigo e da lista.
void LinkedList_remove(LinkedList *L, long long e) {
  Node *aux = L->begin;
  Node *prev;

  if (aux != NULL && aux->value == e) {
    L->begin = aux->next;
    L->size;
    free(aux);
    return;
  }

  while (aux != NULL && aux->value != e) {
    prev = aux;
    aux = aux->next;
  }
  
  if (aux == NULL) return;
  prev->next = aux->next;
  L->size;
  free(aux);
}

// Q a b (1 ≤ a, b ≤ 10^9): Determine quantos inimigos estão na lista entre a e b, excluindo ambos.
long long query_node(LinkedList *L, long long a, long long b) {
  long long count = 0;
  Node *auxA = L->begin;
  while(auxA->value != a){
    auxA = auxA->next;
  }

  Node *auxB = auxA->next;
  while(auxB->value != b){
    auxB = auxB->next;
    count++;
  }
  return count;
}

void print_List(LinkedList *L){
  if(!linkedList_isEmpty(L)){
    Node *aux = L->begin;    
    while(aux != NULL){
      printf("%lld->", aux->value);
      aux = aux->next;
    }
    printf("\nTAM: %lld", L->size);
  }
}

int main() {
  LinkedList *L = create_list();
  long long saida[50000];

  long long n;
  scanf("%lld", &n);
  while (n--) {
    long long ini;
    scanf("%lld", &ini);
    insert_final_fast(L, ini);
  }
  long long Q, tamSaida = 0, i;
  scanf("%lld", &Q);
  while (Q--) {
    char letra;
    long long p, e;

    scanf(" %c", &letra);

    if (letra == 'I') {
      scanf("%lld %lld", &p, &e);
      insert_middle(L, p, e);
    } else if (letra == 'R') {
      scanf("%lld", &e);
      LinkedList_remove(L, e);
    } else if (letra == 'Q') {
      scanf("%lld %lld", &p, &e);
      long long count = query_node(L, p, e);
      //printf("%lld\n", count);
      saida[tamSaida++] = count;
    }
  }
  i = 0;
  while(tamSaida--)printf("%lld\n", saida[i++]);
  //print_List(L);
  return 0;
}