#include <iostream>
#include <string>
#include <algorithm> // Para usar std::reverse

using namespace std;

struct Node {
    char value;
    Node *next;

    Node(char _value) : value(_value), next(NULL) {}
};

struct Stack {
    Node *topo;

    Stack() : topo(NULL) {}

    bool empty() {
        return topo == NULL;
    }

    void push(char value) {
        Node *aux = new Node(value);
        aux->next = topo;
        topo = aux;
    }

    void pop() {
        if (empty()) return;
        Node *aux = topo;
        topo = topo->next;
        delete aux;
    }

    char peek() {
        return empty() ? '\0' : topo->value;
    }

    ~Stack() {
        while (!empty()) pop(); // Libera memória ao destruir a pilha
    }
};

string removeConsecutiveDuplicates(const string &input) {
    Stack pilha;

    for (char c : input) {
        if (!pilha.empty() && pilha.peek() == c) {
            pilha.pop();
        } else {
            pilha.push(c);
        }
    }

    string resultado;
    while (!pilha.empty()) {
        resultado += pilha.peek();
        pilha.pop();
    }

    reverse(resultado.begin(), resultado.end()); // Inverter para a ordem correta
    return resultado;
}

int main() {
    string entrada;
    cout << "Este programa remove caracteres duplicados consecutivos de uma string." << endl;

    while (true) {
        cout << "Digite a string (ou 'sair' para encerrar): ";
        cin >> entrada;

        if (entrada == "sair") break;

        string resultado = removeConsecutiveDuplicates(entrada);
        cout << "Resultado: " << resultado << endl;
    }

    cout << "Programa encerrado." << endl;
    return 0;
}
