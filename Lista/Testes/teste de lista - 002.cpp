#include <stdio.h>
#include <stdlib.h>
#include <new>

typedef struct estrutura{
    int valorNumerico;
    struct estrutura *proximo;
}estrutura;

int main() {

    //Criando inicio da lista
    estrutura *ponteiroEncadeiada;

    //Cria um novo valor
    estrutura *novoPrimeiroValor = new estrutura;
    novoPrimeiroValor->valorNumerico = 13;
    novoPrimeiroValor->proximo = NULL;

    //Faz o ponteiro da encadeada apontar par o primeiro valor
    ponteiroEncadeiada = novoPrimeiroValor;

    //Cria um segundo valor
    estrutura *novoSegundoValor = new estrutura;
    novoSegundoValor->valorNumerico = 20;
    novoSegundoValor->proximo = NULL;

    //Junta os valores com um encadeamento
    ponteiroEncadeiada->proximo = novoSegundoValor;

    //imprime a lista encadeada
    while(ponteiroEncadeiada != NULL){
        //imprime o valor atual
        printf("\nValor: %d", ponteiroEncadeiada->valorNumerico);

        //Cursor recebe a posição de memoria do proximo valor
        ponteiroEncadeiada = ponteiroEncadeiada ->proximo;
    }

    return 0;
}
