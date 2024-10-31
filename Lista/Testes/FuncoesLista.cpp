#include <stdio.h>
#include <stdlib.h>

// Define uma estrutura chamada No para representar um n� da lista encadeada
struct No {
    int valor;       // Armazena o valor inteiro do n�
    No* proximo;     // Ponteiro que aponta para o pr�ximo n� na lista

    // Construtor que inicializa o n� com um valor e define proximo como NULL
    No(int _valor = 0) {
        valor = _valor;
        proximo = NULL;
    }
};

// Define a estrutura Lista para representar a lista encadeada
struct Lista {
    No* primeiro;   // Ponteiro para o primeiro n� da lista
    No* ultimo;     // Ponteiro para o �ltimo n� da lista
    int contagem;   // Contador de n�s na lista

    // Construtor que inicializa uma lista vazia
    Lista() {
        primeiro = NULL;
        ultimo = NULL;
        contagem = 0;
    }

    // Verifica se a lista est� vazia
    bool vazia() {
        return primeiro == NULL;
    }

    // Insere um valor no in�cio da lista
    void empurrarFrente(int valor) {
        No* n = new No(valor);    // Cria um novo n� com o valor fornecido
        contagem++;               // Incrementa o contador de n�s

        if (vazia()) {             // Se a lista estiver vazia, o novo n� se torna o primeiro e o �ltimo
            primeiro = n;
            ultimo = n;
            return;
        }
        n->proximo = primeiro;    // Caso contr�rio, o novo n� aponta para o n� atual no in�cio
        primeiro = n;             // E ent�o se torna o primeiro n� da lista
    }

    // Insere um valor no final da lista
    void empurrarAtras(int valor) {
        No* n = new No(valor);    // Cria um novo n� com o valor fornecido
        contagem++;               // Incrementa o contador de n�s

        if (vazia()) {            // Se a lista estiver vazia, o novo n� se torna o primeiro e o �ltimo
            primeiro = n;
            ultimo = n;
            return;
        }
        ultimo->proximo = n;      // O �ltimo n� atualiza seu ponteiro para apontar para o novo n�
        ultimo = n;               // O novo n� se torna o �ltimo n� da lista
    }

    // Imprime todos os valores da lista encadeada
    void imprimir() {
        No* aux = primeiro;       // Ponteiro auxiliar que percorre a lista a partir do primeiro n�

        while (aux != NULL) {     // Continua at� o fim da lista
            printf("%d -> ", aux->valor);   // Imprime o valor do n� atual
            aux = aux->proximo;            // Move para o pr�ximo n�
        }
        printf("NULL\n");         // Imprime "NULL" ao final para indicar o t�rmino da lista
    }

    // Fun��o 1: Buscar Elemento - Retorna a posi��o do elemento se encontrado
    int buscarElemento(int valor) {
        No* aux = primeiro;       // Ponteiro auxiliar que percorre a lista
        int posicao = 0;          // Vari�vel para contar a posi��o atual na lista

        while (aux != NULL) {     // Continua at� o fim da lista
            if (aux->valor == valor) {   // Verifica se o valor do n� � o valor procurado
                return posicao;          // Retorna a posi��o se encontrado
            }
            aux = aux->proximo;   // Move para o pr�ximo n�
            posicao++;            // Incrementa a posi��o
        }
        return -1;                // Retorna -1 se o valor n�o foi encontrado
    }

    // Fun��o 2: Inser��o Ordenada - Insere valor mantendo a lista ordenada
    void inserirOrdenado(int valor) {
        No* n = new No(valor);    // Cria um novo n� com o valor fornecido
        contagem++;               // Incrementa o contador de n�s

        if (vazia() || primeiro->valor >= valor) {   // Insere no in�cio se a lista est� vazia ou o valor � menor
            n->proximo = primeiro;
            primeiro = n;
            if (ultimo == NULL) ultimo = n; // Se a lista estava vazia, ajusta o ponteiro ultimo
            return;
        }

        No* atual = primeiro;    // Ponteiro auxiliar para encontrar a posi��o correta para inserir o valor
        while (atual->proximo != NULL && atual->proximo->valor < valor) {
            atual = atual->proximo;   // Move para o pr�ximo n� at� encontrar onde o valor se encaixa
        }

        n->proximo = atual->proximo;  // Ajusta o ponteiro do novo n�
        atual->proximo = n;           // Insere o n� ap�s "atual"

        if (n->proximo == NULL) ultimo = n;   // Atualiza o ponteiro ultimo se o novo n� for o �ltimo
    }

    // Fun��o 3: Reverter Lista Encadeada - Inverte a ordem da lista
    void reverter() {
        No* anterior = NULL;    // Ponteiro que mant�m o n� anterior ao atual
        No* atual = primeiro;   // Ponteiro que percorre a lista
        No* proximo = NULL;     // Ponteiro para armazenar o pr�ximo n�
        ultimo = primeiro;      // Define o antigo primeiro n� como �ltimo

        while (atual != NULL) {   // Continua at� o fim da lista
            proximo = atual->proximo;  // Armazena o pr�ximo n�
            atual->proximo = anterior; // Inverte o ponteiro do n� atual para o n� anterior
            anterior = atual;          // Move "anterior" e "atual" para o pr�ximo n�
            atual = proximo;
        }
        primeiro = anterior;      // Define o �ltimo "anterior" como o novo primeiro
    }

