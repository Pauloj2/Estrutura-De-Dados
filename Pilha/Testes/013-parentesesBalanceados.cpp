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

// Função para verificar se os parênteses estão balanceados
bool areParenthesesBalanced(string expr) {
    Stack s;

    // Percorre cada caractere na string
    for (char c : expr) {
        // Se for um parêntese de abertura, empilha
        if (c == '(' || c == '{' || c == '[') {
            string open(1, c); // Converte char para string
            s.push(open);
        }
        // Se for um parêntese de fechamento
        else if (c == ')' || c == '}' || c == ']') {
            // Se a pilha estiver vazia, não está balanceado
            if (s.empty()) {
                return false;
            }

            // Verifica correspondência entre o topo da pilha e o caractere atual
            string top = s.top();
            if ((c == ')' && top == "(") ||
                (c == '}' && top == "{") ||
                (c == ']' && top == "[")) {
                s.pop(); // Remove o par correspondente da pilha
            } else {
                return false; // Parêntese não correspondente
            }
        }
    }

    // Se a pilha estiver vazia no final, está balanceado
    return s.empty();
}

// Programa principal
int main() {
    string expr;

    // Solicitar entrada do usuário
    cout << "Digite a string contendo parênteses: ";
    cin >> expr;

    // Verificar se está balanceada e exibir resultado
    if (areParenthesesBalanced(expr)) {
        cout << "Saída: Válido." << endl;
    } else {
        cout << "Saída: Inválido." << endl;
    }

    return 0;
}
