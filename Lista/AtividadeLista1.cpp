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

struct Lista {
    /*primeiro: um ponteiro para o primeiro n� da lista.
    ultimo: um ponteiro para o �ltimo n� da lista.
    contagem: um contador que rastreia o n�mero de n�s na lista.*/
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

    int tamanho() { // O(1)
        return contagem;//tamanhoretorna o n�mero de n�s na lista, que est� armazenado na vari�vel contagem.
    }

    void removerFrente() { // O(1) remove o primeiro valor
        if (vazia()) return;//Se a lista estiver vazia, n�o fa�a nada.
        if (contagem == 1) {//Se houver apenas um n�, exclua o n�, defina primeiroe ultimocomo NULL, e zera a contagem.
            delete(primeiro);
            primeiro = NULL;
            ultimo = NULL;
            contagem = 0;
            return;
        }
        //Caso contr�rio, mova o ponteiro primeiropara o pr�ximo n� e exclua o antigo primeiro n�.
        No* paraDeletar = primeiro;
        primeiro = primeiro->proximo;
        delete(paraDeletar);
        contagem--;
    }

    void removerAtras() { // O(n) remove o ultimo valor
        if (vazia()) return;
        if (contagem == 1) {//Se houver apenas um n�, exclua o n� e defina primeiro e ultimo como NULL.
            delete(primeiro);
            primeiro = NULL;
            ultimo = NULL;
            contagem = 0;
            return;
        }//Caso contr�rio, percorre a lista at� o pen�ltimo n�, ajusta o ponteiro ultimopara o pen�ltimo e exclui o �ltimo n�.
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

    void inserir(int valor, int pos) { // O(n) insere o no em uma posi��o especifica
        if (pos <= 0) {//Se a posi��o � menor ou igual a 0, insira no in�cio.
            empurrarFrente(valor);
            return;
        }
        if (pos >= contagem) {//Se a posi��o � maior ou igual � contagem, insira no final.
            empurrarAtras(valor);
            return;
        }
        //Caso contr�rio, percorre a lista at� a posi��o desejada e insere o n� nessa posi��o.
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
            if (aux->valor == valor) {// Encontra o n� com o valor a ser removido
                if (anterior == NULL) {
                    removerFrente();// Se o n� a ser removido for o primeiro, chama removerFrente
                } else {
                    anterior->proximo = aux->proximo;// Ajusta o ponteiro do n� anterior
                    delete(aux);// Libera a mem�ria do n� removido
                    contagem--;// Diminui o contador de elementos
                    aux = anterior;// Encerra a fun��o ap�s remover o valor
                }
            }
            anterior = aux;// Atualiza o n� anterior
            aux = aux->proximo;// Avan�a para o pr�ximo n�
        }
    }

    void removerPorPosicao(int pos) { // O(n)
        if (pos <= 0) {
            removerFrente();// Se a posi��o for menor ou igual a 0, remove o primeiro n�
            return;
        }
        if (pos >= contagem) {
            removerAtras();// Se a posi��o for maior ou igual ao tamanho da lista, remove o �ltimo n�
            return;
        }
        No* aux = primeiro;
        for (int i = 0; i < pos - 1; i++, aux = aux->proximo);
        No* paraDeletar = aux->proximo;// N� a ser removido
        aux->proximo = paraDeletar->proximo;// Ajusta o ponteiro do n� anterior
        delete(paraDeletar);// Libera a mem�ria do n� removido
        contagem--;
    }
    //Atividade 1
    void removerUltimos(int N) { /* O(n) */
        if (contagem < N) {
            while(!vazia()){
                removerFrente();// Se N for maior que o n�mero de n�s, remove todos os n�s
            }
            return;
        }
        for (int i = 0; i < N; i++) {
            removerAtras();// Remove os �ltimos N n�s
        }
    }
    //Atividade 2
    void removeSegundo(){
        if(contagem <= 1){// Se a lista tiver 0 ou 1 elemento, n�o faz nada.
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
            empurrarAtras(aux);//insira na lista todos os n�meros de 1 at� N
            aux++;
        }
    }
    // Atividade 5
    void inserirPenultimo(int num){//insere um elemento sempre na pen�ltima posi��o da lista
        if(contagem <= 1){
            return;// Se a lista tiver 0 ou 1 elemento, n�o faz nada.
        }
        No *novoNo = new No(num);//Cria��o de Novo N� ( new No(num)) : Se a lista tiver mais de um elemento, crie-se um novo n� ( novoNo) com o valor num. Esse n� ser� o novo pen�ltimo n� da lista.

        No * aux = primeiro;//Inicializa um ponteiro auxapontando para o primeiro n� da lista.
        for(int i=1; i<contagem - 1; i++){//O loop percorre uma lista do primeiro n� at� o n� anterior ao �ltimo.
            aux = aux->proximo;//auxapontar� para o pen�ltimo n�.
        }
        novoNo->proximo = aux->proximo;// O novo n� aponta para o �ltimo n�
        aux->proximo = novoNo;//Ajusta o ponteiro proximodo pen�ltimo n� ( aux) para apontar para o novo n�.
        contagem++;
    }

