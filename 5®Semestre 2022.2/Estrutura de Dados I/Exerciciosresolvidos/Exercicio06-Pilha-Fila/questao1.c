/* --------------------------------------------------------
* Exercício:  Questão 01
* Autor: Eduardo Henrique de Almeida Izidorio
* Matrícula: 2020000315
----------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

/* Estrutura do Nó */
typedef struct no
{
    char caracter;
    struct no *proximo;
} No;

/* Operação de empilhar */
No *push(No *pilha, char valor)
{
    No *novo = malloc(sizeof(No));

    if (novo != NULL)
    {
        novo->caracter = valor;
        novo->proximo = pilha;
        return novo;
    }
    else
    {
        printf("\tErro ao alocar memoria!\n");
    }
}

/* Operação de desempilhar */
No *pop(No **pilha)
{
    No *remover = NULL;

    if (*pilha)
    {
        remover = *pilha;
        *pilha = remover->proximo;
    }
    else
        printf("\tPilha vazia\n");
    return remover;
}

void imprimir(No *pilha)
{
    printf("\n\tPILHA\n");
    while (pilha)
    {
        printf("\t%c\n", pilha->caracter);
        pilha = pilha->proximo;
    }
    printf("\tFIM PILHA\n\n");
}

int forma_par(char f, char d)
{
    switch (f)
    {
    case ')':
        if (d == '(')
            return 1; // bem formada
        else
            return 0; // mal formada
        break;
    case ']':
        if (d == '[')
            return 1; // bem formada
        else
            return 0; // mal formada
        break;
    case '}':
        if (d == '{')
            return 1; // bem formada
        else
            return 0; // mal formada
        break;
    }
}

int identifica_formacao(char x[])
{
    int i = 0;
    No *remover, *pilha = NULL;

    while (x[i] != '\0')
    {
        if (x[i] == '[' || x[i] == '(' || x[i] == '{')
        {
            pilha = push(pilha, x[i]);
            // imprimir(pilha);
        }
        else if (x[i] == ']' || x[i] == ')' || x[i] == '}')
        {
            remover = pop(&pilha);
            if (forma_par(x[i], remover->caracter) == 0)
            {
                printf("\tNão Balanceado\n");
                return 1; // expressao não está balanceada
            }
            free(remover);
        }
        i++;
    }
    // imprimir(pilha);

    if (pilha)
    {
        printf("\tExpressao nao Balanceada!\n");
        return 1;
    }
    else
    {
        printf("\tExpressao Balanceada!\n");
        return 0;
    }
}

int main()
{
    char exp[50];

    printf("\tDigite um expressao: ");
    scanf("%49[^\n]", exp);
    printf("\nExpressao: %s\nRetorno: %d\n", exp, identifica_formacao(exp));
}