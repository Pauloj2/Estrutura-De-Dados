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

struct Stack {
    Node *topo;

    Stack() {
        topo = NULL;
    }

    bool empty() {
        return topo == NULL;
    }

    void push(int value) {
        Node *n = new Node(value);
        if (empty()) {
            topo = n;
        } else {
            n->next = topo;
            topo = n;
        }
    }

    void pop() {
        if (empty()) {
            return;
        }
        Node *aux = topo;
        topo = topo->next;
        delete aux;
    }

    int peek() {
        if (empty()) {
            printf("Empty\n");
            return -1;
        }
        return topo->value;
    }

    int findMin() {
        if (empty()) {
            printf("A pilha está vazia\n");
            return -1; // Retorna -1 se a pilha estiver vazia
        }

        Stack auxStack; // Pilha auxiliar para restaurar a pilha original
        int minElement = topo->value; // Inicializa com o topo da pilha

        // Percorre a pilha original e encontra o menor elemento
        while (!empty()) {
            int currentValue = peek();
            if (currentValue < minElement) {
                minElement = currentValue;
            }
            auxStack.push(currentValue);
            pop();
        }

        // Restaura a pilha original
        while (!auxStack.empty()) {
            push(auxStack.peek());
            auxStack.pop();
        }

        return minElement;
    }
};

int main() {
    Stack pilha;

    pilha.push(3);
    pilha.push(2);
    pilha.push(1);
    pilha.push(0);

    printf("Topo da pilha: %d\n", pilha.peek());
    pilha.pop();
    printf("O topo foi removido\n\n");
    printf("Topo da pilha depois de remover: %d\n", pilha.peek());

    int min = pilha.findMin();
    if (min != -1) {
        printf("O menor elemento da pilha é: %d\n", min);
    }

    return 0;
}
