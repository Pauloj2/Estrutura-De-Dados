#include <iostream>
#include <climits>

using namespace std;


struct No {
    int valor;
    No* prox;

    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }
};


struct Pilha {
    No* topo;
    No* topoMin;


    Pilha() {
        topo = NULL;
        topoMin = NULL;
    }


    void inserir(int valor) {
        No* novo = new No(valor);
        novo->prox = topo;
        topo = novo;


        if (topoMin == NULL || valor <= topoMin->valor) {
            No* novoMin = new No(valor);
            novoMin->prox = topoMin;
            topoMin = novoMin;
        }
    }


    void remover() {
        if (topo == NULL) {
            cout << "EMPTY\n";
            return;
        }

        No* aux = topo;
        topo = topo->prox;


        if (aux->valor == topoMin->valor) {
            No* auxMin = topoMin;
            topoMin = topoMin->prox;
            delete auxMin;
        }

        delete aux;
    }


    void menor() const {
        if (topoMin == NULL) {
            cout << "EMPTY\n";
            return;
        }
        cout << topoMin->valor << '\n';
    }
};

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    Pilha p;

    int n;
    cin >> n;

    while (n--) {
        string operacao;
        cin >> operacao;

        if (operacao == "PUSH") {
            int v;
            cin >> v;
            p.inserir(v);
        } else if (operacao == "POP") {
            p.remover();
        } else if (operacao == "MIN") {
            p.menor();
        }
    }

    return 0;
}
