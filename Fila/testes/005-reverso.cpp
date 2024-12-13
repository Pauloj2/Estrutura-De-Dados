#include <stdio.h>
#include <iostream>

using namespace std;

// Estrutura de um n� (elemento de uma lista encadeada)
struct No {

    int value;  // Valor do n�
    No *next;   // Ponteiro para o pr�ximo n�

    // Construtor padr�o
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

    No *first;  // Ponteiro para o primeiro n� (in�cio da fila)
    No *last;   // Ponteiro para o �ltimo n� (fim da fila)

    // Construtor padr�o
    Queue() {
        first = NULL;  // Inicializa o ponteiro 'first' como NULL
        last = NULL;   // Inicializa o ponteiro 'last' como NULL
    }

    // Fun��o para verificar se a fila est� vazia
    bool empty() {
        return first == NULL;  // Retorna 'true' se 'first' for NULL (fila vazia)
    }

    // Fun��o para adicionar um novo valor ao final da fila
    void enqueue(int value) {
        No *aux = new No(value);  // Cria um novo n� com o valor fornecido
        if (empty()) {
            first = aux;   // Se a fila estiver vazia, o novo n� � o primeiro
            last = aux;    // O novo n� tamb�m � o �ltimo
            return;
        }
        last->next = aux;  // Caso contr�rio, adiciona o novo n� ap�s o �ltimo
        last = aux;        // O novo n� se torna o �ltimo
    }

    // Fun��o para remover o valor do in�cio da fila
    void dequeue() {
        if (empty()) {
            return;  // Se a fila estiver vazia, n�o faz nada
        }
        if (first == last) {
            first = NULL;  // Se a fila tiver apenas um elemento, esvazia a fila
            last = NULL;
            return;
        }
        No *aux = first;  // Salva o primeiro n�
        first = first->next;  // O primeiro n� passa a ser o pr�ximo n�
        delete(aux);  // Deleta o n� removido
    }

    // Fun��o para retornar o valor do primeiro n� da fila
    int front() {
        if (empty()) {
            return -1;  // Retorna -1 se a fila estiver vazia
        }
        return first->value;  // Retorna o valor do primeiro n�
    }
};

// Estrutura para a pilha
struct Stack {

    No *topo;  // Ponteiro para o topo da pilha

    // Construtor padr�o
    Stack() {
        topo = NULL;  // Inicializa o ponteiro 'topo' como NULL
    }

    // Fun��o para verificar se a pilha est� vazia
    bool empty() {
        return topo == NULL;  // Retorna 'true' se 'topo' for NULL (pilha vazia)
    }

    // Fun��o para adicionar um valor no topo da pilha
    void push(int value) {
        No *aux = new No(value);  // Cria um novo n� com o valor fornecido
        if (empty()) {
            topo = aux;  // Se a pilha estiver vazia, o novo n� � o topo
            return;
        }
        aux->next = topo;  // O novo n� aponta para o antigo topo
        topo = aux;        // O novo n� se torna o topo
    }

    // Fun��o para remover o valor do topo da pilha
    void pop() {
        if (empty()) {
            return;  // Se a pilha estiver vazia, n�o faz nada
        }
        if (topo->next == NULL) {
            delete(topo);  // Se houver apenas um elemento, deleta o topo
            topo = NULL;
        }
        No *aux = topo;  // Salva o topo da pilha
        topo = topo->next;  // O topo passa a ser o pr�ximo n�
        delete(aux);  // Deleta o antigo topo
    }

    // Fun��o para retornar o valor do topo da pilha
    int top() {
        if (empty()) {
            return -1;  // Retorna -1 se a pilha estiver vazia
        }
        return topo->value;  // Retorna o valor do topo
    }
};

// Fun��o para mover todos os elementos da fila para a pilha, efetivamente invertendo a ordem
void verificaReverso(Queue &lista, Stack &reverso) {
    while (!lista.empty()) {
        reverso.push(lista.front());  // Coloca o valor do primeiro n� da fila na pilha
        lista.dequeue();  // Remove o primeiro n� da fila
    }
}

// Fun��o para imprimir os valores da pilha
void print(Stack &pilha) {
    while (!pilha.empty()) {
        printf("%d", pilha.top());  // Imprime o valor do topo da pilha
        pilha.pop();  // Remove o topo da pilha

        if (!pilha.empty()) {  // Se ainda houver elementos, imprime um espa�o
            printf(" ");
        }
    }
    printf("\n");  // Imprime uma nova linha no final
}

int main() {

    Queue lista;  // Cria a fila
    Stack reverso;  // Cria a pilha

    int quant;

    // Pergunta ao usu�rio o n�mero de elementos
    printf("Numeros de elementos: ");
    scanf("%d", &quant);

    // L� os n�meros e os adiciona � fila
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
