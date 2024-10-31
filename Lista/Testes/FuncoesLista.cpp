#include <stdio.h>
#include <stdlib.h>

// Define uma estrutura chamada No para representar um nó da lista encadeada
struct No {
    int valor;       // Armazena o valor inteiro do nó
    No* proximo;     // Ponteiro que aponta para o próximo nó na lista

    // Construtor que inicializa o nó com um valor e define proximo como NULL
    No(int _valor = 0) {
        valor = _valor;
        proximo = NULL;
    }
};

// Define a estrutura Lista para representar a lista encadeada
struct Lista {
    No* primeiro;   // Ponteiro para o primeiro nó da lista
    No* ultimo;     // Ponteiro para o último nó da lista
    int contagem;   // Contador de nós na lista

    // Construtor que inicializa uma lista vazia
    Lista() {
        primeiro = NULL;
        ultimo = NULL;
        contagem = 0;
    }

    // Verifica se a lista está vazia
    bool vazia() {
        return primeiro == NULL;
    }

    // Insere um valor no início da lista
    void empurrarFrente(int valor) {
        No* n = new No(valor);    // Cria um novo nó com o valor fornecido
        contagem++;               // Incrementa o contador de nós

        if (vazia()) {             // Se a lista estiver vazia, o novo nó se torna o primeiro e o último
            primeiro = n;
            ultimo = n;
            return;
        }
        n->proximo = primeiro;    // Caso contrário, o novo nó aponta para o nó atual no início
        primeiro = n;             // E então se torna o primeiro nó da lista
    }

    // Insere um valor no final da lista
    void empurrarAtras(int valor) {
        No* n = new No(valor);    // Cria um novo nó com o valor fornecido
        contagem++;               // Incrementa o contador de nós

        if (vazia()) {            // Se a lista estiver vazia, o novo nó se torna o primeiro e o último
            primeiro = n;
            ultimo = n;
            return;
        }
        ultimo->proximo = n;      // O último nó atualiza seu ponteiro para apontar para o novo nó
        ultimo = n;               // O novo nó se torna o último nó da lista
    }

    // Imprime todos os valores da lista encadeada
    void imprimir() {
        No* aux = primeiro;       // Ponteiro auxiliar que percorre a lista a partir do primeiro nó

        while (aux != NULL) {     // Continua até o fim da lista
            printf("%d -> ", aux->valor);   // Imprime o valor do nó atual
            aux = aux->proximo;            // Move para o próximo nó
        }
        printf("NULL\n");         // Imprime "NULL" ao final para indicar o término da lista
    }

    // Função 1: Buscar Elemento - Retorna a posição do elemento se encontrado
    int buscarElemento(int valor) {
        No* aux = primeiro;       // Ponteiro auxiliar que percorre a lista
        int posicao = 0;          // Variável para contar a posição atual na lista

        while (aux != NULL) {     // Continua até o fim da lista
            if (aux->valor == valor) {   // Verifica se o valor do nó é o valor procurado
                return posicao;          // Retorna a posição se encontrado
            }
            aux = aux->proximo;   // Move para o próximo nó
            posicao++;            // Incrementa a posição
        }
        return -1;                // Retorna -1 se o valor não foi encontrado
    }

    // Função 2: Inserção Ordenada - Insere valor mantendo a lista ordenada
    void inserirOrdenado(int valor) {
        No* n = new No(valor);    // Cria um novo nó com o valor fornecido
        contagem++;               // Incrementa o contador de nós

        if (vazia() || primeiro->valor >= valor) {   // Insere no início se a lista está vazia ou o valor é menor
            n->proximo = primeiro;
            primeiro = n;
            if (ultimo == NULL) ultimo = n; // Se a lista estava vazia, ajusta o ponteiro ultimo
            return;
        }

        No* atual = primeiro;    // Ponteiro auxiliar para encontrar a posição correta para inserir o valor
        while (atual->proximo != NULL && atual->proximo->valor < valor) {
            atual = atual->proximo;   // Move para o próximo nó até encontrar onde o valor se encaixa
        }

        n->proximo = atual->proximo;  // Ajusta o ponteiro do novo nó
        atual->proximo = n;           // Insere o nó após "atual"

        if (n->proximo == NULL) ultimo = n;   // Atualiza o ponteiro ultimo se o novo nó for o último
    }

    // Função 3: Reverter Lista Encadeada - Inverte a ordem da lista
    void reverter() {
        No* anterior = NULL;    // Ponteiro que mantém o nó anterior ao atual
        No* atual = primeiro;   // Ponteiro que percorre a lista
        No* proximo = NULL;     // Ponteiro para armazenar o próximo nó
        ultimo = primeiro;      // Define o antigo primeiro nó como último

        while (atual != NULL) {   // Continua até o fim da lista
            proximo = atual->proximo;  // Armazena o próximo nó
            atual->proximo = anterior; // Inverte o ponteiro do nó atual para o nó anterior
            anterior = atual;          // Move "anterior" e "atual" para o próximo nó
            atual = proximo;
        }
        primeiro = anterior;      // Define o último "anterior" como o novo primeiro
    }

