#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct lista{
    int info;
    char nome[20];
    struct lista* prox;
};
typedef struct lista Lista;
struct fila{
    Lista *ini;
    Lista *fim;
};
typedef struct fila Fila;

struct pergunta{//struct de perguntas com respostas
    char perg[20];
    int resp;//1=sim 0=nao
    struct pergunta* prox;
};
typedef struct pergunta Pergunta;
struct filap{//fila que aponta para as perguntas
    Pergunta *ini;
    Pergunta *fim;
};
typedef struct filap Filap;

Filap* filap_cria(void){//criacao da fila de perguntas
    Filap* f = (Filap*)malloc(sizeof(Filap));
    f->ini=f->fim=NULL;
    return f;
}

void insere_perg(Filap *f,int resp,char perg[20]){
    Pergunta* n =(Pergunta*)malloc(sizeof(Pergunta));
    strcpy(n->perg,perg);
    n->resp=resp;
    n->prox=NULL; //novo nó passa a ser o último
    if(f->fim!=NULL) //verifica se a fila está vazia
        f->fim->prox=n;
    else
        f->ini=n;
    f->fim=n;
}
void imprime_perguntas(Filap* f){
    Pergunta* q=f->ini;
    while(q!=NULL){
        printf("->[%s]",q->perg);
        q=q->prox;
    }
    printf("\n");
}

Fila* fila_cria(void){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->ini=f->fim=NULL;
    return f;
}
int fila_vazia(Fila* f){
    if(f->ini==NULL)
        return 1;
    return 0;
}
void fila_insere(Fila* f, char v[20],int info){
    Lista* n =(Lista*)malloc(sizeof(Lista));
    strcpy(n->nome,v);
    n->info=info;
    n->prox=NULL; //novo nó passa a ser o último
    if(f->fim!=NULL) //verifica se a fila está vazia
        f->fim->prox=n;
    else
        f->ini=n;
    f->fim=n;
}
void fila_retira (Fila* f, char * v){
    Lista* t;
    if(fila_vazia(f)){
        printf("Fila vazia.\n");
        exit(1);
    }
    t=f->ini;
    strcpy(v,t->nome);
    f->ini=t->prox;
    if(f->ini==NULL)
        f->fim=NULL;
    free(t);
}
void fila_libera(Fila* f){
    Lista* q=f->ini;
    while(q!=NULL){
        Lista* t = q->prox; //segura o que e atribui o proximo a 't'
        free(q);//libera q
        q=t;//q recebe o t
    }
    free(f);
}
void fila_imprime(Fila* f){
    Lista* q=f->ini;
    while(q!=NULL){
        printf("->[%s]",q->nome);
        q=q->prox;
    }
    printf("\n");
}
int fila_conta(Fila *f){
    Lista* l=f->ini;
    int i=0;
    while(l!=NULL){
        i++;
        l=l->prox;
    }
    return i;
}
void libera_perguntas(Filap* f){
    Pergunta* q=f->ini;
    while(q!=NULL){
        Pergunta* t = q->prox; //segura o que e atribui o proximo a 't'
        free(q);//libera q
        q=t;//q recebe o t
    }
    free(f);
}