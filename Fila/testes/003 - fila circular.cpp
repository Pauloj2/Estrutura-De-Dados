#include <stdio.h>
#include <iostream>
#define N 3

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

    int cont = 0;
    int tamanho = N;

    Queue(){
        first = NULL;
        last = NULL;
        cont = 0;
    }

    bool empty(){
        return first == NULL;
    }

    bool full(){
        return cont == tamanho;
    }

    void enqueue(int value){
        No *aux = new No(value);
        if(full()){
            No *elimi = first;
            first = first->next;
            delete(elimi);
            cont--;
        }
        if(empty()){
            first = aux;
            last = aux;
        }else{
            last->next = aux;
            last = aux;
        }
        cont++;
    }

    void dequeue(){
        if(empty()){
            cout << "A fila esta vazia, nao e posivel retirar\n";
            return;
        }
        if(first == last){
            delete(first);
            first = NULL;
            last = NULL;
            cont = 0;
        }
        No *aux = first;
        first = first->next;
        delete aux;
        cont--;
    }

    int front(){
        if(empty()){
            cout << "Lista vazia\n";
            return 0;
        }
        return first->value;
    }

    void print(){
        if(empty()){
            cout << "Lista vazia\n";
            return;
        }
        No *aux = first;
        while(aux != NULL){
            cout << aux->value << " ";
            aux = aux->next;
        }
        printf("\n");
    }
};

int main(){
    Queue q;

    // Testando a fila circular
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print();  // Esperado: 10 20 30

    q.enqueue(40);  // Sobrescreve o item mais antigo (10)
    q.print();  // Esperado: 20 30 40

    q.dequeue();  // Remove o item mais antigo (20)
    q.print();  // Esperado: 30 40

    q.enqueue(50);  // Agora, a fila contém 30, 40, 50
    q.print();  // Esperado: 30 40 50

    q.enqueue(60);  // Sobrescreve o item mais antigo (30)
    q.print();  // Esperado: 40 50 60

    return 0;

}
