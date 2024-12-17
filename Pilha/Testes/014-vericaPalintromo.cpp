#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

struct Node {
    char value;   // Tipo de dado 'char' para armazenar caracteres
    Node *next;   // Ponteiro para o pr�ximo n�

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

    // Fun��o para empilhar um valor
    void push(char value) {
        Node *aux = new Node(value);
        if (empty()) {
            topo = aux;
            return;
        }
        aux->next = topo;
        topo = aux;
    }

    // Fun��o para desempilhar um valor
    void pop() {
        if (empty()) {
            return;
        }
        Node *aux = topo;
        topo = topo->next;
        delete aux;
    }

    // Fun��o para ver o valor no topo da pilha
    char peek() {
        if (empty()) {
            return '\0';  // Retorna caractere nulo caso a pilha esteja vazia
        }
        return topo->value;
    }
};

// Fun��o para verificar se a palavra � um pal�ndromo
bool isPalindrome(const char* palavra) {
    Stack pilha;

    // Empilha todos os caracteres da palavra
    for (int i = 0; i < strlen(palavra); i++) {
        pilha.push(palavra[i]);
    }

    // Verifica se a palavra � um pal�ndromo
    for (int i = 0; i < strlen(palavra); i++) {
        if (palavra[i] != pilha.peek()) {
            return false;  // Se algum caractere n�o corresponder, n�o � pal�ndromo
        }
        pilha.pop();
    }

    return true;  // Se todos os caracteres coincidirem, � pal�ndromo
}

int main() {
    char palavra[100];

    // Solicita ao usu�rio que digite uma palavra
    printf("Digite uma palavra: ");
    cin >> palavra;

    // Verifica se a palavra � um pal�ndromo
    if (isPalindrome(palavra)) {
        printf("A palavra '%s' � um pal�ndromo.\n", palavra);
    } else {
        printf("A palavra '%s' n�o � um pal�ndromo.\n", palavra);
    }

    return 0;
}
