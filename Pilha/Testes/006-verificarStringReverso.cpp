#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

struct No{

    char value;
    No *next;

    No(){
        value = ' ';
        next = NULL;
    }

    No(char _value){
        value = _value;
        next = NULL;
    }
};

struct Stack{

    No *topo;

    Stack(){
        topo = NULL;
    }

    bool empty(){
        return topo == NULL;
    }

    void push(char value){
        No *aux = new No(value);
        if(empty()){
            topo = aux;
            return;
        }
        aux->next = topo;
        topo = aux;
    }

    void pop(){
        if(empty()){
            return;
        }
        if(topo->next == NULL){
            delete(topo);
            topo = NULL;
            return;
        }
        No *aux = topo;
        topo = topo->next;
        delete(aux);
    }

    char top(){
        if(empty()){
            return '\0';
        }
        return topo->value;
    }

};

 bool verificarString(string XY) {

        if (XY.size() % 2 != 0) {
            return false;
        }

        int tamanho = XY.size() / 2;
        Stack pilha;

        for (int i = 0; i < tamanho; i++) {
            pilha.push(XY[i]);
        }

        for (int i = tamanho; i < XY.size(); i++) {
            if (pilha.empty() || pilha.top() != XY[i]) {
                return false;
            }
            pilha.pop();
        }

        return pilha.empty();
}

int main() {

    string XY;

    cin >> XY;

    if(verificarString(XY)){
        printf("A string está na forma XY.\n");
    }else{
        printf("A string não esta no forma XY\n");
    }


    return 0;
}
