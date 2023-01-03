#include <stdio.h>
#include<stdlib.h>

typedef struct node {
  int value;
  struct node *next;
} Node;

typedef struct listLinked {
  Node *begin;
} ListLinked;

Node *create_node(int value) {
  Node *newNode = malloc(sizeof(Node));
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}

ListLinked *create_list() {
  ListLinked *newL = malloc(sizeof(ListLinked));
  newL->begin = NULL;
  return newL;
}

void insert_last_slow(ListLinked* L, int value){
    Node *newNode = create_node(value);
    //Caso 1: Lista esta vazia
    if(L->begin == NULL){
        L->begin == newNode;
    }
    else{//Caso 2: Lista nao esta vazia
    Node *aux = create_node(NULL);
    aux = L->begin;
    while (aux != NULL){
        aux = aux->next;
    }
    aux->next = newNode;
  }
}

void print_list()

int main() {
    ListLinked* L = create_list();
 
    return 0;
}