#include <stdio.h>
#include <stdlib.h>

struct cel{
    int conteudo;
    struct cel *seg;
};

typedef struct cel celula;

void insira(int y, celula *lst);
void imprime(celula *lst);

int main(){

    celula c, *lst;

    c.seg = NULL;
    lst = &c;

    insira(50, lst);
    insira(10, lst);
    insira(20, lst);
    insira(30, lst);
    insira(7, lst);

    imprime(lst);



    return 0;
}


void insira(int y, celula *lst){
    celula  *nova;

    nova = (celula *) malloc(sizeof(celula));

    nova->conteudo = y;
    nova->seg = lst->seg;
    lst->seg = nova;

}   

void imprime(celula *lst){
    celula *p = lst->seg;

    while(p != NULL){
        printf("Conteudo: %d\n", p->conteudo);
        p = p->seg;
    }
}

void remove_tude(celula *lst){

    celula *p = lst->seg;
    celula *prox;

    while(p != NULL){
        prox = p->seg;
        free(p);
        p = prox;
    }
}