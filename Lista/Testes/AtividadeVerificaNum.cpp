#include <stdio.h>

struct No {
     int valor;
     No* proximo;

     No() {
         valor = 0;
         proximo = NULL;
     }

     No(int _valor) {
         valor = _valor;
         proximo = NULL;
     }
};
struct Lista {
     No* primeiro;
     No* ultimo;
     int contagem;

     Lista() {
         primeiro = NULL;
         ultimo = NULL;
         contagem = 0;
     }

     bool vazia() {
        return primeiro == NULL;
     }
     void empurrarAtras(int valor) {
        No* n = new No(valor);
        contagem++;

        if (vazia()) {
            primeiro = n;
            ultimo = n;
            return;
        }
        ultimo->proximo = n;
        ultimo = n;
     }
     void imprimir() {
        No* aux = primeiro;
        while (aux != NULL) {
            printf("%d -> ", aux->valor);
            aux = aux->proximo;
        }
        printf("NULL\n");
     }
     void verificarSaldo(){
        No* aux = primeiro;
        double saldo = aux->valor;
        bool verifica = true;

        if(saldo < 0){
            verifica = false;
            printf("invalido\n");
        }
        while(aux != ultimo && saldo > 0) {
            if(saldo + aux->proximo->valor < 0){
                verifica = false;
                printf("invalido\n");
                return;
            }else {
                saldo += aux->proximo->valor;
            }
            aux = aux->proximo;
        }
        if(verifica){
            printf("%.2f\n", saldo);
        }
     }
    };
    int main() {
     Lista l1;
     int n;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
        double x;
        scanf("%lf", &x);
        l1.empurrarAtras(x);
     }

     l1.verificarSaldo();
     return 0;
}
