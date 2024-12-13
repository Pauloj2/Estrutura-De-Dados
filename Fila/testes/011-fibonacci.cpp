#include <stdio.h>

struct Node {
    int value;   // Tipo de dado 'int' para armazenar números inteiros
    Node *next;  // Ponteiro para o próximo nó

    Node() {
        value = 0;
        next = NULL;
    }

    Node(int _value) {
        value = _value;
        next = NULL;
    }
};

struct Queue {
    Node *first;
    Node *last;

    Queue() {
        first = NULL;
        last = NULL;
    }

    bool empty() {
        return first == NULL;
    }

    // Função para enfileirar um valor
    void enqueue(int value) {
        Node *aux = new Node(value);
        if (empty()) {
            first = aux;
            last = aux;
            return;
        }
        last->next = aux;
        last = aux;
    }

    // Função para desenfileirar um valor
    void dequeue() {
        if (empty()) {
            return;
        }
        Node *aux = first;
        first = first->next;
        delete aux;
    }

    // Função para ver o valor na frente da fila
    int Front() {
        if (empty()) {
            return 0;
        }
        return first->value;
    }
};

// Função para gerar a sequência de Fibonacci e enfileirar os valores
void fibonacciQueue(int n) {
    Queue fila;
    int a = 0, b = 1;

    // Enfileirar os primeiros 'n' números de Fibonacci
    for (int i = 0; i < n; i++) {
        fila.enqueue(a);
        int temp = a + b;
        a = b;
        b = temp;
    }

    // Exibir os valores na fila (na ordem de inserção)
    printf("Sequência de Fibonacci acumulada na fila (da frente para trás):\n");
    while (!fila.empty()) {
        printf("%d ", fila.Front());
        fila.dequeue();
    }
    printf("\n");
}

int main() {
    int n;

    // Solicita ao usuário o número de elementos da sequência de Fibonacci
    printf("Digite o número de elementos da sequência de Fibonacci: ");
    scanf("%d", &n);

    // Gerar e exibir a sequência de Fibonacci acumulada na fila
    fibonacciQueue(n);

    return 0;
}
