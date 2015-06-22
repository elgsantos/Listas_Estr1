#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10
struct fila{
    int n;
    int vet[TAM];
    int ini;
};
typedef struct fila Fila;

Fila* fila_cria(void){
    Fila* f=(Fila*)malloc(sizeof(Fila));
    f->n=0;
    f->ini=0;
    return f;
}

void fila_insere(Fila* f,int v){
    int fim;
    if(f->n==TAM){
        printf("Capacidade da Fila estorou\n");
        exit(1);
    }
    fim=(f->ini+f->n)%TAM;
    f->vet[fim]=v;
    f->n++;
}

int fila_retira(Fila* f){
    int v;
    if(f->n==0){
        printf("Fila vazia\n");
        exit(1);
    }
    v=f->vet[f->ini];
    f->ini=(f->ini+1)%TAM;
    f->n--;
    return v;
}
fila_imprime(Fila* f){
    int i;
    for(i=f->ini;i<f->n;i++){
        printf("->%d",f->vet[i]);
    }
}
int sorteio(){
    int x;
    if((rand()%2)==0){//50% de chance de cair em pares negativos ou pares positivos, mesmo para impares, de -9 a 9
        x = rand() % 10;
        x*=(x%2)==1? 1:-1;
    }else{
        x = rand() % 10;
        x*=(x%2)==0? 1:-1;
    }
    if (x==0) {
        printf("\nNúmero 0 sorteado, sorteando novamente...");
        return sorteio();//recursiva caso seja 0 sorteado 
    }
    return x;
}