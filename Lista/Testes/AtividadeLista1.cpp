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

struct Lista {
    /*primeiro: um ponteiro para o primeiro nó da lista.
    ultimo: um ponteiro para o último nó da lista.
    contagem: um contador que rastreia o número de nós na lista.*/
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

    int tamanho() { // O(1)
        return contagem;//tamanhoretorna o número de nós na lista, que está armazenado na variável contagem.
    }

    void removerFrente() { // O(1) remove o primeiro valor
        if (vazia()) return;//Se a lista estiver vazia, não faça nada.
        if (contagem == 1) {//Se houver apenas um nó, exclua o nó, defina primeiroe ultimocomo NULL, e zera a contagem.
            delete(primeiro);
            primeiro = NULL;
            ultimo = NULL;
            contagem = 0;
            return;
        }
        //Caso contrário, mova o ponteiro primeiropara o próximo nó e exclua o antigo primeiro nó.
        No* paraDeletar = primeiro;
        primeiro = primeiro->proximo;
        delete(paraDeletar);
        contagem--;
    }

    void removerAtras() { // O(n) remove o ultimo valor
        if (vazia()) return;
        if (contagem == 1) {//Se houver apenas um nó, exclua o nó e defina primeiro e ultimo como NULL.
            delete(primeiro);
            primeiro = NULL;
            ultimo = NULL;
            contagem = 0;
            return;
        }//Caso contrário, percorre a lista até o penúltimo nó, ajusta o ponteiro ultimopara o penúltimo e exclui o último nó.
        No* paraDeletar = ultimo;
        No* aux = primeiro;
        while (aux->proximo != ultimo) {
            aux = aux->proximo;
        }
        ultimo = aux;
        ultimo->proximo = NULL;
        delete(paraDeletar);
        contagem--;
    }

    void inserir(int valor, int pos) { // O(n) insere o no em uma posição especifica
        if (pos <= 0) {//Se a posição é menor ou igual a 0, insira no início.
            empurrarFrente(valor);
            return;
        }
        if (pos >= contagem) {//Se a posição é maior ou igual à contagem, insira no final.
            empurrarAtras(valor);
            return;
        }
        //Caso contrário, percorre a lista até a posição desejada e insere o nó nessa posição.
        No* aux = primeiro;
        for (int i = 0; i < pos; i++, aux = aux->proximo);
        No* n = new No(valor);
        n->proximo = aux->proximo;
        aux->proximo = n;
        contagem++;
    }

    void remover(int valor) { // O(n) remove um valor especifico
        if (vazia()) return;

        No *aux = primeiro;
        No *anterior = NULL;
        for (int i = 0; i < contagem; i++) {
            if (aux->valor == valor) {// Encontra o nó com o valor a ser removido
                if (anterior == NULL) {
                    removerFrente();// Se o nó a ser removido for o primeiro, chama removerFrente
                } else {
                    anterior->proximo = aux->proximo;// Ajusta o ponteiro do nó anterior
                    delete(aux);// Libera a memória do nó removido
                    contagem--;// Diminui o contador de elementos
                    aux = anterior;// Encerra a função após remover o valor
                }
            }
            anterior = aux;// Atualiza o nó anterior
            aux = aux->proximo;// Avança para o próximo nó
        }
    }

    void removerPorPosicao(int pos) { // O(n)
        if (pos <= 0) {
            removerFrente();// Se a posição for menor ou igual a 0, remove o primeiro nó
            return;
        }
        if (pos >= contagem) {
            removerAtras();// Se a posição for maior ou igual ao tamanho da lista, remove o último nó
            return;
        }
        No* aux = primeiro;
        for (int i = 0; i < pos - 1; i++, aux = aux->proximo);
        No* paraDeletar = aux->proximo;// Nó a ser removido
        aux->proximo = paraDeletar->proximo;// Ajusta o ponteiro do nó anterior
        delete(paraDeletar);// Libera a memória do nó removido
        contagem--;
    }
    //Atividade 1
    void removerUltimos(int N) { /* O(n) */
        if (contagem < N) {
            while(!vazia()){
                removerFrente();// Se N for maior que o número de nós, remove todos os nós
            }
            return;
        }
        for (int i = 0; i < N; i++) {
            removerAtras();// Remove os últimos N nós
        }
    }
    //Atividade 2
    void removeSegundo(){
        if(contagem <= 1){// Se a lista tiver 0 ou 1 elemento, não faz nada.
            return;
        }
        No *paraDeletar = primeiro->proximo;// cria um novo ponteiro para apontar para o segundo ponteiro.

        primeiro->proximo =  paraDeletar->proximo;// O primeiro ponteiro recebe o terceiro que agora vira o segundo;
        delete(paraDeletar);//Deleta o segundo ponteiro
        contagem--;
    }
    void inserirSegundo(int num){
        if (vazia()) return;
        if(contagem == 1){
            empurrarAtras(num);
        }
        No *segundo = new No(num);

        segundo->proximo = primeiro->proximo;
        primeiro->proximo = segundo;
        contagem++;
    }
    //Atividade 3
    void inserirTamanhoNoFinal(){
        if(contagem == 0){
            return;
        }
        empurrarAtras(tamanho());//insere no final da lista o tamanho atual da lista.
    }
    // Atividade 4
    void inserirTodosNumeros(int Num){
        int aux = 1;
        while (aux <= Num){
            empurrarAtras(aux);//insira na lista todos os números de 1 até N
            aux++;
        }
    }
    // Atividade 5
    void inserirPenultimo(int num){//insere um elemento sempre na penúltima posição da lista
        if(contagem <= 1){
            return;// Se a lista tiver 0 ou 1 elemento, não faz nada.
        }
        No *novoNo = new No(num);//Criação de Novo Nó ( new No(num)) : Se a lista tiver mais de um elemento, crie-se um novo nó ( novoNo) com o valor num. Esse nó será o novo penúltimo nó da lista.

        No * aux = primeiro;//Inicializa um ponteiro auxapontando para o primeiro nó da lista.
        for(int i=1; i<contagem - 1; i++){//O loop percorre uma lista do primeiro nó até o nó anterior ao último.
            aux = aux->proximo;//auxapontará para o penúltimo nó.
        }
        novoNo->proximo = aux->proximo;// O novo nó aponta para o último nó
        aux->proximo = novoNo;//Ajusta o ponteiro proximodo penúltimo nó ( aux) para apontar para o novo nó.
        contagem++;
    }

