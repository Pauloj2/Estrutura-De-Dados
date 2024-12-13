#include <stdio.h>
#include <iostream>
#include <string>

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

struct Stack{

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
        if(empty()){
            return;
        }
        if(topo->next == NULL){
            delete topo;
            topo = NULL;
            return;
        }
        Node *aux = topo;
        topo = topo->next;
        delete(aux);
    }

    int top(){
        if(empty()){
            return -1;
        }
        return topo->value;
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

    int front(){
        if(empty()){return -1;}
        return first->value;
    }
};

struct PriorityQueue{

    Node *head;

    PriorityQueue(){
        head = NULL;
    }

    bool empty(){
        return head == NULL;
    }

    void insert(int value){
        Node *aux = new Node(value);
        if(empty() || value > head->value){
            aux->next = head;
            head = aux;
        }else{
            Node *paraPercorrer = head;
            while(paraPercorrer->next != NULL && paraPercorrer->next->value >= value){
                paraPercorrer = paraPercorrer->next;
            }
            aux->next = paraPercorrer->next;
            paraPercorrer->next = aux;
        }
    }

    void remove(){
        if(empty()){
            return;
        }
        Node *aux = head;
        head = head->next;
        delete(aux);
    }

    int top(){
        if(empty()){
            return -1;
        }
        return head->value;
    }
};

int main(){

    int n;
    int comando, x;

    while(scanf("%d", &n) != EOF){
        Stack p;
        Queue f;
        PriorityQueue fp;

        bool verifStack = true;
        bool verifQueue = true;
        bool verifPrior = true;

        while(n--){
            scanf("%d %d", &comando, &x);

            if(comando == 1){
                if(verifStack){p.push(x);}
                if(verifQueue){f.enqueue(x);}
                if(verifPrior){fp.insert(x);}

            }else if(comando == 2){
                if(verifStack){
                    if(p.top() == x){
                        p.pop();
                    }else{verifStack = false;}
                }
                if(verifQueue){
                    if(f.front() == x){
                        f.dequeue();
                    }else{verifQueue = false;}
                }
                if(verifPrior){
                    if(fp.top() == x){
                        fp.remove();
                    }else{
                        verifPrior = false;
                    }
                }
            }
        }
        int valid = 0;
        if(verifStack)valid++;
        if(verifQueue)valid++;
        if(verifPrior)valid++;

        if(valid == 0){
            printf("impossible\n");
        }else if(valid >= 2){
            printf("not sure\n");
        }else if(valid == 1){
            if(verifStack){
                printf("stack\n");
            }else if(verifQueue){
                printf("queue\n");
            }else if(verifPrior){
                printf("priority queue\n");
            }
        }
    }
    return 0;
}
