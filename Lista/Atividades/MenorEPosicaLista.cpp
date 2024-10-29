#include <stdio.h>

// Estrutura do nó da lista encadeada
struct No {
    int valor; // Valor armazenado no nó
    No* proximo; // Ponteiro para o próximo nó na lista

    No() { // Construtor padrão, inicializa o nó com valor 0 e próximo como NULL
        valor = 0;
        proximo = NULL;
    }

    No(int _valor) { // Construtor que inicializa o nó com o valor fornecido e próximo como NULL
        valor = _valor;
        proximo = NULL;
    }
};

// Estrutura da lista encadeada
struct Lista {
    No* primeiro; // Ponteiro para o primeiro nó da lista
    No* ultimo; // Ponteiro para o último nó da lista

    Lista() { // Construtor que inicializa uma lista vazia
        primeiro = NULL;
        ultimo = NULL;
    }

    bool vazia() { // Verifica se a lista está vazia
        return primeiro == NULL;
    }

    // Função para inserir um valor no final da lista
    void empurrarAtras(int valor) {
        No *n = new No(valor); // Cria um novo nó com o valor fornecido

        if (vazia()) { // Se a lista estiver vazia, o novo nó se torna o primeiro e o último
            primeiro = n;
            ultimo = n;
            return;
        }
        // Caso contrário, o último nó atual aponta para o novo nó, e o novo nó se torna o último
        ultimo->proximo = n;
        ultimo = n;
    }

    // Função para encontrar o menor valor e sua posição na lista
    void menorValorPosicao(){
        if(vazia()){ // Verifica se a lista está vazia
            printf("A Lista esta vazia.\n");
            return;
        }
        int menorValor = primeiro->valor; // Inicializa menorValor com o valor do primeiro nó
        int posicaoMenor = 0; // Inicializa posicaoMenor como 0 (posição do primeiro nó)
        int posicaoAtual = 0; // Variável para acompanhar a posição atual durante a iteração
        No *atual = primeiro; // Ponteiro para percorrer a lista, iniciando do primeiro nó

        // Percorre a lista até o final
        while(atual != NULL){
            if(atual->valor < menorValor){ // Se o valor do nó atual for menor que menorValor
                menorValor = atual->valor; // Atualiza menorValor
                posicaoMenor = posicaoAtual; // Atualiza posicaoMenor com a posição atual
            }
            atual = atual->proximo; // Move para o próximo nó
            posicaoAtual++; // Incrementa a posição atual
        }
        // Imprime o menor valor encontrado e sua posição
        printf("Menor valor: %d\n", menorValor);
        printf("Posicao: %d", posicaoMenor);
    }
};

int main () {
    Lista l; // Cria uma lista encadeada
    int n; // Variável para armazenar o número de elementos

    scanf("%d", &n); // Lê o valor de n

    // Loop para ler e inserir n valores na lista
    for(int i = 0; i < n; i++){
        int valor;
        scanf("%d", &valor); // Lê o valor do elemento
        l.empurrarAtras(valor); // Insere o valor no final da lista
    }

    l.menorValorPosicao(); // Chama a função para encontrar e exibir o menor valor e sua posição

    return 0;
}