    //função para ordenar os valores em ordem decrescente.
    void ordenarDecrescente() {
        if (vazia() || contagem == 1) return; // Se a lista estiver vazia ou tiver apenas um elemento, não precisa ordenar

        bool trocou;
        do {
            trocou = false;
            No* atual = primeiro;
            while (atual->proximo != NULL) {
                // Se o valor do nó atual é menor que o valor do próximo nó, trocamos
                if (atual->valor < atual->proximo->valor) {
                    int temp = atual->valor;
                    atual->valor = atual->proximo->valor;
                    atual->proximo->valor = temp;
                    trocou = true;
                }
                atual = atual->proximo;
            }
        } while (trocou); // Continua enquanto houver trocas

    }
    //função para ordenar os valores em ordem crescente.
    void ordenarCrescente() {
        if (vazia() || contagem == 1) return;

        No* limite = NULL; // Define um limite para o final da lista
        bool trocou;

        do {
            trocou = false;
            No* atual = primeiro;
            No* anterior = NULL;
            No* ultimoTroca = NULL; // Rastreia a última troca

            while (atual->proximo != limite) {
                No* proximo = atual->proximo;
                if (atual->valor > proximo->valor) {
                    // Troca os valores entre os nós atual e próximo
                    int temp = atual->valor;
                    atual->valor = proximo->valor;
                    proximo->valor = temp;
                    trocou = true;
                    ultimoTroca = proximo; // Atualiza o último ponto de troca
                }
                anterior = atual;
                atual = proximo;
            }
            limite = ultimoTroca; // Reduz o limite para a última posição onde houve troca
        } while (trocou);
    }

    //Função para somar todos elementos de uma lista
    int somarElementos() { // O(n)
        int soma = 0;
        No* atual = primeiro;
        while (atual != NULL) { // Percorre cada nó da lista
            soma += atual->valor; // Adiciona o valor do nó atual à soma
            atual = atual->proximo; // Avança para o próximo nó
        }
        return soma;
    }

    //função para somar duas listas
    Lista somarListas(Lista& l1, Lista& l2) {
        Lista resultado; // Nova lista para armazenar a soma de cada nó
        No* atual1 = l1.primeiro;
        No* atual2 = l2.primeiro;

        // Percorre as duas listas até o final de uma delas
        while (atual1 != NULL && atual2 != NULL) {
            int soma = atual1->valor + atual2->valor; // Soma os valores dos nós correspondentes
            resultado.empurrarAtras(soma); // Adiciona a soma à lista resultado
            atual1 = atual1->proximo; // Avança para o próximo nó em l1
            atual2 = atual2->proximo; // Avança para o próximo nó em l2
        }

        return resultado; // Retorna a lista resultante com as somas
    }

    //Função somar os nós da mesma posição em duas listas encadeadas
    Lista somarListasPosicao(Lista& l1, Lista& l2) {
        Lista resultado;
        No* atual1 = l1.primeiro;
        No* atual2 = l2.primeiro;

        // Percorre ambas as listas ao mesmo tempo
        while (atual1 != NULL || atual2 != NULL) {
            int soma = 0;

            if (atual1 != NULL) {
                soma += atual1->valor;
                atual1 = atual1->proximo;
            }

            if (atual2 != NULL) {
                soma += atual2->valor;
                atual2 = atual2->proximo;
            }

            resultado.empurrarAtras(soma); // Adiciona a soma à lista de resultado
        }

        return resultado;
    }

    // função somarListas "vai-um"
    Lista somarListas(Lista& l1, Lista& l2) {
        Lista resultado;
        No* atual1 = l1.primeiro;
        No* atual2 = l2.primeiro;
        int carry = 0;

        while (atual1 != NULL || atual2 != NULL || carry != 0) {
            int soma = carry;

            if (atual1 != NULL) {
                soma += atual1->valor;
                atual1 = atual1->proximo;
            }

            if (atual2 != NULL) {
                soma += atual2->valor;
                atual2 = atual2->proximo;
            }

            carry = soma / 10;  // Define carry para a próxima posição
            resultado.empurrarAtras(soma % 10);  // Insere apenas o dígito unitário
        }

        return resultado;
    }

};

int main() {
    Lista l;

    l.empurrarFrente(10);
    l.empurrarFrente(3);
    l.empurrarAtras(5);

    //l.removerAtras();

    l.imprimir();

    //l.inserirTamanhoNoFinal();
    //l.removeSegundo();
    //l.inserirTodosNumeros(3);
    printf("\n===================\n");
    l.inserirSegundo(6);
    //l.inserirPenultimo(10);
    //l.removerUltimos(1);
    //l.inserirTamanhoNoFinal();
    l.imprimir();

    return 0;
}
