#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// Estrutura de um n� (elemento de uma lista encadeada)
struct No {

    char value;  // Valor do n� (alterado para char, j� que lidamos com caracteres)
    No *next;    // Ponteiro para o pr�ximo n�

    // Construtor padr�o
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

    // Construtor padr�o
    Stack() {
        topo = NULL;  // Inicializa o ponteiro 'topo' como NULL
    }

    // Verifica se a pilha est� vazia
    bool empty() {
        return topo == NULL;  // Retorna 'true' se 'topo' for NULL
    }

    // Adiciona um caractere no topo da pilha
    void push(char value) {
        No *aux = new No(value);  // Cria um novo n� com o caractere fornecido
        if (empty()) {
            topo = aux;  // Se a pilha estiver vazia, o novo n� � o topo
            return;
        }
        aux->next = topo;  // O novo n� aponta para o antigo topo
        topo = aux;        // O novo n� se torna o topo
    }

    // Remove o caractere do topo da pilha
    void pop() {
        if (empty()) {
            return;  // Se a pilha estiver vazia, n�o faz nada
        }
        No *aux = topo;  // Salva o n� atual do topo
        topo = topo->next;  // Move o topo para o pr�ximo n�
        delete(aux);  // Deleta o antigo n� do topo
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

    printf("Digite o texto at� o ponto final (use '.'): \n");

    // L� caractere por caractere at� o ponto final
    while (scanf("%c", &c) == 1) {
        if (c == ' ') {
            // Encontrou um espa�o: processa a palavra na pilha
            while (!pilha.empty()) {
                resultado += pilha.top(); // Adiciona os caracteres invertidos
                pilha.pop();
            }
            resultado += " "; // Adiciona o espa�o ap�s a palavra
        } else if (c == '.') {
            // Encontrou o ponto final: processa a �ltima palavra e encerra
            while (!pilha.empty()) {
                resultado += pilha.top(); // Adiciona os caracteres invertidos
                pilha.pop();
            }
            resultado += "."; // Adiciona o ponto final
            break;
        } else {
            // Caso contr�rio, adiciona o caractere na pilha
            pilha.push(c);
        }
    }

    // Imprime a frase final
    cout << resultado << endl;

    return 0;
}
