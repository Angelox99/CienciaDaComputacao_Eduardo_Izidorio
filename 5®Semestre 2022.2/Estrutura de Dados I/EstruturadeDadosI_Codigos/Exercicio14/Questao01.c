/* ---------------------------------------------
* Autor: Eduardo Henrique de Almeida Izidorio
* Matricula: 2020000315
* Questao 01 - Implemente a Busca Sequencial...
------------------------------------------------ */

#include <stdio.h>

// função de busca atraves do indice de cada elemento do vetor
int buscaSeq(int v[], int n, int valor)
{
    for (int i = 0; i < n; i++)
    {
        if (v[i] == valor)
        { // se encontrar o valor, retorna o indice do elemento
            return i;
        }
    }

    return -1; // senão encontrar, retorna -1
}

int main()
{
    int n = 10;
    int v[] = {12, 15, 0, -1, 14, -45, 54, 78, -10, 32}; // vetor de 10 elementos desodernado
    int ivalor = buscaSeq(v, n, -45);                    // buscando o -45

    printf("Indice: %d\n", ivalor);

    return 0;
}