    // Função 4: Remover Duplicatas - Remove nós com valores duplicados
    void removerDuplicatas() {
        No* atual = primeiro;     // Ponteiro que percorre a lista

        while (atual != NULL && atual->proximo != NULL) {   // Continua até o penúltimo nó
            No* comparador = atual;   // Ponteiro para comparar nós subsequentes
            while (comparador->proximo != NULL) {
                if (atual->valor == comparador->proximo->valor) {   // Se o valor é duplicado
                    No* temp = comparador->proximo;  // Armazena o nó duplicado
                    comparador->proximo = comparador->proximo->proximo;  // Remove o nó duplicado
                    delete temp;                     // Libera memória do nó duplicado
                    contagem--;                      // Decrementa o contador
                } else {
                    comparador = comparador->proximo;   // Move para o próximo nó
                }
            }
            atual = atual->proximo;   // Move para o próximo nó para continuar a verificação
        }
    }

    // Função 5: Encontrar o Elemento do Meio - Retorna o nó do meio
    No* encontrarElementoDoMeio() {
        if (vazia()) return NULL;   // Retorna NULL se a lista está vazia

        No* lento = primeiro;   // Ponteiro lento que avança uma posição por vez
        No* rapido = primeiro;  // Ponteiro rápido que avança duas posições por vez

        while (rapido != NULL && rapido->proximo != NULL) {
            lento = lento->proximo;            // Avança uma posição
            rapido = rapido->proximo->proximo; // Avança duas posições
        }
        return lento;   // Quando rápido atinge o final, lento estará no meio
    }
     void removerKesimoDoFinal(int k) {
        if (vazia() || k <= 0 || k > contagem) {
            printf("Posição inválida ou lista vazia.\n");
            return;
        }

        int posicaoAlvo = contagem - k; // Calcula a posição do elemento a partir do início
        if (posicaoAlvo == 0) {
            // Se for o primeiro elemento, chamamos a função para remover o primeiro
            No* paraDeletar = primeiro;
            primeiro = primeiro->proximo;
            delete paraDeletar;
            contagem--;
            return;
        }

        // Caso contrário, percorre até o nó anterior ao que será removido
        No* aux = primeiro;
        for (int i = 0; i < posicaoAlvo - 1; i++) {
            aux = aux->proximo;
        }

        No* paraDeletar = aux->proximo;
        aux->proximo = paraDeletar->proximo;
        if (paraDeletar == ultimo) {
            ultimo = aux; // Atualiza o último se necessário
        }
        delete paraDeletar;
        contagem--;
    }

    // Função para concatenar duas listas encadeadas
    void concatenar(Lista& outraLista) {
        if (outraLista.vazia()) return; // Se a outra lista está vazia, não faz nada

        if (vazia()) {
            // Se a lista atual está vazia, a outra lista se torna a lista atual
            primeiro = outraLista.primeiro;
            ultimo = outraLista.ultimo;
        } else {
            // Caso contrário, conecta o último nó da lista atual ao primeiro da outra
            ultimo->proximo = outraLista.primeiro;
            ultimo = outraLista.ultimo; // Atualiza o último nó da lista atual
        }

        contagem += outraLista.contagem; // Atualiza a contagem de nós
        // Opcionalmente, podemos "esvaziar" a outra lista
        outraLista.primeiro = NULL;
        outraLista.ultimo = NULL;
        outraLista.contagem = 0;
    }
};

int main() {
    Lista l;

    // Adiciona valores à lista
    l.empurrarAtras(10);
    l.empurrarAtras(3);
    l.empurrarAtras(5);
    l.empurrarAtras(8);
    l.empurrarAtras(10);
    l.empurrarAtras(3);

    printf("Lista inicial:\n");
    l.imprimir();

    // Testa a função de busca
    printf("\nBusca pelo valor 5: ");
    int posicao = l.buscarElemento(5);
    if (posicao != -1) {
        printf("Encontrado na posicao %d\n", posicao);
    } else {
        printf("Não encontrado\n");
    }

    // Testa a função de inserção ordenada
    printf("\nInsercao ordenada de 4:\n");
    l.inserirOrdenado(4);
    l.imprimir();

    // Testa a função de reversão da lista
    printf("\nRevertendo a lista:\n");
    l.reverter();
    l.imprimir();

    // Testa a função de remoção de duplicatas
    printf("\nRemovendo duplicatas:\n");
    l.removerDuplicatas();
    l.imprimir();

    // Testa a função de encontrar o elemento do meio
    printf("\nElemento do meio: ");
    No* meio = l.encontrarElementoDoMeio();
    if (meio != NULL) {
        printf("%d\n", meio->valor);
    } else {
        printf("Lista vazia\n");
    }

     Lista l1;
    l1.empurrarAtras(1);
    l1.empurrarAtras(2);
    l1.empurrarAtras(3);
    l1.empurrarAtras(4);
    l1.empurrarAtras(5);

    printf("Lista original:\n");
    l1.imprimir();

    printf("\nRemovendo o 2-ésimo elemento do final:\n");
    l1.removerKesimoDoFinal(2); // Remove o 2º elemento a partir do final
    l1.imprimir();

     Lista l2;
    l2.empurrarAtras(6);
    l2.empurrarAtras(7);
    l2.empurrarAtras(8);

    printf("\nLista a ser concatenada:\n");
    l2.imprimir();

    printf("\nConcatenando listas:\n");
    l1.concatenar(l2); // Concatena l2 no final de l1
    l1.imprimir();

    return 0;
}
