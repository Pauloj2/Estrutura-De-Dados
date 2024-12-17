#include <stdio.h>

struct Node {
    int value;
    Node *next;

    Node(int _value) : value(_value), next(NULL) {}
};

struct Stack {
    Node *topo;

    Stack() : topo(NULL) {}

    ~Stack() {
        while (!empty()) {
            pop();
        }
    }

    Stack(const Stack &other) : topo(NULL) {
        if (!other.empty()) {
            Node *current = other.topo;
            Stack temp;

            // Copia os valores para uma pilha temporária
            while (current != NULL) {
                temp.push(current->value);
                current = current->next;
            }

            // Restaura os valores na ordem correta
            while (!temp.empty()) {
                push(temp.peek());
                temp.pop();
            }
        }
    }

    bool empty() const {
        return topo == NULL;
    }

    void push(int value) {
        Node *n = new Node(value);
        n->next = topo;
        topo = n;
    }

    void pop() {
        if (empty()) return;
        Node *aux = topo;
        topo = topo->next;
        delete aux;
    }

    int peek() const {
        if (empty()) {
            printf("Empty\n");
            return -1;
        }
        return topo->value;
    }

    double calculateAverage() {
        if (empty()) {
            printf("A pilha está vazia\n");
            return 0.0;
        }

        int sum = 0, count = 0;
        Stack auxStack;

        while (!empty()) {
            int value = peek();
            sum += value;
            count++;
            auxStack.push(value);
            pop();
        }

        // Restaura a pilha original
        while (!auxStack.empty()) {
            push(auxStack.peek());
            auxStack.pop();
        }

        return (double)sum / count;
    }
};

int main() {
    Stack pilha;

    pilha.push(3);
    pilha.push(1);
    pilha.push(4);
    pilha.push(2);
    pilha.push(5);

    // Exibe os elementos da pilha original
    printf("Pilha original:\n");
    Stack temp = pilha;
    while (!temp.empty()) {
        printf("%d ", temp.peek());
        temp.pop();
    }
    printf("\n");

    // Calcula a média dos valores da pilha
    double average = pilha.calculateAverage();
    printf("A média dos valores da pilha é: %.2f\n", average);

    return 0;
}
