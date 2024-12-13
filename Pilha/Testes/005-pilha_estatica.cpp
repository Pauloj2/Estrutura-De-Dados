#include <stdio.h>
#include <iostream>
#define N 5

using namespace std;

struct Stack{

    int pilha[N];
    int quant;

    Stack(){
        quant = -1;
    }

    bool empty(){
        return quant == -1;
    }

    bool full(){
        return quant == N;
    }

    void push(int value){
        if(full()){
            printf("A pilha esta cheia\n");
            return;
        }
        quant++;
        pilha[quant] = value;
    }

    void pop(){
        if(empty()){
            printf("A pilha esta vazia");
            return;
        }
        quant--;
    }

    int peek(){
        if(empty()){
            printf("A pilha esta vazia");
            return 0;
        }
        return pilha[quant];
    }

};

int main (){

    Stack p;
    int aux = 0;

    while(aux < N){
        int num;
        printf("Digite o numero pra pilha: ");
        scanf("%d", &num);
        p.push(num);
        aux++;
    }
    while(!p.empty()){
        printf("\n%d", p.peek());
        p.pop();
    }

return 0;
}
