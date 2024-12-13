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

    Node* topo;

    Stack(){
        topo = NULL;
    }

    bool empty (){
        return topo == NULL;
    }

    void push(string value){
        Node *n = new Node(value);
        if(empty()){
            topo = n;
            return;
        }
        n->next = topo;
        topo = n;
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
        Node *aux = topo;
        topo = topo->next;
        delete(aux);
    }

    string top(){
        if(empty()){
            return "";
        }
        return topo->value;
    }

    bool verificacaoDeparenteses(string expressao){
        for(char c : expressao){
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

    void limpar(){
        while(!empty()){
            pop();
        }
    }
};

int main() {

    Stack pilha;
    string expressao;

    while(getline(cin, expressao)){
        pilha.limpar();
        if(pilha.verificacaoDeparenteses(expressao)){
            printf("correct\n");
        }else{
            printf("incorrect\n");
        }
    }
    return 0;
}

