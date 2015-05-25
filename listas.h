/*
**************************************
* Trabalho 1-AV2 de Estrutura de Dados I
* Curso de Sistemas da informacão
* Aluno: Eduardo Gomes - matricula: 0050011271
* Listas
***************************************
*/
#include <stdio.h>
#include <stdlib.h>
struct lista{
    int info;
    struct lista *prox;
};
typedef struct lista Lista;
Lista * lst_cria(){//funcao de criacao da lista, apontando-a para null
    return NULL;
}
Lista * lst_insere(Lista *l,int info){//inclusao de elementos na lista
    Lista *p = malloc(sizeof(Lista));
    p->info=info;
    p->prox=l;
    return p;
}
void lst_imprime(Lista *l){//imprime os elementos
    Lista *p;
    for(p=l;p!=NULL;p=p->prox)//enquanto p for diferente de null, imprimir a informacao
        printf("-->[%d]",p->info);
}
int lst_buscar(Lista *l, int chave){
    Lista *p;
    for(p=l;p!=NULL;p=p->prox)
        if(chave==p->info) 
            return 1;
    return 0;
}
void lst_libera(Lista* l){//funcao para liberar a lista
    Lista* p = l;
    while (p!=NULL){
        Lista*t = p->prox;
        free(p);
        p=t;
    }
}

Lista* separa(Lista* l, int n){
    Lista *p=l;//p recebe lista l
    Lista *aux=NULL;
    while(p!=NULL&&p->info!=n){
        p=p->prox;//enquanto nao encontrado o 'n' passa de elemento na lista
    }
    if(p==NULL)
        return NULL;//se não achou retorna NULL
    aux=p;//chegando aqui ja foi encontrado e aux recebe a lista p
    p=p->prox;//p recebe seu proximo, ou seja sai do elemento encontrado
    aux->prox=NULL;//retira a referencia do proximo ao elemento encontrado, dizendo que a lista termina ali
    l=aux;//retorna a lista dividida ate o elemento para l
    return p;//retorna a subdivisao apos o elemento para a Lista na main
}