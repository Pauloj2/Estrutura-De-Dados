#include<stdio.h>

// Define uma estrutura chamada Node (nó) que representa um elemento da pilha
struct Node {

    int value; // Valor armazenado no nó
    Node* next; // Ponteiro para o próximo nó na pilha

    // Construtor padrão: inicializa o nó com valor 0 e próximo como NULL
    Node() {
        value = 0; // Inicializa o valor como 0
        next = NULL; // Define o próximo nó como NULL (nenhum próximo nó)
    }

    // Construtor parametrizado: inicializa o nó com um valor fornecido e próximo como NULL
    Node(int _value) {
        value = _value; // Atribui o valor fornecido ao nó
        next = NULL; // Define o próximo nó como NULL
    }
};

// Define uma estrutura chamada Stack (pilha) que implementa uma pilha usando nós
struct Stack() {

    Node* t; // Ponteiro para o topo da pilha

    // Construtor padrão da pilha: inicializa o topo da pilha como NULL (pilha vazia)
    Stack() {
        t = NULL;
    }

    // Verifica se a pilha está vazia
    bool empty() { // Complexidade O(1)
        return t == NULL; // Retorna verdadeiro se o topo for NULL, indicando que a pilha está vazia
    }

    // Insere um novo elemento no topo da pilha
    void push(int value) { // Complexidade O(1)
        Node* n = new Node(value); // Cria um novo nó com o valor fornecido
        if (empty()) { // Verifica se a pilha está vazia
            t = n; // Se estiver vazia, o novo nó se torna o topo da pilha
            return; // Retorna para evitar continuar o código
        }
        n->next = t; // O novo nó aponta para o nó atualmente no topo
        t = n; // Atualiza o topo da pilha para o novo nó
    }

    // Remove o elemento no topo da pilha
    void pop() { // Complexidade O(1)
        if (empty()) { // Verifica se a pilha está vazia
            return; // Se estiver vazia, não faz nada
        }
        if (t->next == NULL) { // Verifica se há apenas um nó na pilha
            delete(t); // Deleta o único nó
            t = NULL; // Atualiza o topo para NULL, indicando pilha vazia
            return; // Retorna para evitar continuar o código
        }
        Node* toDel = t; // Salva o nó atual do topo para deletar depois
        t = t->next; // Atualiza o topo para o próximo nó
        delete(toDel); // Deleta o nó antigo do topo
    }

    // Retorna o valor no topo da pilha sem removê-lo
    int top() { // Complexidade O(1)
        if (empty()) { // Verifica se a pilha está vazia
            printf("Empty\n"); // Imprime "Empty" para indicar pilha vazia
            return -1; // Retorna -1 como valor padrão para pilha vazia
        }
        return t->value; // Retorna o valor armazenado no topo da pilha
    }

};
