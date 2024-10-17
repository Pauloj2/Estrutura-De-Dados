#include<stdio.h>


struct Node {

    int value;
    Node* next;

    Node() {
        value = 0;
        next = NULL;
    }

    Node(int _value) {
        value = _value;
        next = NULL;
    }

};

struct List {

    Node* first;
    Node* last;

    List() {
        first = NULL;
        last = NULL;
    }


    bool empty() {
        return first == NULL;
    }

    void pushFront(int value) {
        Node *n = new Node(value);
        if (empty()) {
            first = n;
            last = n;
            return;
        }
        n->next = first;
        first = n;
    }

    void pushBack(int value) {
        Node *n = new Node(value);
        if (empty()) {
            first = n;
            last = n;
            return;
        }
        last->next = n;
        last = n;
    }

    void print() {
        Node* aux = first;
        while (aux != NULL) {
            printf("%d -> ", aux->value);
            aux = aux->next;
        }
    }

};

int main() {

    List l;

    l.pushFront(10);
    l.pushFront(20);
    l.pushFront(30);
    l.pushBack(30);
    l.pushBack(50);
    l.print();

    return 0;
}
