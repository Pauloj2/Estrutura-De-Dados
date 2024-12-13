#include <stdio.h>
#include <iostream>

using namespace std;

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

// Função para intercalar duas filas
Queue interleaveQueues(Queue &q1, Queue &q2) {
    Queue result;

    // Intercalar elementos das duas filas
    while (!q1.empty() || !q2.empty()) {
        if (!q1.empty()) {
            result.enqueue(q1.Front());
            q1.dequeue();
        }
        if (!q2.empty()) {
            result.enqueue(q2.Front());
            q2.dequeue();
        }
    }

    return result;
}

int main() {
    Queue q1, q2;

    // Preencher a fila Q1
    q1.enqueue(1);
    q1.enqueue(3);
    q1.enqueue(5);

    // Preencher a fila Q2
    q2.enqueue(2);
    q2.enqueue(4);
    q2.enqueue(6);

    // Intercalar as filas
    Queue result = interleaveQueues(q1, q2);

    // Exibir a fila resultante
    printf("Fila intercalada: ");
    while (!result.empty()) {
        printf("%d ", result.Front());
        result.dequeue();
    }
    printf("\n");

    return 0;
}
