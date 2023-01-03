#include <stdio.h>
#include <stdlib.h>
// #define TAM 10

typedef struct pilha
{
    int tam;
    int top;
    int *array;
} Pilha;

Pilha *criaPilha(int tam)
{
    Pilha *P = malloc(sizeof(Pilha));
    P->top = -1;
    P->tam = tam;
    P->array = malloc(tam * sizeof(int));
    return P;
}

void push(Pilha *P, int val)
{
    P->top = P->top + 1;
    P->array[P->top] = val;
}

void pop(Pilha *p, int aux)
{
    aux = p->array[p->top];
    p->top = p->top - 1;
}

int qtdElementos(Pilha *P)
{
    return P->top + 1;
}

int printPilha(Pilha *P)
{
    if (P->top == -1)
    {
        printf("Pilha Vazia\n");
    }
    else
    {
        for (int i = P->top; i > -1; i--)
        {
            printf("%d\n", P->array[i]);
        }
    }
}

int peek(Pilha *P)
{
    if ()
}

int main()
{
    Pilha *P = criaPilha(10);
    push(P, 30);
    push(P, 51);
    push(P, 67);
    push(P, 12);
    printPilha(P);
    puts("");
    pop(P, 12);
    // pop(P, 67);
    // pop(P, 51);
    // pop(P, 30);
    printPilha(P);

    return 0;
}