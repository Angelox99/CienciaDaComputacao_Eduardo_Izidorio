/* --------------------------------------------------------
* Exercício: – Questão 06
* Autor: Eduardo Henrique de Almeida Izidorio
* Matrícula: 2020000315
----------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//   ->   STRUCTS 

typedef struct node {
  char name[25];
  struct node *next;
  struct node *before;
} Node;

typedef struct linkedlist {
  Node *begin;
  Node *end;
} LinkedList;

//   ->  FUNÇÕES BÁSICAS DE STRUCTS 

Node *create_node(char *name) {
  Node *newNode = malloc(sizeof(Node));
  newNode->before = NULL;
  strcpy(newNode->name, name);
  newNode->next = NULL;
  return newNode;
}

LinkedList *create_list() {
  LinkedList *newL = malloc(sizeof(LinkedList));
  newL->begin = NULL;
  newL->end = NULL;
  return newL;
}

//    ->  FUNÇÕES DE OPERÇÕES 

void insert_node_extremities(LinkedList *L, char *name, char where){

  Node *inserted_node = create_node(name);

  if(L->begin == NULL){

    L->begin = inserted_node;
    L->end = inserted_node;

    inserted_node->next = inserted_node;
    inserted_node->before = inserted_node;

  }else{
    if(where == 'e'){
      inserted_node->before = L->end;
      L->end->next = inserted_node;
      inserted_node->next = L->begin;
      L->begin->before = inserted_node;

      L->end = inserted_node;
    }else if(where == 'b'){
      inserted_node->next = L->begin;
      L->begin->before = inserted_node;
      inserted_node->before = L->end;
      L->end->next = inserted_node;

      L->begin = inserted_node;
    }
  }
}

void insert_node_any(LinkedList *L, Node *node, char *name, char where){

  Node *inserted_node = create_node(name);

  if(L->begin == NULL){

    L->begin = inserted_node;
    L->end = inserted_node;

    inserted_node->next = inserted_node;
    inserted_node->before = inserted_node;

  }else{

    if(where == 'n'){
      if(node == L->end){
        L->end = inserted_node;
      }

      Node *old_next = node->next;
      node->next=inserted_node;
      inserted_node->before = node;
      inserted_node->next = old_next;

    }else if(where == 'b'){
      if(node == L->begin){
        L->begin = inserted_node;
      }

      Node *old_before = node->before;
      node->before=inserted_node;
      inserted_node->next = node;
      inserted_node->before = old_before;

    }

  }

}

void remove_node(LinkedList *L, Node *node){

  Node *before_node = node->before;
  Node *next_node = node->next;

  //   ->   Remove o valor da lista dependendo se ele estiver no começo, final ou meio da lista encadeada
  
  if(node == L->begin){
    L->begin = node->next;
  }
  if(node == L->end){
    L->end = node->before;
  }

  before_node->next = next_node;
  next_node->before = before_node;
}

void hat_remove(LinkedList *L, char *name, int n){
    Node *p = L->begin;
    while(strcmp(p->name, name)){
        p = p->next;
    };
    
    for(int i = 1; i<n; i++){
        p = p->before;
    }

    remove_node(L, p);
}

//   ->  FUNÇÕES DE DEBUG 

void print_list(LinkedList *L){
    if(L->begin != NULL){
        Node *p = L->begin;
        do{
            printf("%s\n", p->name);
            p = p->next;
        }while(p != L->begin);
    }
}

//   ->  MAIN 

int main() {

  LinkedList *L = create_list();

  insert_node_extremities(L, "edu", 'e');
  insert_node_extremities(L, "gabys", 'e');
  insert_node_extremities(L, "gaba", 'e');
  insert_node_extremities(L, "Shelly", 'e');
  insert_node_extremities(L, "maria", 'e');
  insert_node_extremities(L, "serjao", 'e');
  insert_node_extremities(L, "linda", 'e');

  print_list(L);

  hat_remove(L, "edu", 2);
  hat_remove(L, "Gaba", 6);
  hat_remove(L, "gabys", 4);
  hat_remove(L, "Shelly", 3);
  hat_remove(L, "maria", 1);
  hat_remove(L, "linda", 5);
  hat_remove(L, "serjao", 10);

  printf("\n\n");

  print_list(L);

  return 0;

}