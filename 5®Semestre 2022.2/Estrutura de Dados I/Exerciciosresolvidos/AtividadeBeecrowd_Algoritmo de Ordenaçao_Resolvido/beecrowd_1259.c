/* --------------------------------------------------------
* Exercício: beecrowd 1259 - Pares e Ímpares
* Autor: Eduardo Henrique de Almeida Izidorio
* Matrícula: 2020000315
----------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

void quick(int vet[], int esq, int dir);

int main()
{
    int par[100000], impar[100000];
    int n, i, j, k, l;

    j = 0;
    k = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &l);
        if (l % 2 == 0)
        {
            par[j] = l;
            j++;
        }
        else
        {
            impar[k] = l;
            k++;
        }
    }

    quick(par, 0, j - 1);
    quick(impar, 0, k - 1);

    // printf("\n");

    for (i = 0; i < j; i++)
        printf("%d\n", par[i]);
    for (i = k - 1; i >= 0; i--)
        printf("%d\n", impar[i]);
}

void quick(int vet[], int esq, int dir)
{
    int pivo = esq, i, ch, j;
    for (i = esq + 1; i <= dir; i++)
    {          // Percorre todos os espaços do vetor
        j = i; // atribuição de valor
        if (vet[j] < vet[pivo])
        {                // verifica se o vetor da posição pivo é maior que de outra posição
            ch = vet[j]; // ch recebe o valor que é menor
            while (j > pivo)
            {                        // repete enquanto o j que é a posição do algarismo menor que o pivo ficar na posição 0
                vet[j] = vet[j - 1]; // reorganiza a posição de vetores
                j--;                 // decremento para a organização
            }
            vet[j] = ch; // atribuição da variavel menor que o pivo na posição inicial
            pivo++;      // aumenta a posição do pivo em uma unidade
        }
    }
    if (pivo - 1 >= esq)
    {                              // verifica se o valor do pivo é maior que o final do vetor.
        quick(vet, esq, pivo - 1); // final da execursão da função
    }
    if (pivo + 1 <= dir)
    {                              // verifica se o valor do pivo é menor, indicando que ainda estar dentro das limitações do vetor
        quick(vet, pivo + 1, dir); // chama a função para executar novamente
    }
}