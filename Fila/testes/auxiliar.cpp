#include <iostream>  // Inclusão da biblioteca para entrada e saída de dados

using namespace std;  // Usando o namespace padrão para evitar a necessidade de escrever std:: antes das funções e tipos da biblioteca padrão.

struct No {
    int valor;  // A estrutura "No" armazena o valor do elemento da fila
    No* prox;  // Um ponteiro para o próximo nó da fila (para formar a lista encadeada)

    No() {  // Construtor padrão
        valor = 0;  // Inicializa o valor como 0
        prox = NULL;  // Inicializa o ponteiro "prox" como NULL
    }

    No(int _valor) {  // Construtor com valor
        valor = _valor;  // Inicializa o valor com o valor fornecido
        prox = NULL;  // Inicializa o ponteiro "prox" como NULL
    }
};

struct Fila {
    No* inicio;  // Ponteiro para o primeiro nó da fila
    No* fim;  // Ponteiro para o último nó da fila
    int n;  // Variável que armazena o número de elementos na fila

    Fila() {  // Construtor da fila
        inicio = NULL;  // Inicializa o ponteiro "inicio" como NULL (fila vazia)
        fim = NULL;  // Inicializa o ponteiro "fim" como NULL
        n = 0;  // Inicializa o número de elementos como 0
    }

    void enfileirar(int valor) {  // Função para adicionar um novo elemento à fila
        No* novo = new No(valor);  // Cria um novo nó com o valor fornecido
        if (inicio == NULL) {  // Se a fila estiver vazia
            inicio = novo;  // O primeiro nó é o novo nó
            fim = novo;  // O último nó também é o novo nó
        } else {
            fim->prox = novo;  // O último nó aponta para o novo nó
            fim = novo;  // O último nó agora é o novo nó
        }
        n++;  // Incrementa o número de elementos na fila
    }

    void desenfileirar() {  // Função para remover um elemento da fila
        if (n == 0) return;  // Se a fila estiver vazia, não faz nada
        if (n == 1) {  // Se houver apenas um elemento na fila
            delete(inicio);  // Apaga o único nó
            inicio = NULL;  // A fila agora está vazia
            fim = NULL;  // A fila agora está vazia
            n = 0;  // O número de elementos agora é 0
            return;
        }
        No* aux = inicio;  // Cria um ponteiro auxiliar para o primeiro nó
        inicio = inicio->prox;  // O ponteiro "inicio" passa a apontar para o segundo nó
        delete(aux);  // Deleta o antigo primeiro nó
        n--;  // Decrementa o número de elementos
    }

    int frente() {  // Função para obter o valor do primeiro elemento da fila
        if (inicio == NULL) return 0;  // Se a fila estiver vazia, retorna 0 (valor arbitrário)
        return inicio->valor;  // Retorna o valor do primeiro nó
    }

    void copiarPara(Fila& dest) {  // Função para copiar todos os elementos da fila atual para outra fila
        No* aux = inicio;  // Cria um ponteiro auxiliar para o primeiro nó da fila atual
        while (aux != NULL) {  // Enquanto houver elementos na fila
            dest.enfileirar(aux->valor);  // Adiciona o valor do nó atual na fila de destino
            aux = aux->prox;  // Avança para o próximo nó
        }
    }

    void ordenarDecrescente() {  // Função para ordenar a fila em ordem decrescente
        if (!inicio) return;  // Se a fila estiver vazia, não faz nada

        bool trocado;  // Variável para verificar se houve troca durante a ordenação
        No* atual;  // Ponteiro para percorrer a fila
        No* ultimo = NULL;  // Ponteiro para marcar o último nó já ordenado

        do {
            trocado = false;  // Inicializa a variável trocado como falso (não houve troca ainda)
            atual = inicio;  // Começa a percorrer a fila a partir do primeiro nó

            while (atual->prox != ultimo) {  // Enquanto não chegar no último nó já ordenado
                if (atual->valor < atual->prox->valor) {  // Se o valor do nó atual for menor que o do próximo
                    swap(atual->valor, atual->prox->valor);  // Troca os valores dos nós
                    trocado = true;  // Marca que houve uma troca
                }
                atual = atual->prox;  // Avança para o próximo nó
            }
            ultimo = atual;  // O último nó já está ordenado
        } while (trocado);  // Repete enquanto houver trocas
    }

    int contarInalterados(Fila& ordenada) {  // Função para contar quantos elementos não mudaram de posição após ordenação
        No* auxOriginal = inicio;  // Ponteiro para percorrer a fila original
        No* auxOrdenada = ordenada.inicio;  // Ponteiro para percorrer a fila ordenada
        int cont = 0;  // Variável para contar os elementos que não mudaram de posição

        while (auxOriginal != NULL && auxOrdenada != NULL) {  // Enquanto houver elementos em ambas as filas
            if (auxOriginal->valor == auxOrdenada->valor) {  // Se o valor na fila original for igual ao valor na fila ordenada
                cont++;  // Incrementa o contador
            }
            auxOriginal = auxOriginal->prox;  // Avança para o próximo nó na fila original
            auxOrdenada = auxOrdenada->prox;  // Avança para o próximo nó na fila ordenada
        }

        return cont;  // Retorna o número de elementos que não mudaram de posição
    }
};

int main() {
    int n;  // Número de casos de teste
    cin >> n;  // Lê o número de casos de teste

    for (int i = 0; i < n; i++) {  // Loop para processar cada caso de teste
        int m;  // Número de pessoas na fila
        cin >> m;  // Lê o número de pessoas na fila

        Fila fOriginal;  // Fila para armazenar os elementos originais
        Fila fOrdenada;  // Fila para armazenar os elementos ordenados

        for (int j = 0; j < m; j++) {  // Loop para ler os elementos da fila
            int x;  // Identificador de cada pessoa
            cin >> x;  // Lê o valor (identificador da pessoa)
            fOriginal.enfileirar(x);  // Adiciona a pessoa à fila original
        }

        // Copiar os valores originais para a lista ordenada
        fOriginal.copiarPara(fOrdenada);  // Copia os elementos da fila original para a fila ordenada

        // Ordenar a lista ordenada
        fOrdenada.ordenarDecrescente();  // Ordena a fila de forma decrescente

        // Contar quantos elementos não mudaram de posição
        int inalterados = fOriginal.contarInalterados(fOrdenada);  // Conta os elementos inalterados

        cout << inalterados << endl;  // Imprime o número de elementos inalterados
    }

    return 0;  // Fim do programa
}
