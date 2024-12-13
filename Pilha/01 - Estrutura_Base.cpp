#include<stdio.h>

// Define uma estrutura chamada Node (n�) que representa um elemento da pilha
struct Node {

    int value; // Valor armazenado no n�
    Node* next; // Ponteiro para o pr�ximo n� na pilha

    // Construtor padr�o: inicializa o n� com valor 0 e pr�ximo como NULL
    Node() {
        value = 0; // Inicializa o valor como 0
        next = NULL; // Define o pr�ximo n� como NULL (nenhum pr�ximo n�)
    }

    // Construtor parametrizado: inicializa o n� com um valor fornecido e pr�ximo como NULL
    Node(int _value) {
        value = _value; // Atribui o valor fornecido ao n�
        next = NULL; // Define o pr�ximo n� como NULL
    }
};

// Define uma estrutura chamada Stack (pilha) que implementa uma pilha usando n�s
struct Stack() {

    Node* t; // Ponteiro para o topo da pilha

    // Construtor padr�o da pilha: inicializa o topo da pilha como NULL (pilha vazia)
    Stack() {
        t = NULL;
    }

    // Verifica se a pilha est� vazia
    bool empty() { // Complexidade O(1)
        return t == NULL; // Retorna verdadeiro se o topo for NULL, indicando que a pilha est� vazia
    }

    // Insere um novo elemento no topo da pilha
    void push(int value) { // Complexidade O(1)
        Node* n = new Node(value); // Cria um novo n� com o valor fornecido
        if (empty()) { // Verifica se a pilha est� vazia
            t = n; // Se estiver vazia, o novo n� se torna o topo da pilha
            return; // Retorna para evitar continuar o c�digo
        }
        n->next = t; // O novo n� aponta para o n� atualmente no topo
        t = n; // Atualiza o topo da pilha para o novo n�
    }

    // Remove o elemento no topo da pilha
    void pop() { // Complexidade O(1)
        if (empty()) { // Verifica se a pilha est� vazia
            return; // Se estiver vazia, n�o faz nada
        }
        if (t->next == NULL) { // Verifica se h� apenas um n� na pilha
            delete(t); // Deleta o �nico n�
            t = NULL; // Atualiza o topo para NULL, indicando pilha vazia
            return; // Retorna para evitar continuar o c�digo
        }
        Node* toDel = t; // Salva o n� atual do topo para deletar depois
        t = t->next; // Atualiza o topo para o pr�ximo n�
        delete(toDel); // Deleta o n� antigo do topo
    }

    // Retorna o valor no topo da pilha sem remov�-lo
    int top() { // Complexidade O(1)
        if (empty()) { // Verifica se a pilha est� vazia
            printf("Empty\n"); // Imprime "Empty" para indicar pilha vazia
            return -1; // Retorna -1 como valor padr�o para pilha vazia
        }
        return t->value; // Retorna o valor armazenado no topo da pilha
    }

};
