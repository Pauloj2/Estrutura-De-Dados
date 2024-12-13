#include <iostream>

using namespace std;

// Estrutura de n� da lista encadeada
struct No {
    char valor;
    No* prox;

    // Construtor padr�o
    No() {
        valor = 0;
        prox = NULL;
    }

    // Construtor com valor inicial
    No(char _valor) {
        valor = _valor;
        prox = NULL;
    }
};

// Estrutura da fila
struct Fila {
    No* inicio;
    No* fim;
    int n;

    // Construtor padr�o
    Fila() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    // M�todo para enfileirar um valor
    void enfileirar(char valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
        n++;
    }

    // M�todo para desenfileirar um valor
    void desenfileirar() {
        if (n == 0) return;
        No* aux = inicio;
        inicio = inicio->prox;
        delete aux;
        n--;
        if (n == 0) fim = NULL;
    }

    // M�todo para pegar o valor na frente da fila
    char frente() {
        if (inicio == NULL) return '0';
        return inicio->valor;
    }
};

// Estrutura da pilha
struct Pilha {
    No* topo;
    int n;

    // Construtor padr�o
    Pilha() {
        topo = NULL;
        n = 0;
    }

    // M�todo para inserir um valor na pilha
    void inserir(char valor) {
        No* novo = new No(valor);
        novo->prox = topo;
        topo = novo;
        n++;
    }

    // M�todo para remover um valor da pilha
    void remover() {
        if (n == 0) return;
        No* aux = topo;
        topo = topo->prox;
        delete aux;
        n--;
    }

    // M�todo para pegar o valor no topo da pilha
    char topoPilha() {
        if (topo == NULL) return '0';
        return topo->valor;
    }

    // M�todo para limpar a pilha
    void limpar() {
        while (topo != NULL) {
            remover();
        }
    }

    // M�todo para restaurar a pilha a partir de uma pilha tempor�ria e uma fila
    void restaurarPilha(Pilha& tempPilha, Fila& tempFila) {
        // Transferir valores da pilha tempor�ria para a pilha original
        while (tempPilha.n > 0) {
            inserir(tempPilha.topoPilha());
            tempPilha.remover();
        }
        // Transferir valores da fila tempor�ria para a pilha original
        while (tempFila.n > 0) {
            inserir(tempFila.frente());
            tempFila.desenfileirar();
        }
    }
};

int receberam = 0; // Contador global de brindes recebidos

// Fun��o para reiniciar a pilha com a sequ�ncia FACE
void reiniciaPilha(Pilha& p) {
    p.limpar();
    p.inserir('F');
    p.inserir('A');
    p.inserir('C');
    p.inserir('E');
}

// Fun��o para comparar a pilha e a fila e determinar se o visitante ganha um brinde
void comparaPilhaFila(Pilha& p, Fila& f) {
    Pilha tempPilha; // Pilha tempor�ria para backup
    Fila tempFila; // Fila tempor�ria para backup
    bool verifica = true;

    // Verificar se as 4 letras da pilha correspondem �s 4 letras da fila
    for (int i = 0; i < 4; ++i) {
        if (p.n == 0 || f.n == 0 || p.topoPilha() != f.frente()) {
            verifica = false;
            break;
        }
        tempPilha.inserir(p.topoPilha());
        p.remover();
        tempFila.enfileirar(f.frente());
        f.desenfileirar();
    }

    // Se as letras correspondem, incrementar o contador de brindes
    if (verifica) {
        receberam++;
        // Se a pilha ficou vazia, reiniciar com FACE
        if (p.n == 0) {
            reiniciaPilha(p);
        }
    } else {
        // Se n�o correspondem, restaurar a pilha e a fila originais
        while (f.n > 0) {
            tempFila.enfileirar(f.frente());
            f.desenfileirar();
        }
        p.restaurarPilha(tempPilha, tempFila);
    }
}

int main() {
    int n;
    cin >> n;

    Pilha p;
    reiniciaPilha(p);

    // Processar cada visitante
    while (n--) {
        Fila f;
        // Ler as 4 letras do visitante
        for (int i = 0; i < 4; ++i) {
            char l;
            cin >> l;
            f.enfileirar(l);
        }
        // Comparar a pilha e a fila
        comparaPilhaFila(p, f);
    }

    // Imprimir o n�mero de brindes recebidos
    cout << receberam << endl;

    return 0;
}
