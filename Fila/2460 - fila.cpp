#include <stdio.h>
#include <iostream>
#include <unordered_set>

using namespace std;

struct No {
    int value;
    No* next;

    No() {
        value = 0;
        next = NULL;
    }

    No(int _value) {
        value = _value;
        next = NULL;
    }
};

struct Queue {
    No* first;
    No* last;

    Queue() {
        first = NULL;
        last = NULL;
    }

    bool empty() {
        return first == NULL;
    }

    void enqueue(int value) {
        No* aux = new No(value);
        if (empty()) {
            first = aux;
            last = aux;
            return;
        }
        last->next = aux;
        last = aux;
    }

    void dequeue() {
        if (empty()) {
            return;
        }
        if (first == last) {
            first = NULL;
            last = NULL;
            return;
        }
        No* aux = first;
        first = first->next;
        delete (aux);
    }

    int front() {
        if (empty()) {
            return -1;
        }
        return first->value;
    }

    void imprimirLista() {
        No *aux = first;
        bool firstElement = true;
        while (aux != NULL) {
            if (!firstElement) {
                printf(" ");
            }
            printf("%d", aux->value);
            firstElement = false;
            aux = aux->next;
        }
        printf("\n");
    }
};

int main() {
    Queue fila;

    int N, M;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        fila.enqueue(num);
    }

    scanf("%d", &M);

    unordered_set<int> paraExcluir;

    for (int i = 0; i < M; i++) {
        int num;
        scanf("%d", &num);
        paraExcluir.insert(num);
    }

    Queue filaAposRemover;

    No* aux = fila.first;
    while (aux != NULL) {
        if (paraExcluir.find(aux->value) == paraExcluir.end()) {
            filaAposRemover.enqueue(aux->value);
        }
        aux = aux->next;
    }

    filaAposRemover.imprimirLista();

    return 0;
}
