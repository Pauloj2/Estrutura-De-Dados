#include <stdio.h>
#include <iostream>

using namespace std;

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

struct Stack {

    Node *topo;

    Stack(){
        topo = NULL;
    }

    bool empty(){
        return topo == NULL;
    }

    void push(int value){
        Node *aux = new Node(value);
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

    int peek(){
        if(empty()){
            printf("Empty\n");
            return -1;
        }
        return topo->value;
    }

};

int main(){

    Stack pilha;

    int decimal, quociente, resto=0;

    printf("Digite os numeros decimal para converter\n");

    while(cin >> decimal){
        quociente = decimal;
        while(quociente != 0){
            resto = quociente%2;
            pilha.push(resto);
            quociente = quociente/2;
        }

        printf("Numero em Decimal: %d\n", decimal);
        printf("Numero em Binario: ");

        while(!pilha.empty()){
            printf("%d",pilha.peek());
            pilha.pop();
        }
        cout << endl << "Para encerrar aperte CTRL+Z e Enter ";
        printf("\n");
    }
    return 0;
}
