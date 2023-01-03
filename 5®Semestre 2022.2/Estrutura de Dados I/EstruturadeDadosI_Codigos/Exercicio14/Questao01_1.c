/* ---------------------------------------------
* Autor: Eduardo Henrique de Almeida Izidorio
* Matricula: 2020000315
* Questao 01.1 - Implemente a Busca Binária
------------------------------------------------ */

#include <stdio.h>

// função de busca
int buscaBin(int v[], int n, int valor)
{
    int ini = 0;
    int fim = n - 1;

    while (ini <= fim)
    {
        int meio = ini + ((fim - ini) / 2);
        if (v[meio] == valor)
            return meio;
        if (valor > v[meio])
        {
            ini = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }
    return -1;
}

int main()
{
    int n = 10;
    // int v[] = {12, 15, 0, -1, 14, -45, 54, 78, -10, 32}; //vetor de 10 elementos desodernado
    int v[] = {-45, -10, -1, 0, 12, 14, 15, 32, 45, 78}; // vetor de 10 elementos ordernado
    int resp = buscaBin(v, n, -1);                       // buscando o -1

    printf("Indice: %d\n", resp);

    return 0;
}