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

    void sortDescending() {
        Stack auxStack; // Pilha auxiliar para ordenar a pilha original em ordem decrescente

        while (!empty()) {
            int current = peek();
            pop();

            // Mova os elementos da pilha auxiliar para a pilha original
            // enquanto forem menores que o elemento atual
            while (!auxStack.empty() && auxStack.peek() < current) {
                push(auxStack.peek());
                auxStack.pop();
            }

            // Coloque o elemento atual na pilha auxiliar
            auxStack.push(current);
        }

        // Restaure a pilha original da pilha auxiliar (ordenada de forma decrescente)
        while (!auxStack.empty()) {
            push(auxStack.peek());
            auxStack.pop();
        }
    }
};

int main() {
    Stack pilha;

    pilha.push(3);
    pilha.push(1);
    pilha.push(4);
    pilha.push(2);
    pilha.push(5);

    printf("Pilha original:\n");
    while (!pilha.empty()) {
        printf("%d ", pilha.peek());
        pilha.pop();
    }
    printf("\n");

    // Recria a pilha com os elementos para ordenar
    pilha.push(3);
    pilha.push(1);
    pilha.push(4);
    pilha.push(2);
    pilha.push(5);

    pilha.sortDescending();

    printf("Pilha ordenada em ordem decrescente:\n");
    while (!pilha.empty()) {
        printf("%d ", pilha.peek());
        pilha.pop();
    }
    printf("\n");

    return 0;
}
