#include <stdio.h>

// Estrutura do n� da lista encadeada
struct No {
    int valor; // Valor armazenado no n�
    No* proximo; // Ponteiro para o pr�ximo n� na lista

    No() { // Construtor padr�o, inicializa o n� com valor 0 e pr�ximo como NULL
        valor = 0;
        proximo = NULL;
    }

    No(int _valor) { // Construtor que inicializa o n� com o valor fornecido e pr�ximo como NULL
        valor = _valor;
        proximo = NULL;
    }
};

// Estrutura da lista encadeada
struct Lista {
    No* primeiro; // Ponteiro para o primeiro n� da lista
    No* ultimo; // Ponteiro para o �ltimo n� da lista

    Lista() { // Construtor que inicializa uma lista vazia
        primeiro = NULL;
        ultimo = NULL;
    }

    bool vazia() { // Verifica se a lista est� vazia
        return primeiro == NULL;
    }

    // Fun��o para inserir um valor no final da lista
    void empurrarAtras(int valor) {
        No *n = new No(valor); // Cria um novo n� com o valor fornecido

        if (vazia()) { // Se a lista estiver vazia, o novo n� se torna o primeiro e o �ltimo
            primeiro = n;
            ultimo = n;
            return;
        }
        // Caso contr�rio, o �ltimo n� atual aponta para o novo n�, e o novo n� se torna o �ltimo
        ultimo->proximo = n;
        ultimo = n;
    }

    // Fun��o para encontrar o menor valor e sua posi��o na lista
    void menorValorPosicao(){
        if(vazia()){ // Verifica se a lista est� vazia
            printf("A Lista esta vazia.\n");
            return;
        }
        int menorValor = primeiro->valor; // Inicializa menorValor com o valor do primeiro n�
        int posicaoMenor = 0; // Inicializa posicaoMenor como 0 (posi��o do primeiro n�)
        int posicaoAtual = 0; // Vari�vel para acompanhar a posi��o atual durante a itera��o
        No *atual = primeiro; // Ponteiro para percorrer a lista, iniciando do primeiro n�

        // Percorre a lista at� o final
        while(atual != NULL){
            if(atual->valor < menorValor){ // Se o valor do n� atual for menor que menorValor
                menorValor = atual->valor; // Atualiza menorValor
                posicaoMenor = posicaoAtual; // Atualiza posicaoMenor com a posi��o atual
            }
            atual = atual->proximo; // Move para o pr�ximo n�
            posicaoAtual++; // Incrementa a posi��o atual
        }
        // Imprime o menor valor encontrado e sua posi��o
        printf("Menor valor: %d\n", menorValor);
        printf("Posicao: %d", posicaoMenor);
    }
};

int main () {
    Lista l; // Cria uma lista encadeada
    int n; // Vari�vel para armazenar o n�mero de elementos

    scanf("%d", &n); // L� o valor de n

    // Loop para ler e inserir n valores na lista
    for(int i = 0; i < n; i++){
        int valor;
        scanf("%d", &valor); // L� o valor do elemento
        l.empurrarAtras(valor); // Insere o valor no final da lista
    }

    l.menorValorPosicao(); // Chama a fun��o para encontrar e exibir o menor valor e sua posi��o

    return 0;
}
