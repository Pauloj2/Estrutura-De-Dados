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

// Fun��o para verificar se os par�nteses est�o balanceados
bool areParenthesesBalanced(string expr) {
    Stack s;

    // Percorre cada caractere na string
    for (char c : expr) {
        // Se for um par�ntese de abertura, empilha
        if (c == '(' || c == '{' || c == '[') {
            string open(1, c); // Converte char para string
            s.push(open);
        }
        // Se for um par�ntese de fechamento
        else if (c == ')' || c == '}' || c == ']') {
            // Se a pilha estiver vazia, n�o est� balanceado
            if (s.empty()) {
                return false;
            }

            // Verifica correspond�ncia entre o topo da pilha e o caractere atual
            string top = s.top();
            if ((c == ')' && top == "(") ||
                (c == '}' && top == "{") ||
                (c == ']' && top == "[")) {
                s.pop(); // Remove o par correspondente da pilha
            } else {
                return false; // Par�ntese n�o correspondente
            }
        }
    }

    // Se a pilha estiver vazia no final, est� balanceado
    return s.empty();
}

// Programa principal
int main() {
    string expr;

    // Solicitar entrada do usu�rio
    cout << "Digite a string contendo par�nteses: ";
    cin >> expr;

    // Verificar se est� balanceada e exibir resultado
    if (areParenthesesBalanced(expr)) {
        cout << "Sa�da: V�lido." << endl;
    } else {
        cout << "Sa�da: Inv�lido." << endl;
    }

    return 0;
}
