# Nome: Eduardo Henrique de Almeida Izidorio
# Matricula: 2020000315
# Questao 01 - Aula 13 - Implemente uma fila de prioridade não ordenada usando elementos dinâmicos (células).


class Element:
    def __init__(self, valor, prioridade):
        self.item = valor
        self.prioridade = prioridade

    def __str__(self):
        return str(self.item) + '' + str(self.prioridade)

# implementação da classe fila


class PriorityQueue:
    # inicia com uma fila vazia
    def __init__(self):
        self.itens = []

    # verifica se a fila está vazia
    def is_empty(self):
        return self.itens == []

    # retorna o numero de elementos a fila
    def size(self):
        return len(self.itens)

    # adiciona o elemento no final da fila com sua prioridade
    def enqueue(self, item, prioridade):
        elemento = Element(item, prioridade)
        # função de inserção em uma fila no pyhton
        self.itens.insert(0, elemento)
        print('ENQUEUE %s ' % elemento)

    # remove o elemento com maior prioridade
    def dequeue(self):
        if self.is_empty():
            print('Empty Queue')  # verifica se a fila tá vazia
        else:
            print('DEQUEUE')
            posicao = 0
            menor = self.itens[posicao].prioridade
            # Encontra o elemento de maior prioridade
            for i in range(self.size()):
                if self.itens[i].prioridade < menor:
                    posicao = i
                    menor = self.itens[i].prioridade
            # remove elemento da fila
            # função de remoção do topo "pop"
            removido = self.itens.pop(posicao)

            return removido.item

    def print_queue(self):
        Q = []
        for x in self.itens:  # qualquer elemento dentro da fila eu adiciono no vetor Q
            Q.append(x.item)
        print(Q)


PQ = PriorityQueue()
PQ.print_queue()
PQ.enqueue('a', 4)
PQ.enqueue('b', 2)
PQ.enqueue('c', 3)
PQ.print_queue()
PQ.dequeue()
PQ.print_queue()
