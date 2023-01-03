/* --------------------------------------------------------
* Exercício: – Questão 07
* Autor: Eduardo Henrique de Almeida Izidorio
* Matrícula: 2020000315
----------------------------------------------------------*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct node {
  char name[25];
  char registration[25];
  char gender[1];
  struct node *next;
  struct node *before;
} Node;

typedef struct linkedlist {
  Node *begin;
  Node *end;
  int size;
} LinkedList;



Node *create_node(char *name, char *registration, char *gender) {
  Node *newNode = malloc(sizeof(Node));
  newNode->before = NULL;
  strcpy(newNode->name, name);
  strcpy(newNode->registration, registration);
  strcpy(newNode->gender, gender);
  newNode->next = NULL;
  return newNode;
}

LinkedList *create_list() {
  LinkedList *newL = malloc(sizeof(LinkedList));
  newL->begin = NULL;
  newL->end = NULL;
  newL->size = 0;
  return newL;
}



void insert_node_extremities(LinkedList *L, char *name, char *registration, char *gender, char where){

  Node *inserted_node = create_node(name, registration, gender);

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

  L->size += 1;

}

void read_students_list(char array_students[250][100]) {
  FILE *file;
  file = fopen("listagem_alunos.txt", "r");

  int line = 0;
  while (!feof(file) && !ferror(file)){
      if (fgets(array_students[line], 100, file) != NULL){
          line++;
      }
  }
  fclose(file);
}

void get_paramns(char array_students[250][100], char array_params[750][100]){

  for (int i=0; i<250; i++){
    if(array_students[i]){
      int k = 0;
      int f = 0;
      for(int j=0; j<strlen(array_students[i]); j++){
        if(array_students[i][j] != ' ' && array_students[i][j] != '\n'){
          if(f == 2 && k == 1){ break; }
          array_params[(i*3)+f][k] = array_students[i][j];
        }else{
          f++;
          k = -1;
        }
        k++;
      }
    }
  }

}

int count_repeated_names(LinkedList *L){
  char all_names[L->size][25];
  char repeated_names[L->size][25];
  Node *p = L->begin;
  
  for(int i=0; i < L->size; i++){
    int already_in = 0;
    for(int j=0; j < i; j++){
      if(strcmp(p->name, all_names[j]) == 0){ 
        already_in++;
        strcpy(repeated_names[i], p->name);
        strcpy(repeated_names[j], p->name);
      }
    }
    if(already_in == 0){
      strcpy(all_names[i], p->name);
    }
    p = p->next;
  }

  int repeated = 0;
  for(int i=0; i < L->size; i++){
    if(strcmp(repeated_names[i], "") != 0){
      printf("%s\n", repeated_names[i]);
      repeated+=1;
    }
  }
  
  return repeated;
}

void remove_node(LinkedList *L, Node *node){

  Node *before_node = node->before;
  Node *next_node = node->next;

  //  - > Remove o valor da lista dependendo se ele estiver no começo, final ou meio da lista encadeada
  
  if(node == L->begin){
    L->begin = node->next;
  }
  if(node == L->end){
    L->end = node->before;
  }

  before_node->next = next_node;
  next_node->before = before_node;
}

//  - > FUNÇÕES DE DEBUG 

void print_list(LinkedList *L){
  if(L->begin != NULL){
    Node *p = L->begin;
    
    printf("[ ");
    do{
      if(p != L->end){
        printf("%s %s %s, ", p->registration, p->name, p->gender);
      }else{
        printf("%s %s %s ", p->registration, p->name, p->gender);
      }
      p = p->next;
    }while(p != L->begin);
    printf("]\n");
    printf("Size: %d, NomesRepetidos: %d", L->size, count_repeated_names(L));
  }
}

//  - >  MAIN

int main() {

  char array_students[250][100];
  char array_params[750][100];
  read_students_list(array_students);
  get_paramns(array_students, array_params);

  LinkedList *M = create_list();
  LinkedList *F = create_list();
  
  for (int i=2; i<750; i+=3){
    if(strcmp(array_params[i],"M") == 0){
      insert_node_extremities(M, array_params[i-1], array_params[i-2], "M", 'e');
    }else if(strcmp(array_params[i],"F") == 0){
      insert_node_extremities(F, array_params[i-1], array_params[i-2], "F", 'e');
    }
  }

  // print_list(M);
  printf("\n\n");
  print_list(F);


  return 0;

}
