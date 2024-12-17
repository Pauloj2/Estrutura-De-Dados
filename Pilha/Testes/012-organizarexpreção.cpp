#include <iostream>
#include <string>
using namespace std;

// Estrutura do Node ajustada para strings
struct Node {
    string value;
    Node *next;

    Node() {
        value = "";
        next = NULL;
    }

    Node(string _value) {
        value = _value;
        next = NULL;
    }
};

// Estrutura da Pilha ajustada para strings
struct Stack {
    Node *topo;

    Stack() {
        topo = NULL;
    }

    bool empty() {
        return topo == NULL;
    }

    void push(string value) {
        Node *aux = new Node(value);
        if (empty()) {
            topo = aux;
            return;
        }
        aux->next = topo;
        topo = aux;
    }

    void pop() {
        if (empty()) {
            return;
        }
        if (topo->next == NULL) {
            delete topo;
            topo = NULL;
            return;
        }
        Node *aux = topo;
        topo = topo->next;
        delete (aux);
    }

    string top() {
        if (empty()) {
            return "";
        }
        return topo->value;
    }
};

// Fun��o para converter nota��o p�s-fixa para infixa
string postfixToInfix(string postfix) {
    Stack s;
    string operand1, operand2, result;

    for (char c : postfix) {
        // Ignorar espa�os
        if (c == ' ') {
            continue;
        }

        // Se for operando (n�mero ou letra), empilha
        if (isalnum(c)) {
            string operand(1, c); // Converter char para string
            s.push(operand);
        } else {
            // Se for operador, desempilha dois operandos
            operand2 = s.top();
            s.pop();
            operand1 = s.top();
            s.pop();

            // Monta a express�o infixa e empilha de volta
            result = "(" + operand1 + " " + c + " " + operand2 + ")";
            s.push(result);
        }
    }

    // O resultado final estar� no topo da pilha
    return s.top();
}

// Programa principal
int main() {
    string postfix;

    // Solicitar entrada do usu�rio
    cout << "Digite a express�o em nota��o p�s-fixa (separe os elementos com espa�os): ";
    getline(cin, postfix);

    // Exibir a express�o original e a convertida
    cout << "Express�o P�s-Fixa: " << postfix << endl;
    string infix = postfixToInfix(postfix);
    cout << "Express�o Infixa: " << infix << endl;

    return 0;
}
