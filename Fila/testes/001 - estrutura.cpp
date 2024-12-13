#include <stdio.h>

struct Node{

    int value;
    Node *next;

    Node(){
        value = 0;
        next = NULL;
    }

    Node(int _value){
        value = _value;
        next = NULL;
    }
};

struct Queue{

    Node *first;
    Node *last;

    Queue(){
        first = NULL;
        last = NULL;
    }

    bool empty(){
        return first == NULL;
    }

    void enqueue(int value){
        Node *aux = new Node(value);
        if(empty()){
            first = aux;
            last = aux;
            return;
        }
        last->next = aux;
        last = aux;
    }

    void dequeue(){
        if(empty()){return;}
        if(first == last){
            delete(first);
            first = NULL;
            last = NULL;
            return;
        }
        Node *aux = first;
        first = first->next;
        delete(aux);
    }

    int Front(){
        if(empty()){return 0;}
        return first->value;
    }
};

int main(){

    Queue fila;

    fila.enqueue(1);
    fila.enqueue(2);
    fila.enqueue(3);
    fila.enqueue(4);
    fila.enqueue(5);

    while(!fila.empty()){
        printf("%d", fila.Front());
        fila.dequeue();
    }

    return 0;
}
