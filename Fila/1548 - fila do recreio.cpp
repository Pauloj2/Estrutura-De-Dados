#include <stdio.h>
#include <iostream>

using namespace std;

struct No{

    int value;
    No *next;

    No(){
        value = value;
        next = NULL;
    }

    No(int _value){
        value = _value;
        next = NULL;
    }
};

struct Queue{

    No *first;
    No *last;

    Queue(){
        first = NULL;
        last = NULL;
    }

    bool empty(){
        return first == NULL;
    }

    void enqueue(int value){
        No *aux = new No(value);
        if(empty()){
            first = aux;
            last = aux;
            return;
        }
        last->next = aux;
        last = aux;
    }

    void dequeue(){
        if(empty()){
            return;
        }
        if(first == last){
            first = NULL;
            last = NULL;
            return;
        }
        No *aux = first;
        first = first->next;
        delete(aux);
    }

    int front(){
        if(empty()){
            return -1;
        }
        return first->value;
    }

    void copiarLista(Queue &paraOrdenar){
        No *aux = first;
        while(aux != NULL){
            paraOrdenar.enqueue(aux->value);
            aux = aux->next;
        }
    }

    void ordenarDecrescente() {
        if (!first) return;

        bool trocado;
        No* atual;
        No* ultimo = NULL;

        do {
            trocado = false;
            atual = first;

            // Percorre a fila até o último nó não ordenado
            while (atual->next != ultimo) {
                if (atual->value < atual->next->value) {
                    // Troca os valores de dois nós
                    swap(atual->value, atual->next->value);
                    trocado = true;
                }
                atual = atual->next;
            }
            ultimo = atual; // Marca o último nó como ordenado
        } while (trocado); // Repete enquanto houver trocas
    }

    int contarInalterados(Queue &ordenada) {  // Função para contar quantos elementos não mudaram de posição após ordenação
        No* auxOriginal = first;  // Ponteiro para percorrer a fila original
        No* auxOrdenada = ordenada.first;  // Ponteiro para percorrer a fila ordenada
        int cont = 0;  // Variável para contar os elementos que não mudaram de posição

        while (auxOriginal != NULL && auxOrdenada != NULL) {  // Enquanto houver elementos em ambas as filas
            if (auxOriginal->value == auxOrdenada->value) {  // Se o valor na fila original for igual ao valor na fila ordenada
                cont++;  // Incrementa o contador
            }
            auxOriginal = auxOriginal->next;  // Avança para o próximo nó na fila original
            auxOrdenada = auxOrdenada->next;  // Avança para o próximo nó na fila ordenada
        }

        return cont;  // Retorna o número de elementos que não mudaram de posição
    }
};

int main(){

    int N;
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        int M;
        scanf("%d", &M);

        Queue filaOriginal;
        Queue filaOrdenada;

        for(int j=0; j<M; j++){
            int num;
            scanf("%d",&num);
            filaOriginal.enqueue(num);
        }

        filaOriginal.copiarLista(filaOrdenada);

        filaOrdenada.ordenarDecrescente();

        int quantInalterado = filaOriginal.contarInalterados(filaOrdenada);

        printf("%d\n", quantInalterado);
    }

    return 0;
}
