#include <stdio.h>

struct Node {

    int value;
    Node *next;

    Node(){
        value = 0;
        next = NULL;
    }

    Node(int _value){
        value = _value;
        next = NULL;
    }
};

struct Queue {

    Node *first;
    Node *last;

    Queue(){
        first = NULL;
        last = NULL;
    }

    bool empty(){
        return first == NULL;
    }

    void enqueue(int value){
        Node *aux = new Node(value);
        if(empty()){
            first = aux;
            last = aux;
            return;
        }
        last->next = aux;
        last = aux;
    }

    void dequeue(){
        if(empty()) { return; }
        if(first == last){
            delete(first);
            first = NULL;
            last = NULL;
            return;
        }
        Node *aux = first;
        first = first->next;
        delete(aux);
    }

    int Front(){
        if(empty()) { return 0; }
        return first->value;
    }
};

// Fun��o para calcular o maior, menor e a m�dia aritm�tica
void calcularEstatisticas(Queue &fila, int &maior, int &menor, float &media) {
    if (fila.empty()) {
        printf("A fila est� vazia!\n");
        return;
    }

    int soma = 0;
    int count = 0;
    maior = fila.Front();
    menor = fila.Front();

    // Percorrer todos os elementos da fila
    Node *current = fila.first;
    while (current != NULL) {
        soma += current->value;
        count++;

        // Atualizar maior e menor
        if (current->value > maior) {
            maior = current->value;
        }
        if (current->value < menor) {
            menor = current->value;
        }

        current = current->next;
    }

    // Calcular a m�dia
    media = (float)soma / count;
}

int main() {
    Queue fila;

    int n;

    // Solicitar ao usu�rio o n�mero de elementos
    printf("Digite o n�mero de elementos na fila: ");
    scanf("%d", &n);

    // Solicitar ao usu�rio os elementos
    printf("Digite os elementos:\n");
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        fila.enqueue(num);  // Adiciona cada n�mero na fila
    }

    // Vari�veis para armazenar as estat�sticas
    int maior, menor;
    float media;

    // Calcular as estat�sticas
    calcularEstatisticas(fila, maior, menor, media);

    // Exibir os resultados
    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);
    printf("M�dia: %.2f\n", media);

    return 0;
}
