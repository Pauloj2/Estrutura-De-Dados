#include <stdio.h>

struct Node {
    int value;   // Tipo de dado 'int' para armazenar n�meros inteiros
    Node *next;  // Ponteiro para o pr�ximo n�

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

    // Fun��o para enfileirar um valor
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

    // Fun��o para desenfileirar um valor
    void dequeue() {
        if (empty()) {
            return;
        }
        Node *aux = first;
        first = first->next;
        delete aux;
    }

    // Fun��o para ver o valor na frente da fila
    int Front() {
        if (empty()) {
            return 0;
        }
        return first->value;
    }
};

// Fun��o para gerar a sequ�ncia de Fibonacci e enfileirar os valores
void fibonacciQueue(int n) {
    Queue fila;
    int a = 0, b = 1;

    // Enfileirar os primeiros 'n' n�meros de Fibonacci
    for (int i = 0; i < n; i++) {
        fila.enqueue(a);
        int temp = a + b;
        a = b;
        b = temp;
    }

    // Exibir os valores na fila (na ordem de inser��o)
    printf("Sequ�ncia de Fibonacci acumulada na fila (da frente para tr�s):\n");
    while (!fila.empty()) {
        printf("%d ", fila.Front());
        fila.dequeue();
    }
    printf("\n");
}

int main() {
    int n;

    // Solicita ao usu�rio o n�mero de elementos da sequ�ncia de Fibonacci
    printf("Digite o n�mero de elementos da sequ�ncia de Fibonacci: ");
    scanf("%d", &n);

    // Gerar e exibir a sequ�ncia de Fibonacci acumulada na fila
    fibonacciQueue(n);

    return 0;
}
