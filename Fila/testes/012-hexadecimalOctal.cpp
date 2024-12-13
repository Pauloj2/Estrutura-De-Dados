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
    Node *topo;   // Ponteiro para o topo da pilha

    Stack() {
        topo = NULL;
    }

    bool empty() {
        return topo == NULL;
    }

    void push(int value) {
        Node *aux = new Node(value);
        if (empty()) {
            topo = aux;
            return;
        }
        aux->next = topo;
        topo = aux;
    }

    void pop() {
        if (empty()) { return; }
        Node *aux = topo;
        topo = topo->next;
        delete aux;
    }

    int peek() {
        if (empty()) {
            return -1;  // Valor inválido para pilha vazia
        }
        return topo->value;
    }
};

// Função para converter decimal para binário
void decimalToBinary(int decimal) {
    Stack pilha;
    int quociente = decimal, resto;

    while (quociente != 0) {
        resto = quociente % 2;
        pilha.push(resto);
        quociente = quociente / 2;
    }

    printf("Número em Binário: ");
    while (!pilha.empty()) {
        printf("%d", pilha.peek());
        pilha.pop();
    }
    printf("\n");
}

// Função para converter decimal para octal
void decimalToOctal(int decimal) {
    Stack pilha;
    int quociente = decimal, resto;

    while (quociente != 0) {
        resto = quociente % 8;
        pilha.push(resto);
        quociente = quociente / 8;
    }

    printf("Número em Octal: ");
    while (!pilha.empty()) {
        printf("%d", pilha.peek());
        pilha.pop();
    }
    printf("\n");
}

// Função para converter decimal para hexadecimal
void decimalToHexadecimal(int decimal) {
    Stack pilha;
    int quociente = decimal, resto;
    char hexDigits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    while (quociente != 0) {
        resto = quociente % 16;
        pilha.push(resto);
        quociente = quociente / 16;
    }

    printf("Número em Hexadecimal: ");
    while (!pilha.empty()) {
        printf("%c", hexDigits[pilha.peek()]);
        pilha.pop();
    }
    printf("\n");
}

int main() {
    int decimal, cont, opcao;

    printf("Digite a quantidade de números: \n");
    scanf("%d", &cont);

    for (int i = 0; i < cont; i++) {
        printf("Digite um número decimal: ");
        scanf("%d", &decimal);

        printf("Escolha a conversão desejada:\n");
        printf("1. Decimal para Binário\n");
        printf("2. Decimal para Octal\n");
        printf("3. Decimal para Hexadecimal\n");
        printf("Digite a opção (1/2/3): ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                decimalToBinary(decimal);
                break;
            case 2:
                decimalToOctal(decimal);
                break;
            case 3:
                decimalToHexadecimal(decimal);
                break;
            default:
                printf("Opção inválida.\n");
        }
    }

    return 0;
}
