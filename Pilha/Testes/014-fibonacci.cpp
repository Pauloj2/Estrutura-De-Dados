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

struct Stack {
    Node *topo;  // Ponteiro para o topo da pilha

    Stack() {
        topo = NULL;
    }

    bool empty() {
        return topo == NULL;
    }

    // Função para empilhar um valor
    void push(int value) {
        Node *aux = new Node(value);
        if (empty()) {
            topo = aux;
            return;
        }
        aux->next = topo;
        topo = aux;
    }

    // Função para desempilhar um valor
    void pop() {
        if (empty()) {
            return;
        }
        Node *aux = topo;
        topo = topo->next;
        delete aux;
    }

    // Função para ver o valor no topo da pilha
    int peek() {
        if (empty()) {
            return -1;  // Retorna -1 caso a pilha esteja vazia
        }
        return topo->value;
    }
};

// Função para gerar a sequência de Fibonacci e empilhar os valores
void fibonacciStack(int n) {
    Stack pilha;
    int a = 0, b = 1;

    // Empilhar os primeiros 'n' números de Fibonacci
    for (int i = 0; i < n; i++) {
        pilha.push(a);
        int temp = a + b;
        a = b;
        b = temp;
    }

    // Exibir os valores empilhados
    cout << "Sequência de Fibonacci acumulada na pilha (de cima para baixo):\n";
    while (!pilha.empty()) {
        cout << pilha.peek() << " ";
        pilha.pop();
    }
    cout << endl;
}

int main() {
    int n;

    // Solicita ao usuário o número de elementos da sequência de Fibonacci
    printf("Digite o número de elementos da sequência de Fibonacci: ");
    cin >> n;

    // Gerar e exibir a sequência de Fibonacci acumulada na pilha
    fibonacciStack(n);

    return 0;
}
