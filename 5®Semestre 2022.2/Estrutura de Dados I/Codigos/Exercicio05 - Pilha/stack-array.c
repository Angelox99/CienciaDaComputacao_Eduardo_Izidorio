/* ----------------------------------------------------
* Resposta ao exercício: Exercício 05 - Pilha: Questão 1
* Autor(a): Eduardo Henrique de Almeida Izidorio
* Matrícula: 2020000315
------------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct pilha
{
    int topo;
    int tam;
    int *array;
} Pilha;

Pilha *criaPilha(int tam)
{
    Pilha *P = malloc(sizeof(Pilha));
    P->topo = -1;
    P->tam = tam;
    P->array = malloc(tam * sizeof(int));
    return P;
}

void push(Pilha *P, int val)
{
    P->topo = P->topo + 1;
    P->array[P->topo] = val;
}

int qtdElem(Pilha *P)
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
}

int pop(Pilha *P)
{
    int aux;
    if (P->topo == -1)
    {
        printf("Pilha Vazia!\n");
    }
    else
    {
        aux = P->array[P->topo];
        P->topo--;
        return aux;
    }
}

int peek(Pilha *P)
{
    if (P->topo == -1)
    {
        printf("Pilha Vazia!\n");
    }
    else
    {
        return P->array[P->topo];
    }
}

int main()
{
    Pilha *P = criaPilha(10);
    push(P, 35);
    push(P, 77);
    push(P, 21);
    push(P, 190);
    printPilha(P);
    pop(P);
    printf("\n");
    printPilha(P);

    printf("Topo: %d", peek(P));

    return 0;
}
