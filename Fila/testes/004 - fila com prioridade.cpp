#include <stdio.h>
#include <iostream>

using namespace std;

struct No{

    string elemento;
    int prioridade;
    No *next;

    No(){
        elemento = "";
        prioridade = 0;
        next = NULL;
    }
    No(string _elemento, int _prioridade){
        elemento = _elemento;
        prioridade = _prioridade;
        next = NULL;
    }
};

struct Queue{

    No *first;
    No *last;
    int cont;

    Queue(){
        first = NULL;
        last = NULL;
        cont = 0;
    }

    bool empty(){
        return first == NULL;
    }

    void enqueue(string elemento, int prioridade){
        No *aux = new No(elemento, prioridade);
        if(empty()){
            first = aux;
            last = aux;
            cont++;
            return;
        }
        No *paraPercorrer = first;
        No *antesDoAtual = NULL;

        while(paraPercorrer != NULL && paraPercorrer->prioridade >= aux-> prioridade){
            antesDoAtual = paraPercorrer;
            paraPercorrer = paraPercorrer->next;
        }
        if(antesDoAtual == NULL){
            aux->next = first;
            first = aux;
            cont++;
        }else if(paraPercorrer == NULL){
            antesDoAtual->next = aux;
            last = aux;
            cont++;
        }else{
            antesDoAtual->next = aux;
            aux->next = paraPercorrer;
            cont++;
        }
    }

    void dequeue(){
        if(empty()){
            return;
        }
        if(first == last){
            first = NULL;
            last = NULL;
            cont--;
        }
        No *aux = first;
        first = first->next;
        delete(aux);
        cont--;
    }

    string front(){
        if(empty()){
            return "Fila vazia";
        }
        return first->elemento;
    }

    int size(){
        return cont;
    }

};

int main(){

    Queue fila;

    fila.enqueue("A",1);
    fila.enqueue("B",2);
    fila.enqueue("C",3);

    cout << "Primeiro da fila por prioridade: " << fila.front() << endl;

    fila.dequeue();
    cout << "Primeiro da fila por prioridade apos o dequeue: " << fila.front() << endl;

    cout << "Tamanho da fila: " << fila.size() << endl;

    return 0;
}
