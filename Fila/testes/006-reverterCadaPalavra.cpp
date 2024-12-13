#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// Estrutura de um nó (elemento de uma lista encadeada)
struct No {

    char value;  // Valor do nó (alterado para char, já que lidamos com caracteres)
    No *next;    // Ponteiro para o próximo nó

    // Construtor padrão
    No() {
        value = '\0';   // Inicializa o valor como caractere nulo
        next = NULL;    // Inicializa o ponteiro 'next' como NULL
    }

    // Construtor com valor especificado
    No(char _value) {
        value = _value; // Inicializa o valor com o caractere fornecido
        next = NULL;    // Inicializa o ponteiro 'next' como NULL
    }
};

// Estrutura da pilha
struct Stack {

    No *topo;  // Ponteiro para o topo da pilha

    // Construtor padrão
    Stack() {
        topo = NULL;  // Inicializa o ponteiro 'topo' como NULL
    }

    // Verifica se a pilha está vazia
    bool empty() {
        return topo == NULL;  // Retorna 'true' se 'topo' for NULL
    }

    // Adiciona um caractere no topo da pilha
    void push(char value) {
        No *aux = new No(value);  // Cria um novo nó com o caractere fornecido
        if (empty()) {
            topo = aux;  // Se a pilha estiver vazia, o novo nó é o topo
            return;
        }
        aux->next = topo;  // O novo nó aponta para o antigo topo
        topo = aux;        // O novo nó se torna o topo
    }

    // Remove o caractere do topo da pilha
    void pop() {
        if (empty()) {
            return;  // Se a pilha estiver vazia, não faz nada
        }
        No *aux = topo;  // Salva o nó atual do topo
        topo = topo->next;  // Move o topo para o próximo nó
        delete(aux);  // Deleta o antigo nó do topo
    }

    // Retorna o caractere do topo da pilha
    char top() {
        if (empty()) {
            return '\0';  // Retorna caractere nulo se a pilha estiver vazia
        }
        return topo->value;  // Retorna o valor do topo
    }
};

int main() {

    Stack pilha;  // Pilha para processar caracteres
    string resultado = ""; // Armazena a frase final
    char c;

    printf("Digite o texto até o ponto final (use '.'): \n");

    // Lê caractere por caractere até o ponto final
    while (scanf("%c", &c) == 1) {
        if (c == ' ') {
            // Encontrou um espaço: processa a palavra na pilha
            while (!pilha.empty()) {
                resultado += pilha.top(); // Adiciona os caracteres invertidos
                pilha.pop();
            }
            resultado += " "; // Adiciona o espaço após a palavra
        } else if (c == '.') {
            // Encontrou o ponto final: processa a última palavra e encerra
            while (!pilha.empty()) {
                resultado += pilha.top(); // Adiciona os caracteres invertidos
                pilha.pop();
            }
            resultado += "."; // Adiciona o ponto final
            break;
        } else {
            // Caso contrário, adiciona o caractere na pilha
            pilha.push(c);
        }
    }

    // Imprime a frase final
    cout << resultado << endl;

    return 0;
}
