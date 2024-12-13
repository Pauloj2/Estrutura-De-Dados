#include <stdio.h>
#include <iostream>

using namespace std;

// Estrutura de um nó (elemento de uma lista encadeada)
struct No {

    int value;  // Valor do nó
    No *next;   // Ponteiro para o próximo nó

    // Construtor padrão
    No(){
        value = 0;     // Inicializa o valor como 0
        next = NULL;   // Inicializa o ponteiro 'next' como NULL
    }

    // Construtor com valor especificado
    No(int _value){
        value = _value;   // Inicializa o valor com o valor passado
        next = NULL;      // Inicializa o ponteiro 'next' como NULL
    }
};

// Estrutura para a fila
struct Queue {

    No *first;  // Ponteiro para o primeiro nó (início da fila)
    No *last;   // Ponteiro para o último nó (fim da fila)

    // Construtor padrão
    Queue() {
        first = NULL;  // Inicializa o ponteiro 'first' como NULL
        last = NULL;   // Inicializa o ponteiro 'last' como NULL
    }

    // Função para verificar se a fila está vazia
    bool empty() {
        return first == NULL;  // Retorna 'true' se 'first' for NULL (fila vazia)
    }

    // Função para adicionar um novo valor ao final da fila
    void enqueue(int value) {
        No *aux = new No(value);  // Cria um novo nó com o valor fornecido
        if (empty()) {
            first = aux;   // Se a fila estiver vazia, o novo nó é o primeiro
            last = aux;    // O novo nó também é o último
            return;
        }
        last->next = aux;  // Caso contrário, adiciona o novo nó após o último
        last = aux;        // O novo nó se torna o último
    }

    // Função para remover o valor do início da fila
    void dequeue() {
        if (empty()) {
            return;  // Se a fila estiver vazia, não faz nada
        }
        if (first == last) {
            first = NULL;  // Se a fila tiver apenas um elemento, esvazia a fila
            last = NULL;
            return;
        }
        No *aux = first;  // Salva o primeiro nó
        first = first->next;  // O primeiro nó passa a ser o próximo nó
        delete(aux);  // Deleta o nó removido
    }

    // Função para retornar o valor do primeiro nó da fila
    int front() {
        if (empty()) {
            return -1;  // Retorna -1 se a fila estiver vazia
        }
        return first->value;  // Retorna o valor do primeiro nó
    }
};

// Estrutura para a pilha
struct Stack {

    No *topo;  // Ponteiro para o topo da pilha

    // Construtor padrão
    Stack() {
        topo = NULL;  // Inicializa o ponteiro 'topo' como NULL
    }

    // Função para verificar se a pilha está vazia
    bool empty() {
        return topo == NULL;  // Retorna 'true' se 'topo' for NULL (pilha vazia)
    }

    // Função para adicionar um valor no topo da pilha
    void push(int value) {
        No *aux = new No(value);  // Cria um novo nó com o valor fornecido
        if (empty()) {
            topo = aux;  // Se a pilha estiver vazia, o novo nó é o topo
            return;
        }
        aux->next = topo;  // O novo nó aponta para o antigo topo
        topo = aux;        // O novo nó se torna o topo
    }

    // Função para remover o valor do topo da pilha
    void pop() {
        if (empty()) {
            return;  // Se a pilha estiver vazia, não faz nada
        }
        if (topo->next == NULL) {
            delete(topo);  // Se houver apenas um elemento, deleta o topo
            topo = NULL;
        }
        No *aux = topo;  // Salva o topo da pilha
        topo = topo->next;  // O topo passa a ser o próximo nó
        delete(aux);  // Deleta o antigo topo
    }

    // Função para retornar o valor do topo da pilha
    int top() {
        if (empty()) {
            return -1;  // Retorna -1 se a pilha estiver vazia
        }
        return topo->value;  // Retorna o valor do topo
    }
};

// Função para mover todos os elementos da fila para a pilha, efetivamente invertendo a ordem
void verificaReverso(Queue &lista, Stack &reverso) {
    while (!lista.empty()) {
        reverso.push(lista.front());  // Coloca o valor do primeiro nó da fila na pilha
        lista.dequeue();  // Remove o primeiro nó da fila
    }
}

// Função para imprimir os valores da pilha
void print(Stack &pilha) {
    while (!pilha.empty()) {
        printf("%d", pilha.top());  // Imprime o valor do topo da pilha
        pilha.pop();  // Remove o topo da pilha

        if (!pilha.empty()) {  // Se ainda houver elementos, imprime um espaço
            printf(" ");
        }
    }
    printf("\n");  // Imprime uma nova linha no final
}

int main() {

    Queue lista;  // Cria a fila
    Stack reverso;  // Cria a pilha

    int quant;

    // Pergunta ao usuário o número de elementos
    printf("Numeros de elementos: ");
    scanf("%d", &quant);

    // Lê os números e os adiciona à fila
    for (int i = 0; i < quant; i++) {
        int num;
        scanf("%d", &num);
        lista.enqueue(num);
    }

    // Inverte os elementos da fila movendo-os para a pilha
    verificaReverso(lista, reverso);

    // Imprime os elementos invertidos da pilha
    print(reverso);

    return 0;
}
