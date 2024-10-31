#include<stdio.h>

struct No {
    /*Define uma estrutura chamada No(n�), que armazena um valor inteiro ( valor)
    e um ponteiro ( proximo) que aponta para o pr�ximo n� na lista encadeada.*/
    int valor;
    No* proximo;

    No() { // O(1)
        valor = 0;
        proximo = NULL;
    }
    /*Construtor padr�o : Inicializa o n� com o valor 0e define o ponteiro proximocomo
    NULL, diminuindo que este n� n�o aponta para nenhum outro n�.*/

    No(int _valor) { // O(1)
        valor = _valor;
        proximo = NULL;
    }
    /*Construtor com par�metro : inicializa o valor do n� como _valor, que � fornecido pelo usu�rio.
     O ponteiro proximoainda � definido como NULL, j� que o n� n�o est� conectado a nenhum outro n� no momento da cria��o.*/
};

struct Lista{

    No* primeiro;
    No* ultimo;
    int contagem;

    /*Construtor da lista : inicializa uma lista vazia, com primeiroe
    ultimoapontando para NULL, e o contador contagem� definido como 0.*/
    Lista() { // O(1)
        primeiro = NULL;
        ultimo = NULL;
        contagem = 0;
    }
    /*Fun��ovazia : verificar se a lista est� vazia. Retorna truese primeirofor NULL,
     o que indica que n�o h� n�s na lista.*/
    bool vazia() { // O(1)
        return primeiro == NULL;
    }

    void empurrarFrente(int valor) { // O(1) insere um valor na frente
        No *n = new No(valor); //Cria um novo n� n com o valor fornecido.
        contagem++; //Incrementa a contagemde n�s.
        if (vazia()) { //Se a lista estiver vazia, o novo n�o se tornar� o primeiro e o �ltimo.
            primeiro = n;
            ultimo = n;
            return;
        }
        n->proximo = primeiro; //Caso contr�rio, o novo n� aponta para o n� que era o primeiro e, em seguida, o novo n� se torna o primeiro.
        primeiro = n;
    }

    void empurrarAtras(int valor) { // O(1) insere um valor atras
        No *n = new No(valor);//Cria um novo n� ncom o valor fornecido.
        contagem++;//Incrementos a contagem.

        if (vazia()) { //Se a lista estiver vazia, o novo n�o se tornar� o primeiro e o �ltimo.
            primeiro = n;
            ultimo = n;
            return;
        }
        ultimo->proximo = n;//Caso contr�rio, o ponteiro proximodo n� que era o �ltimo aponta para o novo n�, e o novo n� se torna o �ltimo.
        ultimo = n;
    }

    void imprimir() { // complexidade de tempo O(n), complexidade de espa�o O(1)
        No* aux = primeiro; //Um ponteiro aux� usado para percorrer a lista, come�ando do primeiro n�.
        while (aux != NULL) {
            printf("%d -> ", aux->valor);//A cada n�, imprime o valor seguido por "->".
            aux = aux->proximo;
        }//O la�o continua at� que auxse torne NULL, indicando que chegou ao fim da lista.
    }

     void soma(Lista &lista2) {
        No* auxl1 = primeiro;        // Ponteiro para percorrer a primeira lista
        No* auxl2 = lista2.primeiro; // Ponteiro para percorrer a segunda lista

        while (auxl1 != NULL && auxl2 != NULL) {  // Enquanto h� n�s em ambas as listas
            int soma = 0;          // Vari�vel para armazenar a soma dos valores dos n�s

            if (auxl1->valor + auxl2->valor >= 10) {   // Se a soma for 10 ou mais
                auxl1->proximo->valor += 1;    // Adiciona 1 ao pr�ximo valor de auxl1
                soma = (auxl1->valor + auxl2->valor) - 10;  // Armazena o valor da unidade
                printf("%d ", soma);         // Imprime o resultado parcial
            } else {
                soma = auxl1->valor + auxl2->valor; // Soma os valores normalmente
                printf("%d ", soma);        // Imprime o resultado parcial
            }
            auxl1 = auxl1->proximo;  // Move para o pr�ximo n� em l1
            auxl2 = auxl2->proximo;  // Move para o pr�ximo n� em l2
        }
    }
};

int main(){
    Lista l1;                  // Cria a primeira lista
    Lista l2;                  // Cria a segunda lista
    int n;

    scanf("%d", &n);                  // L� o n�mero de elementos nas listas

    int aux1 = n;
    int aux2 = n;

    for(int i = 0; i < n; i++) {     // L� os elementos da primeira lista
        int x;
        scanf("%d", &x);
        l1.empurrarAtras(x);          // Adiciona o elemento ao final da lista l1
    }

    for(int i = 0; i < n; i++) {     // L� os elementos da segunda lista
        int y;
        scanf("%d", &y);
        l2.empurrarAtras(y);          // Adiciona o elemento ao final da lista l2
    }

    l1.soma(l2);               // Chama a fun��o para somar as listas e imprimir o resultado

    return 0;
}
