#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

struct Node {
    char value;   // Tipo de dado 'char' para armazenar caracteres
    Node *next;   // Ponteiro para o próximo nó

    Node() {
        value = 0;
        next = NULL;
    }

    Node(char _value) {
        value = _value;
        next = NULL;
    }
};

struct Stack {
    Node *topo;   // Ponteiro para o topo da pilha

    Stack() {
        topo = NULL;
    }

    bool empty() {
        return topo == NULL;
    }

    // Função para empilhar um valor
    void push(char value) {
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
    char peek() {
        if (empty()) {
            return '\0';  // Retorna caractere nulo caso a pilha esteja vazia
        }
        return topo->value;
    }
};

// Função para verificar se a palavra é um palíndromo
bool isPalindrome(const char* palavra) {
    Stack pilha;

    // Empilha todos os caracteres da palavra
    for (int i = 0; i < strlen(palavra); i++) {
        pilha.push(palavra[i]);
    }

    // Verifica se a palavra é um palíndromo
    for (int i = 0; i < strlen(palavra); i++) {
        if (palavra[i] != pilha.peek()) {
            return false;  // Se algum caractere não corresponder, não é palíndromo
        }
        pilha.pop();
    }

    return true;  // Se todos os caracteres coincidirem, é palíndromo
}

int main() {
    char palavra[100];

    // Solicita ao usuário que digite uma palavra
    printf("Digite uma palavra: ");
    cin >> palavra;

    // Verifica se a palavra é um palíndromo
    if (isPalindrome(palavra)) {
        printf("A palavra '%s' é um palíndromo.\n", palavra);
    } else {
        printf("A palavra '%s' não é um palíndromo.\n", palavra);
    }

    return 0;
}
