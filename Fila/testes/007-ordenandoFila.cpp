
#include <stdio.h>
#include <iostream>
using namespace std;

// Estrutura de um nó (elemento de uma lista encadeada)
struct No {
    int value;  // Valor do nó
    No *next;   // Ponteiro para o próximo nó

    // Construtor padrão
    No() {
        value = 0;     // Inicializa o valor como 0
        next = NULL;   // Inicializa o ponteiro 'next' como NULL
    }

    // Construtor com valor especificado
    No(int _value) {
        value = _value;   // Inicializa o valor com o valor passado
        next = NULL;      // Inicializa o ponteiro 'next' como NULL
    }
};

// Estrutura para a fila
struct Queue {
    No *first;  // Ponteiro para o primeiro nó (início da fila)
    No *last;   // Ponteiro para o último nó (fim da fila)

    // Construtor padrão
    Queue() {
        first = NULL;  // Inicializa o ponteiro 'first' como NULL
        last = NULL;   // Inicializa o ponteiro 'last' como NULL
    }

    // Função para verificar se a fila está vazia
    bool empty() {
        return first == NULL;  // Retorna 'true' se 'first' for NULL (fila vazia)
    }

    // Função para adicionar um novo valor ao final da fila
    void enqueue(int value) {
        No *aux = new No(value);  // Cria um novo nó com o valor fornecido
        if (empty()) {
            first = aux;   // Se a fila estiver vazia, o novo nó é o primeiro
            last = aux;    // O novo nó também é o último
            return;
        }
        last->next = aux;  // Caso contrário, adiciona o novo nó após o último
        last = aux;        // O novo nó se torna o último
    }

    // Função para remover o valor do início da fila
    void dequeue() {
        if (empty()) {
            return;  // Se a fila estiver vazia, não faz nada
        }
        if (first == last) {
            first = NULL;  // Se a fila tiver apenas um elemento, esvazia a fila
            last = NULL;
            return;
        }
        No *aux = first;  // Salva o primeiro nó
        first = first->next;  // O primeiro nó passa a ser o próximo nó
        delete(aux);  // Deleta o nó removido
    }

    // Função para retornar o valor do primeiro nó da fila
    int front() {
        if (empty()) {
            return -1;  // Retorna -1 se a fila estiver vazia
        }
        return first->value;  // Retorna o valor do primeiro nó
    }

    // Função para imprimir a fila
    void print() {
        No* current = first;
        while (current != NULL) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Função para ordenar a fila em ordem crescente (Bubble Sort)
    void ordenar() {
        if (empty() || first == last) {
            return; // Se a fila estiver vazia ou tiver apenas um elemento, não faz nada
        }

        // Usando Bubble Sort para ordenar os elementos da fila
        No* current = first;
        No* index = NULL;
        int temp;

        // Loop externo para percorrer todos os nós
        while (current != NULL) {
            index = current->next;

            // Loop interno para comparar os elementos
            while (index != NULL) {
                if (current->value > index->value) {
                    // Troca os valores dos nós
                    temp = current->value;
                    current->value = index->value;
                    index->value = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
};

int main() {
    Queue lista;  // Cria a fila

    int quant;

    // Pergunta ao usuário o número de elementos
    printf("Numeros de elementos: ");
    scanf("%d", &quant);

    // Lê os números e os adiciona à fila
    for (int i = 0; i < quant; i++) {
        int num;
        scanf("%d", &num);
        lista.enqueue(num);
    }

    // Imprime a fila antes de ordenar
    printf("Fila antes de ordenar: ");
    lista.print();

    // Ordena a fila
    lista.ordenar();

    // Imprime a fila após ordenar
    printf("Fila após ordenar: ");
    lista.print();

    return 0;
}
