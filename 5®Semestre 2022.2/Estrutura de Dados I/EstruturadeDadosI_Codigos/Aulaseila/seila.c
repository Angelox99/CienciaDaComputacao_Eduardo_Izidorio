#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int conteudo;
    struct Node *prox;
} Node;

void imprimaLista (Node *iniCC)
{
   Node *p;
   for (p = iniCC->prox; p != NULL; p = p->prox) 
      printf ("%d\n", p->conteudo);
}

Node *buscaLista (int x, Node *iniCC)
{
   Node *p;
   p = iniCC->prox;
   while (p != NULL && p->conteudo != x) 
      p = p->prox; 
   return p; 
}

int main() {
    //Instanciação da "cabeça da lista"
    Node* iniCC = malloc(sizeof(Node));
    iniCC->prox = NULL; 
    
    //Instanciação da "Sem cabeça"
    Node* iniSC = malloc(sizeof(Node));
    iniSC = NULL;

    //Lista com Cabeça
    Node* nodeA = malloc(sizeof(Node));
    nodeA->conteudo = 30;
    Node* nodeB = malloc(sizeof(Node));
    nodeB->conteudo = 66;
    Node* nodeC = malloc(sizeof(Node));
    nodeC->conteudo = 12;

    iniCC->prox = nodeB;
    nodeB->prox = nodeC;
    nodeC->prox = nodeA;
    nodeA->prox = NULL;

    imprimaLista(iniCC);
    if(buscaLista(12, iniCC)) 
    printf("existe\n");
    else printf("Não existe\n");

    return 0;
}