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
} ;

struct Stack{

    Node *topo;

    Stack(){
        topo = NULL;
    }

    bool empty(){
        return topo == NULL;
    }

    void push(string palavra){
        Node *aux = new Node(palavra);
        if(empty()){
            topo = aux;
            return;
        }
        aux->next = topo;
        topo = aux;
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

    bool verificarParenteses(string sequencia){
        for(char c : sequencia){
            if(c == '('){
                push(string (1, c));
            }else if(c == ')'){
                if(empty()){
                    return false;
                }
                pop();
            }
        }
        return empty();
    }
};

int main() {

    Stack pilha;
    string sequencia;

    printf("Digite as sequencias para ser verificadas\n");

    while (cin >> sequencia){
        if(pilha.verificarParenteses(sequencia)){
            cout << "Balanceada" << endl;
        }else{
            cout << "Nao balanceada" << endl;
        }
        cout << "Para encerrar aperte CTRL+Z e Enter " << endl << endl ;
    }
}
