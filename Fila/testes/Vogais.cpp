#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

struct Node {
    char value;
    Node* next;

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
    Node* topo;

    Stack() {
        topo = NULL;
    }

    bool empty() {
        return topo == NULL;
    }

    void push(char value) {
        Node* aux = new Node(value);
        if (empty()) {
            topo = aux;
            return;
        }
        aux->next = topo;
        topo = aux;
    }

    void pop() {
        if (empty()) {
            return;
        }
        Node* aux = topo;
        topo = topo->next;
        delete aux;
    }

    char top() {
        if (empty()) {
            return '\0';
        }
        return topo->value;
    }
};

bool isVowel(char c) {
    c = toupper(c);
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int main() {
    char palavra[101];

    // Entrada da palavra embaralhada
    printf("Digite a palavra embaralhada: ");
    scanf("%s", palavra);

    Stack stackVowels;

    // Processar a palavra e empilhar as vogais
    for (int i = 0; palavra[i] != '\0'; i++) {
        if (islower(palavra[i])) {
            palavra[i] = toupper(palavra[i]); // Converter para maiúscula
        }

        if (isVowel(palavra[i])) {
            stackVowels.push(palavra[i]); // Empilhar vogais
        }
    }

    // Reconstruir a palavra desembaralhada
    printf("Palavra desembaralhada: ");
    for (int i = 0; palavra[i] != '\0'; i++) {
        if (isVowel(palavra[i])) {
            // Substituir vogal pela do topo da pilha
            printf("%c", stackVowels.top());
            stackVowels.pop();
        } else {
            // Manter consoantes no lugar
            printf("%c", palavra[i]);
        }
    }

    printf("\n");

    return 0;
}
