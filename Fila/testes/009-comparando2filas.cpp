#include <stdio.h>

struct Node {
    int value;
    Node *next;

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

    void dequeue() {
        if (empty()) { return; }
        if (first == last) {
            delete(first);
            first = NULL;
            last = NULL;
            return;
        }
        Node *aux = first;
        first = first->next;
        delete(aux);
    }

    int Front() {
        if (empty()) { return 0; }
        return first->value;
    }

    // Função para contar o número de elementos na fila
    int countElements() {
        int count = 0;
        Node *current = first;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        return count;
    }
};

// Função para comparar o tamanho de duas filas
bool compararFilas(Queue &F1, Queue &F2) {
    int tamanhoF1 = F1.countElements();
    int tamanhoF2 = F2.countElements();

    if (tamanhoF1 > tamanhoF2) {
        return true;  // F1 tem mais elementos que F2
    } else {
        return false; // F1 não tem mais elementos que F2
    }
}

int main() {
    Queue fila1, fila2;
    int n1, n2;

    // Solicitar ao usuário o número de elementos da fila 1
    printf("Digite o número de elementos na fila 1: ");
    scanf("%d", &n1);

    // Solicitar ao usuário os elementos da fila 1
    printf("Digite os elementos da fila 1:\n");
    for (int i = 0; i < n1; i++) {
        int num;
        scanf("%d", &num);
        fila1.enqueue(num);
    }

    // Solicitar ao usuário o número de elementos da fila 2
    printf("Digite o número de elementos na fila 2: ");
    scanf("%d", &n2);

    // Solicitar ao usuário os elementos da fila 2
    printf("Digite os elementos da fila 2:\n");
    for (int i = 0; i < n2; i++) {
        int num;
        scanf("%d", &num);
        fila2.enqueue(num);
    }

    // Comparar as filas
    if (compararFilas(fila1, fila2)) {
        printf("A fila 1 tem mais elementos que a fila 2.\n");
    } else {
        printf("A fila 1 não tem mais elementos que a fila 2.\n");
    }

    return 0;
}
