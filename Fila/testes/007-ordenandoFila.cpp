
#include <stdio.h>
#include <iostream>
using namespace std;

// Estrutura de um n� (elemento de uma lista encadeada)
struct No {
    int value;  // Valor do n�
    No *next;   // Ponteiro para o pr�ximo n�

    // Construtor padr�o
    No() {
        value = 0;     // Inicializa o valor como 0
        next = NULL;   // Inicializa o ponteiro 'next' como NULL
    }

    // Construtor com valor especificado
    No(int _value) {
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

    // Fun��o para imprimir a fila
    void print() {
        No* current = first;
        while (current != NULL) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Fun��o para ordenar a fila em ordem crescente (Bubble Sort)
    void ordenar() {
        if (empty() || first == last) {
            return; // Se a fila estiver vazia ou tiver apenas um elemento, n�o faz nada
        }

        // Usando Bubble Sort para ordenar os elementos da fila
        No* current = first;
        No* index = NULL;
        int temp;

        // Loop externo para percorrer todos os n�s
        while (current != NULL) {
            index = current->next;

            // Loop interno para comparar os elementos
            while (index != NULL) {
                if (current->value > index->value) {
                    // Troca os valores dos n�s
                    temp = current->value;
                    current->value = index->value;
                    index->value = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
};

int main() {
    Queue lista;  // Cria a fila

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

    // Imprime a fila antes de ordenar
    printf("Fila antes de ordenar: ");
    lista.print();

    // Ordena a fila
    lista.ordenar();

    // Imprime a fila ap�s ordenar
    printf("Fila ap�s ordenar: ");
    lista.print();

    return 0;
}
