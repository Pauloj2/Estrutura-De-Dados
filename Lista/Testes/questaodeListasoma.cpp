#include<stdio.h>

struct No {
    /*Define uma estrutura chamada No(nó), que armazena um valor inteiro ( valor)
    e um ponteiro ( proximo) que aponta para o próximo nó na lista encadeada.*/
    int valor;
    No* proximo;

    No() { // O(1)
        valor = 0;
        proximo = NULL;
    }
    /*Construtor padrão : Inicializa o nó com o valor 0e define o ponteiro proximocomo
    NULL, diminuindo que este nó não aponta para nenhum outro nó.*/

    No(int _valor) { // O(1)
        valor = _valor;
        proximo = NULL;
    }
    /*Construtor com parâmetro : inicializa o valor do nó como _valor, que é fornecido pelo usuário.
     O ponteiro proximoainda é definido como NULL, já que o nó não está conectado a nenhum outro nó no momento da criação.*/
};

struct Lista{

    No* primeiro;
    No* ultimo;
    int contagem;

    /*Construtor da lista : inicializa uma lista vazia, com primeiroe
    ultimoapontando para NULL, e o contador contagemé definido como 0.*/
    Lista() { // O(1)
        primeiro = NULL;
        ultimo = NULL;
        contagem = 0;
    }
    /*Funçãovazia : verificar se a lista está vazia. Retorna truese primeirofor NULL,
     o que indica que não há nós na lista.*/
    bool vazia() { // O(1)
        return primeiro == NULL;
    }

    void empurrarFrente(int valor) { // O(1) insere um valor na frente
        No *n = new No(valor); //Cria um novo nó n com o valor fornecido.
        contagem++; //Incrementa a contagemde nós.
        if (vazia()) { //Se a lista estiver vazia, o novo não se tornará o primeiro e o último.
            primeiro = n;
            ultimo = n;
            return;
        }
        n->proximo = primeiro; //Caso contrário, o novo nó aponta para o nó que era o primeiro e, em seguida, o novo nó se torna o primeiro.
        primeiro = n;
    }

    void empurrarAtras(int valor) { // O(1) insere um valor atras
        No *n = new No(valor);//Cria um novo nó ncom o valor fornecido.
        contagem++;//Incrementos a contagem.

        if (vazia()) { //Se a lista estiver vazia, o novo não se tornará o primeiro e o último.
            primeiro = n;
            ultimo = n;
            return;
        }
        ultimo->proximo = n;//Caso contrário, o ponteiro proximodo nó que era o último aponta para o novo nó, e o novo nó se torna o último.
        ultimo = n;
    }

    void imprimir() { // complexidade de tempo O(n), complexidade de espaço O(1)
        No* aux = primeiro; //Um ponteiro auxé usado para percorrer a lista, começando do primeiro nó.
        while (aux != NULL) {
            printf("%d -> ", aux->valor);//A cada nó, imprime o valor seguido por "->".
            aux = aux->proximo;
        }//O laço continua até que auxse torne NULL, indicando que chegou ao fim da lista.
    }

     void soma(Lista &lista2) {
        No* auxl1 = primeiro;        // Ponteiro para percorrer a primeira lista
        No* auxl2 = lista2.primeiro; // Ponteiro para percorrer a segunda lista

        while (auxl1 != NULL && auxl2 != NULL) {  // Enquanto há nós em ambas as listas
            int soma = 0;          // Variável para armazenar a soma dos valores dos nós

            if (auxl1->valor + auxl2->valor >= 10) {   // Se a soma for 10 ou mais
                auxl1->proximo->valor += 1;    // Adiciona 1 ao próximo valor de auxl1
                soma = (auxl1->valor + auxl2->valor) - 10;  // Armazena o valor da unidade
                printf("%d ", soma);         // Imprime o resultado parcial
            } else {
                soma = auxl1->valor + auxl2->valor; // Soma os valores normalmente
                printf("%d ", soma);        // Imprime o resultado parcial
            }
            auxl1 = auxl1->proximo;  // Move para o próximo nó em l1
            auxl2 = auxl2->proximo;  // Move para o próximo nó em l2
        }
    }
};

int main(){
    Lista l1;                  // Cria a primeira lista
    Lista l2;                  // Cria a segunda lista
    int n;

    scanf("%d", &n);                  // Lê o número de elementos nas listas

    int aux1 = n;
    int aux2 = n;

    for(int i = 0; i < n; i++) {     // Lê os elementos da primeira lista
        int x;
        scanf("%d", &x);
        l1.empurrarAtras(x);          // Adiciona o elemento ao final da lista l1
    }

    for(int i = 0; i < n; i++) {     // Lê os elementos da segunda lista
        int y;
        scanf("%d", &y);
        l2.empurrarAtras(y);          // Adiciona o elemento ao final da lista l2
    }

    l1.soma(l2);               // Chama a função para somar as listas e imprimir o resultado

    return 0;
}
