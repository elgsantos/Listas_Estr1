/*
**************************************
* Trabalho 1-AV2 de Estrutura de Dados I
* Curso de Sistemas da informacão
* Aluno: Eduardo Gomes - matricula: 0050011271
* Listas
***************************************
*/
#include "listas.h"
int main(){
    Lista *l;
    l=lst_cria();
    l=lst_insere(l,10);
    l=lst_insere(l,20);
    l=lst_insere(l,30);
    l=lst_insere(l,40);
    l=lst_insere(l,50);
    l=lst_insere(l,100);
    l=lst_insere(l,200);
    l=lst_insere(l,300);
    l=lst_insere(l,400);
    l=lst_insere(l,500);
    lst_imprime(l);
    puts("");
    int elem;
    printf("Escolha o elemento no qual ocorrera a separacao da lista: ");
    scanf("%d",&elem);
    int busca=lst_buscar(l,elem);
    if(busca){
        Lista *l2;
        l2=lst_cria();
        l2=separa(l,elem);
        printf("Lista 1: ");
        lst_imprime(l);
        puts("");
        printf("Lista 2: ");
        lst_imprime(l2);
        puts("");
        lst_libera(l2);
    }else{
        puts("Elemento nao encontrado");
    }
    lst_libera(l);
    return 0;
}