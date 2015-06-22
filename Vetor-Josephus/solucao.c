#include "filavet.h"
int main()
{   int c;        
    int i;
    srand( (unsigned)time(NULL) );
    Fila* f;
        f=fila_cria();
        for (i=1;i<11;i++){
            fila_insere(f,i);
        }
    while((f->n)>1){
        int x;
        x=sorteio();
            printf("\nNúmero %d sorteado.\n",x);
        if(i>0){
            f->ini=((f->ini+x)%f->n);//sendo >0 anda pra frente
            if(f->vet[f->ini]=99)
                f->ini++;
        }else{
            f->ini=((f->n-(f->ini-x))%f->n);
            if(f->vet[f->ini]=99)
                f->ini--;
        }
        f->vet[f->ini]=99;
        c=fila_retira(f);
        printf("Soldado %d removido.",c);
    }
    c=fila_retira(f);
    printf("O Soldado %d foi escolhido",c);
}