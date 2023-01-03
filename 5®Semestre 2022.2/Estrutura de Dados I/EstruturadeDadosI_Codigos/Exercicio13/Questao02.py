# Nome: Eduardo Henrique de Almeida Izidorio
# Matricula: 2020000315
# Questao 02 - Aula 13 - Implemente a estrutura de dados Heap, tendo como base os algoritmos de heap vistos no slide


def heapify(arr, n, i):
    smallest = i  # Initialize smallest as root
    l = 2 * i + 1  # left = 2*i + 1
    r = 2 * i + 2  # right = 2*i + 2

    # Se o filho esquerdo for menor que o root
    if l < n and arr[l] < arr[smallest]:
        smallest = l

    # Se o filho direito for menor que o root
    if r < n and arr[r] < arr[smallest]:
        smallest = r

    # Se o maior não for o root
    if smallest != i:
        (arr[i],
         arr[smallest]) = (arr[smallest],
                           arr[i])

        # chama a função novamente para os filhos
        heapify(arr, n, smallest)


def heapSort(arr, n):

    for i in range(int(n / 2) - 1, -1, -1):
        heapify(arr, n, i)

    for i in range(n-1, -1, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr, i, 0)


# ----- MAIN ------
A = [19, 18, 14, 17, 12, 13, 21, 3, 9]
n = len(A)
print(A)
heapSort(A, n)
print(A)
