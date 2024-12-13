#include <iostream>  // Inclus�o da biblioteca para entrada e sa�da de dados

using namespace std;  // Usando o namespace padr�o para evitar a necessidade de escrever std:: antes das fun��es e tipos da biblioteca padr�o.

struct No {
    int valor;  // A estrutura "No" armazena o valor do elemento da fila
    No* prox;  // Um ponteiro para o pr�ximo n� da fila (para formar a lista encadeada)

    No() {  // Construtor padr�o
        valor = 0;  // Inicializa o valor como 0
        prox = NULL;  // Inicializa o ponteiro "prox" como NULL
    }

    No(int _valor) {  // Construtor com valor
        valor = _valor;  // Inicializa o valor com o valor fornecido
        prox = NULL;  // Inicializa o ponteiro "prox" como NULL
    }
};

struct Fila {
    No* inicio;  // Ponteiro para o primeiro n� da fila
    No* fim;  // Ponteiro para o �ltimo n� da fila
    int n;  // Vari�vel que armazena o n�mero de elementos na fila

    Fila() {  // Construtor da fila
        inicio = NULL;  // Inicializa o ponteiro "inicio" como NULL (fila vazia)
        fim = NULL;  // Inicializa o ponteiro "fim" como NULL
        n = 0;  // Inicializa o n�mero de elementos como 0
    }

    void enfileirar(int valor) {  // Fun��o para adicionar um novo elemento � fila
        No* novo = new No(valor);  // Cria um novo n� com o valor fornecido
        if (inicio == NULL) {  // Se a fila estiver vazia
            inicio = novo;  // O primeiro n� � o novo n�
            fim = novo;  // O �ltimo n� tamb�m � o novo n�
        } else {
            fim->prox = novo;  // O �ltimo n� aponta para o novo n�
            fim = novo;  // O �ltimo n� agora � o novo n�
        }
        n++;  // Incrementa o n�mero de elementos na fila
    }

    void desenfileirar() {  // Fun��o para remover um elemento da fila
        if (n == 0) return;  // Se a fila estiver vazia, n�o faz nada
        if (n == 1) {  // Se houver apenas um elemento na fila
            delete(inicio);  // Apaga o �nico n�
            inicio = NULL;  // A fila agora est� vazia
            fim = NULL;  // A fila agora est� vazia
            n = 0;  // O n�mero de elementos agora � 0
            return;
        }
        No* aux = inicio;  // Cria um ponteiro auxiliar para o primeiro n�
        inicio = inicio->prox;  // O ponteiro "inicio" passa a apontar para o segundo n�
        delete(aux);  // Deleta o antigo primeiro n�
        n--;  // Decrementa o n�mero de elementos
    }

    int frente() {  // Fun��o para obter o valor do primeiro elemento da fila
        if (inicio == NULL) return 0;  // Se a fila estiver vazia, retorna 0 (valor arbitr�rio)
        return inicio->valor;  // Retorna o valor do primeiro n�
    }

    void copiarPara(Fila& dest) {  // Fun��o para copiar todos os elementos da fila atual para outra fila
        No* aux = inicio;  // Cria um ponteiro auxiliar para o primeiro n� da fila atual
        while (aux != NULL) {  // Enquanto houver elementos na fila
            dest.enfileirar(aux->valor);  // Adiciona o valor do n� atual na fila de destino
            aux = aux->prox;  // Avan�a para o pr�ximo n�
        }
    }

    void ordenarDecrescente() {  // Fun��o para ordenar a fila em ordem decrescente
        if (!inicio) return;  // Se a fila estiver vazia, n�o faz nada

        bool trocado;  // Vari�vel para verificar se houve troca durante a ordena��o
        No* atual;  // Ponteiro para percorrer a fila
        No* ultimo = NULL;  // Ponteiro para marcar o �ltimo n� j� ordenado

        do {
            trocado = false;  // Inicializa a vari�vel trocado como falso (n�o houve troca ainda)
            atual = inicio;  // Come�a a percorrer a fila a partir do primeiro n�

            while (atual->prox != ultimo) {  // Enquanto n�o chegar no �ltimo n� j� ordenado
                if (atual->valor < atual->prox->valor) {  // Se o valor do n� atual for menor que o do pr�ximo
                    swap(atual->valor, atual->prox->valor);  // Troca os valores dos n�s
                    trocado = true;  // Marca que houve uma troca
                }
                atual = atual->prox;  // Avan�a para o pr�ximo n�
            }
            ultimo = atual;  // O �ltimo n� j� est� ordenado
        } while (trocado);  // Repete enquanto houver trocas
    }

    int contarInalterados(Fila& ordenada) {  // Fun��o para contar quantos elementos n�o mudaram de posi��o ap�s ordena��o
        No* auxOriginal = inicio;  // Ponteiro para percorrer a fila original
        No* auxOrdenada = ordenada.inicio;  // Ponteiro para percorrer a fila ordenada
        int cont = 0;  // Vari�vel para contar os elementos que n�o mudaram de posi��o

        while (auxOriginal != NULL && auxOrdenada != NULL) {  // Enquanto houver elementos em ambas as filas
            if (auxOriginal->valor == auxOrdenada->valor) {  // Se o valor na fila original for igual ao valor na fila ordenada
                cont++;  // Incrementa o contador
            }
            auxOriginal = auxOriginal->prox;  // Avan�a para o pr�ximo n� na fila original
            auxOrdenada = auxOrdenada->prox;  // Avan�a para o pr�ximo n� na fila ordenada
        }

        return cont;  // Retorna o n�mero de elementos que n�o mudaram de posi��o
    }
};

int main() {
    int n;  // N�mero de casos de teste
    cin >> n;  // L� o n�mero de casos de teste

    for (int i = 0; i < n; i++) {  // Loop para processar cada caso de teste
        int m;  // N�mero de pessoas na fila
        cin >> m;  // L� o n�mero de pessoas na fila

        Fila fOriginal;  // Fila para armazenar os elementos originais
        Fila fOrdenada;  // Fila para armazenar os elementos ordenados

        for (int j = 0; j < m; j++) {  // Loop para ler os elementos da fila
            int x;  // Identificador de cada pessoa
            cin >> x;  // L� o valor (identificador da pessoa)
            fOriginal.enfileirar(x);  // Adiciona a pessoa � fila original
        }

        // Copiar os valores originais para a lista ordenada
        fOriginal.copiarPara(fOrdenada);  // Copia os elementos da fila original para a fila ordenada

        // Ordenar a lista ordenada
        fOrdenada.ordenarDecrescente();  // Ordena a fila de forma decrescente

        // Contar quantos elementos n�o mudaram de posi��o
        int inalterados = fOriginal.contarInalterados(fOrdenada);  // Conta os elementos inalterados

        cout << inalterados << endl;  // Imprime o n�mero de elementos inalterados
    }

    return 0;  // Fim do programa
}
