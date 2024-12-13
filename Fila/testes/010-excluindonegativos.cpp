#include <stdio.h>

struct Node {
    int value;
    Node *next;

    Node() {
        value = 0;
        next = NULL;
    }

    Node(int _value) {
        value = _value;
        next = NULL;
    }
};

struct Queue {
    Node *first;
    Node *last;

    Queue() {
        first = NULL;
        last = NULL;
    }

    bool empty() {
        return first == NULL;
    }

    void enqueue(int value) {
        Node *aux = new Node(value);
        if (empty()) {
            first = aux;
            last = aux;
            return;
        }
        last->next = aux;
        last = aux;
    }

    void dequeue() {
        if (empty()) { return; }
        if (first == last) {
            delete(first);
            first = NULL;
            last = NULL;
            return;
        }
        Node *aux = first;
        first = first->next;
        delete(aux);
    }

    int Front() {
        if (empty()) { return 0; }
        return first->value;
    }

    // Fun��o para contar o n�mero de elementos na fila
    int countElements() {
        int count = 0;
        Node *current = first;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Fun��o para excluir n�meros negativos
    void excluirNegativos() {
        while (first != NULL && first->value < 0) {
            dequeue();  // Remove os negativos do in�cio da fila
        }

        Node *current = first;
        while (current != NULL && current->next != NULL) {
            if (current->next->value < 0) {
                Node *aux = current->next;
                current->next = current->next->next;  // Remove o n� negativo
                delete aux;
            } else {
                current = current->next;  // Avan�a para o pr�ximo n�
            }
        }
    }
};

int main() {
    Queue fila;
    int n;

    // Solicitar ao usu�rio o n�mero de elementos na fila
    printf("Digite o n�mero de elementos na fila: ");
    scanf("%d", &n);

    // Solicitar ao usu�rio os elementos da fila
    printf("Digite os elementos da fila:\n");
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        fila.enqueue(num);  // Adiciona cada n�mero na fila
    }

    // Excluir os n�meros negativos da fila
    fila.excluirNegativos();

    // Imprimir os elementos restantes na fila
    printf("Elementos da fila ap�s excluir negativos:\n");
    while (!fila.empty()) {
        printf("%d ", fila.Front());
        fila.dequeue();
    }

    return 0;
}
