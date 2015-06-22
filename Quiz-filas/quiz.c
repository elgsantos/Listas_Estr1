#include "fila.h"
int main(){
    Fila *f;
    f=fila_cria();
    fila_insere(f,"Joao",1);
    fila_insere(f,"Maria",2);
    fila_insere(f,"Carlos",3);
    fila_insere(f,"Joana",4);
    puts(".::Participantes::.");
    fila_imprime(f);
    puts("..:Perguntas:..");
    Filap *fp;
    fp=filap_cria();
    insere_perg(fp,1,"1+1=2?");
    insere_perg(fp,0,"2+2=5?");
    insere_perg(fp,1,"4+1=5?");
    insere_perg(fp,1,"10+10=20?");
    insere_perg(fp,0,"10+1=12?");
    Pergunta *fpc=fp->ini;
    int i=0;//contador de perguntas feitas(extra)
    while(fila_conta(f)!=1){
        if(fpc==NULL){
            fpc=fp->ini;//se chegar ao fim das perguntas, repete
        }
        char r[3];
        int rp;
        printf("%s, %s(sim/nao): ",f->ini->nome,fpc->perg);
        scanf(" %[^\n]s",r);//recebe a resposta(sim/nao)
        if(strcmp(r,"sim")==0){
            rp=1;
        }else{
            rp=0;
        }
        if(rp==fpc->resp){
            puts("Resposta correta\n");
            char re[20];fila_retira(f,re);//retira e reinsere no final
            fila_insere(f,re,i);
        }else{
            puts("Resposta incorreta. ");
            char re[20];fila_retira(f,re);
            printf("%s, você está fora.\n\n",re);
        }
        fila_imprime(f);
        fpc=fpc->prox;
        i++;
    }
    char fim[20];
    fila_retira(f,fim);
    printf("Parabéns %s, você foi o vencedor do nosso QUIZ!!!\n",fim);
    printf("Foram realizadas %d perguntas.\n",i);
    fila_libera(f);
    libera_perguntas(fp);
}