    // Fun��o 4: Remover Duplicatas - Remove n�s com valores duplicados
    void removerDuplicatas() {
        No* atual = primeiro;     // Ponteiro que percorre a lista

        while (atual != NULL && atual->proximo != NULL) {   // Continua at� o pen�ltimo n�
            No* comparador = atual;   // Ponteiro para comparar n�s subsequentes
            while (comparador->proximo != NULL) {
                if (atual->valor == comparador->proximo->valor) {   // Se o valor � duplicado
                    No* temp = comparador->proximo;  // Armazena o n� duplicado
                    comparador->proximo = comparador->proximo->proximo;  // Remove o n� duplicado
                    delete temp;                     // Libera mem�ria do n� duplicado
                    contagem--;                      // Decrementa o contador
                } else {
                    comparador = comparador->proximo;   // Move para o pr�ximo n�
                }
            }
            atual = atual->proximo;   // Move para o pr�ximo n� para continuar a verifica��o
        }
    }

    // Fun��o 5: Encontrar o Elemento do Meio - Retorna o n� do meio
    No* encontrarElementoDoMeio() {
        if (vazia()) return NULL;   // Retorna NULL se a lista est� vazia

        No* lento = primeiro;   // Ponteiro lento que avan�a uma posi��o por vez
        No* rapido = primeiro;  // Ponteiro r�pido que avan�a duas posi��es por vez

        while (rapido != NULL && rapido->proximo != NULL) {
            lento = lento->proximo;            // Avan�a uma posi��o
            rapido = rapido->proximo->proximo; // Avan�a duas posi��es
        }
        return lento;   // Quando r�pido atinge o final, lento estar� no meio
    }
     void removerKesimoDoFinal(int k) {
        if (vazia() || k <= 0 || k > contagem) {
            printf("Posi��o inv�lida ou lista vazia.\n");
            return;
        }

        int posicaoAlvo = contagem - k; // Calcula a posi��o do elemento a partir do in�cio
        if (posicaoAlvo == 0) {
            // Se for o primeiro elemento, chamamos a fun��o para remover o primeiro
            No* paraDeletar = primeiro;
            primeiro = primeiro->proximo;
            delete paraDeletar;
            contagem--;
            return;
        }

        // Caso contr�rio, percorre at� o n� anterior ao que ser� removido
        No* aux = primeiro;
        for (int i = 0; i < posicaoAlvo - 1; i++) {
            aux = aux->proximo;
        }

        No* paraDeletar = aux->proximo;
        aux->proximo = paraDeletar->proximo;
        if (paraDeletar == ultimo) {
            ultimo = aux; // Atualiza o �ltimo se necess�rio
        }
        delete paraDeletar;
        contagem--;
    }

    // Fun��o para concatenar duas listas encadeadas
    void concatenar(Lista& outraLista) {
        if (outraLista.vazia()) return; // Se a outra lista est� vazia, n�o faz nada

        if (vazia()) {
            // Se a lista atual est� vazia, a outra lista se torna a lista atual
            primeiro = outraLista.primeiro;
            ultimo = outraLista.ultimo;
        } else {
            // Caso contr�rio, conecta o �ltimo n� da lista atual ao primeiro da outra
            ultimo->proximo = outraLista.primeiro;
            ultimo = outraLista.ultimo; // Atualiza o �ltimo n� da lista atual
        }

        contagem += outraLista.contagem; // Atualiza a contagem de n�s
        // Opcionalmente, podemos "esvaziar" a outra lista
        outraLista.primeiro = NULL;
        outraLista.ultimo = NULL;
        outraLista.contagem = 0;
    }
};

int main() {
    Lista l;

    // Adiciona valores � lista
    l.empurrarAtras(10);
    l.empurrarAtras(3);
    l.empurrarAtras(5);
    l.empurrarAtras(8);
    l.empurrarAtras(10);
    l.empurrarAtras(3);

    printf("Lista inicial:\n");
    l.imprimir();

    // Testa a fun��o de busca
    printf("\nBusca pelo valor 5: ");
    int posicao = l.buscarElemento(5);
    if (posicao != -1) {
        printf("Encontrado na posicao %d\n", posicao);
    } else {
        printf("N�o encontrado\n");
    }

    // Testa a fun��o de inser��o ordenada
    printf("\nInsercao ordenada de 4:\n");
    l.inserirOrdenado(4);
    l.imprimir();

    // Testa a fun��o de revers�o da lista
    printf("\nRevertendo a lista:\n");
    l.reverter();
    l.imprimir();

    // Testa a fun��o de remo��o de duplicatas
    printf("\nRemovendo duplicatas:\n");
    l.removerDuplicatas();
    l.imprimir();

    // Testa a fun��o de encontrar o elemento do meio
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

    printf("\nRemovendo o 2-�simo elemento do final:\n");
    l1.removerKesimoDoFinal(2); // Remove o 2� elemento a partir do final
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
