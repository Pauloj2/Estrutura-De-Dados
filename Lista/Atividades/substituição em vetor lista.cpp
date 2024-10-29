#include <stdio.h>

struct No{

    int valor;
    No *proximo;

    No(){
        valor = 0;
        proximo = NULL;
    }

    No(int _valor){
        valor = _valor;
        proximo = NULL;
    }
};

struct Lista{
    No *primeiro;
    No *ultimo;

    Lista(){
        primeiro = NULL;
        ultimo = NULL;
    }

    bool vazia() { // Verifica se a lista está vazia
        return primeiro == NULL;
    }

    void inserirAtras(int valor){
        No *n = new No(valor);

        if(vazia()){
            primeiro = n;
            ultimo = n;
            return;
        }
        ultimo->proximo = n;
        ultimo = n;
    }
    void substituirNuloNegativo(){
        No* aux = primeiro; //Um ponteiro aux é usado para percorrer a lista, começando do primeiro nó.
        while (aux != NULL) {
            if(aux->valor <= 0){
                aux->valor = 1;
            }
            aux = aux->proximo;
        }
    }
    void Imprimir(){
        int cont = 0;
        No *aux = primeiro;
        while(aux != NULL){
            printf("X[%d] = %d\n", cont, aux->valor);
            aux = aux->proximo;
            cont++;
        }
    }
};

int main(){

    Lista l;

    for(int i=0; i<10; i++){
        int num;
        scanf("%d", &num);
        l.inserirAtras(num);
    }

    l.substituirNuloNegativo();

    l.Imprimir();

    return 0;
}
