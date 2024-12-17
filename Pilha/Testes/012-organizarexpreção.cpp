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

// Função para converter notação pós-fixa para infixa
string postfixToInfix(string postfix) {
    Stack s;
    string operand1, operand2, result;

    for (char c : postfix) {
        // Ignorar espaços
        if (c == ' ') {
            continue;
        }

        // Se for operando (número ou letra), empilha
        if (isalnum(c)) {
            string operand(1, c); // Converter char para string
            s.push(operand);
        } else {
            // Se for operador, desempilha dois operandos
            operand2 = s.top();
            s.pop();
            operand1 = s.top();
            s.pop();

            // Monta a expressão infixa e empilha de volta
            result = "(" + operand1 + " " + c + " " + operand2 + ")";
            s.push(result);
        }
    }

    // O resultado final estará no topo da pilha
    return s.top();
}

// Programa principal
int main() {
    string postfix;

    // Solicitar entrada do usuário
    cout << "Digite a expressão em notação pós-fixa (separe os elementos com espaços): ";
    getline(cin, postfix);

    // Exibir a expressão original e a convertida
    cout << "Expressão Pós-Fixa: " << postfix << endl;
    string infix = postfixToInfix(postfix);
    cout << "Expressão Infixa: " << infix << endl;

    return 0;
}
