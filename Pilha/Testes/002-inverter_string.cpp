#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

struct Node{

    string value;
    Node *next;

    Node(){
        value = "";
        next = NULL;
    }
    Node(string _value){
        value = _value;
        next = NULL;
    }
};

struct Stack{

    Node *topo;

    Stack(){
        topo = NULL;
    }

    bool empty(){
        return topo == NULL;
    }

    void push(string value){
        Node *n = new Node(value);
        if(empty()){
            topo = n;
        }else{
            n->next = topo;
            topo = n;
        }
    }
    void pop(){
        if(empty()){return;}
        if(topo->next == NULL){
            delete(topo);
            topo = NULL;
            return;
        }
        Node *aux = topo;
        topo = topo->next;
        delete(aux);
    }

    string peek(){
        if(empty()){
            printf("");
            return "";
        }
        return topo->value;
    }

    string reverteString(string palavra){
        for(char c : palavra){
            push(string (1, c));
        }
        string invertida;
        while (!empty()){
            invertida += peek();
            pop();
        }
        return invertida;
    }
};

int main(){
    Stack pilha;
    string palavra;

    printf("Digite palavras para inverter\n");

    while(cin >> palavra){

    pilha.reverteString(palavra);

    string invertida = pilha.reverteString(palavra);

    cout << "Palavra original: " << palavra << endl;
    cout << "Palavra invertida: " << invertida << endl;
    cout << "Para encerrar aperte CTRL+Z " << endl << endl ;

    }
    return 0;
}

