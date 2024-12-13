#include <stdio.h>
#include <iostream>

using namespace std;

struct No{

    int value;
    No *next;

    No(){
        value = 0;
        next = NULL;
    }

    No(int _value){
        value = _value;
        next = NULL;
    }
};

struct Queue{

    No *first;
    No *last;

    Queue(){
        first = NULL;
        last = NULL;
    }

    bool empty(){
        return first == NULL;
    }

    void enqueue(int value){
        No *aux = new No(value);
        if(empty()){
            first = aux;
            last = aux;
            return;
        }
        last->next = aux;
        last = aux;
    }

    void dequeue(){
        if(empty()){
            return;
        }
        if(first == last){
            delete(first);
            first = NULL;
            last = NULL;
            return;
        }
        No *aux = first;
        first = first->next;
        delete(aux);
    }

    int front(){
        if(empty()){
            return -1;
        }
        return first->value;
    }
};

int main(){

    Queue lista;

    lista.enqueue(1);
    cout << "Tarefa 1 adicionada a fila.\n";

    lista.enqueue(2);
    cout << "Tarefa 2 adicionada a fila.\n";

    printf("O primeiro da fila para ser executado e: %d\n", lista.front());

    lista.dequeue();
    cout << "O primeiro de fila foi executado e foi retirado.\n\n";

    lista.enqueue(3);
    cout << "Tarefa 3 adicionada a fila.\n";

    printf("Agora o primeiro da fila para ser executado e: %d\n", lista.front());

    lista.dequeue();
    cout << "O primeiro de fila foi executado e foi retirado.\n\n";

    printf("Agora o primeiro da fila para ser executado e: %d\n", lista.front());

    lista.dequeue();
    cout << "O primeiro de fila foi executado e foi retirado.\n";

    return 0;
}
