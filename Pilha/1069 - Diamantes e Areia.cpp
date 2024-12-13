#include <iostream>
#include <string>

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

    string top(){
        if(empty()){
            return "";
        }
        return topo->value;
    }

    int verificarDiamantes(string sequencia){
        int cont = 0;
        for(char c : sequencia){
            if(c == '<'){
                push(string (1, c));
            }else if (c == '>'){
                if(!empty()){
                    pop();
                    cont++;
                }
            }
        }
        return cont;
    }

    void limpar(){
        while(!empty()){
            pop();
        }
    }
};

int main(){

    Stack pilha;
    string sequencia;
    int vezes;

    cin >> vezes;

    for(int i=0; i<vezes; i++){
        cin >> sequencia;
        cout << pilha.verificarDiamantes(sequencia) << endl;

        pilha.limpar();
    }

    return 0;
}