    //fun��o para ordenar os valores em ordem decrescente.
    void ordenarDecrescente() {
        if (vazia() || contagem == 1) return; // Se a lista estiver vazia ou tiver apenas um elemento, n�o precisa ordenar

        bool trocou;
        do {
            trocou = false;
            No* atual = primeiro;
            while (atual->proximo != NULL) {
                // Se o valor do n� atual � menor que o valor do pr�ximo n�, trocamos
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
    //fun��o para ordenar os valores em ordem crescente.
    void ordenarCrescente() {
        if (vazia() || contagem == 1) return;

        No* limite = NULL; // Define um limite para o final da lista
        bool trocou;

        do {
            trocou = false;
            No* atual = primeiro;
            No* anterior = NULL;
            No* ultimoTroca = NULL; // Rastreia a �ltima troca

            while (atual->proximo != limite) {
                No* proximo = atual->proximo;
                if (atual->valor > proximo->valor) {
                    // Troca os valores entre os n�s atual e pr�ximo
                    int temp = atual->valor;
                    atual->valor = proximo->valor;
                    proximo->valor = temp;
                    trocou = true;
                    ultimoTroca = proximo; // Atualiza o �ltimo ponto de troca
                }
                anterior = atual;
                atual = proximo;
            }
            limite = ultimoTroca; // Reduz o limite para a �ltima posi��o onde houve troca
        } while (trocou);
    }

    //Fun��o para somar todos elementos de uma lista
    int somarElementos() { // O(n)
        int soma = 0;
        No* atual = primeiro;
        while (atual != NULL) { // Percorre cada n� da lista
            soma += atual->valor; // Adiciona o valor do n� atual � soma
            atual = atual->proximo; // Avan�a para o pr�ximo n�
        }
        return soma;
    }

    //fun��o para somar duas listas
    Lista somarListas(Lista& l1, Lista& l2) {
        Lista resultado; // Nova lista para armazenar a soma de cada n�
        No* atual1 = l1.primeiro;
        No* atual2 = l2.primeiro;

        // Percorre as duas listas at� o final de uma delas
        while (atual1 != NULL && atual2 != NULL) {
            int soma = atual1->valor + atual2->valor; // Soma os valores dos n�s correspondentes
            resultado.empurrarAtras(soma); // Adiciona a soma � lista resultado
            atual1 = atual1->proximo; // Avan�a para o pr�ximo n� em l1
            atual2 = atual2->proximo; // Avan�a para o pr�ximo n� em l2
        }

        return resultado; // Retorna a lista resultante com as somas
    }

    //Fun��o somar os n�s da mesma posi��o em duas listas encadeadas
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

            resultado.empurrarAtras(soma); // Adiciona a soma � lista de resultado
        }

        return resultado;
    }

    // fun��o somarListas "vai-um"
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

            carry = soma / 10;  // Define carry para a pr�xima posi��o
            resultado.empurrarAtras(soma % 10);  // Insere apenas o d�gito unit�rio
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
