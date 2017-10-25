#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include "ListaCirc.h" //inclui os Protótipos
using namespace std;

//Definição do tipo lista
struct elemento{
    int valor;
    struct elemento *prox;
};
//typedef struct elemento Elem;
Elem* cria_lista(){
    return NULL;
}
void libera_lista(Elem* li){
   if(li != NULL){
        Elem *aux, *no = li;
        while(no->prox != li){//enquanto prox for diferente do inicio
            aux = no;
            no = no->prox;
            free(aux);
        }
        free(no);
        free(li);
   }
}





int consulta_lista_mat(Elem* li, int val){
    if(li == NULL)
        return 0;
    Elem *no = li;
    while(no->prox != li && no->valor != val)
        no = no->prox;
    if(no->valor != val)
        return 0;
    else{
        cout<< no->valor;
        return 1;
    }
}



Elem* insere_lista_inicio(Elem* li, int val){
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return li;
    no->valor = val;
    if(li == NULL){//lista vazia: insere início
        li = no;
        no->prox = no;//no aponta pra ele mesmo
    }else{
        Elem *aux = li;
        while(aux->prox != li){
            aux = aux->prox;
        }
        aux->prox = no;
        no->prox = li;
        li = no;
    }
    return li;
}


Elem* remove_lista_inicio(Elem* li){
    if(li == NULL)
        return li;

    if(li == li->prox){//lista fica vaza
        free(li);
        li = NULL;
        return li;
    }
    Elem *atual = li;
    while(atual->prox != li)//procura o último
        atual = atual->prox;

    Elem *no = li;
    atual->prox = no->prox;
    li = no->prox;
    free(no);
    return li;
}

Elem* remove_lista_final(Elem* li){
    if(li == NULL)
        return li;

    if(li == li->prox){//lista fica vaza
        free(li);
        li = NULL;
        return li;
    }
    Elem *ant, *no = li;
    while(no->prox != li){//procura o último
        ant = no;
        no = no->prox;
    }
    ant->prox = no->prox;
    free(no);
    return li;
}

Elem* remove_lista(Elem* li, int val){
    if(li == NULL)
        return li;
    Elem *no = li;
    if(no->valor == val){//remover do início
        if(no == no->prox){//lista fica vaza
            free(no);
            li = NULL;
            return li;
        }else{
            Elem *ult = li;
            while(ult->prox != li)//procura o último
                ult = ult->prox;
            ult->prox = li->prox;
            li = li->prox;
            free(no);
            return li;
        }
    }
    Elem *ant = no;
    no = no->prox;
    while(no != li && no->valor != val){
        ant = no;
        no = no->prox;
    }
    if(no == li)//não encontrado
        return li;

    ant->prox = no->prox;
    free(no);
    return li;
}

int tamanho_lista(Elem* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elem* no = li;
    do{
        cont++;
        no = no->prox;
    }while(no != li);
    return cont;
}


int lista_vazia(Elem* li){
    if(li == NULL)
        return 1;
    return 0;
}

void imprime_lista(Elem* li){
    if(li == NULL){
        cout<< "Lista Vazia"<<endl;
        return;
    }
    Elem* no = li;
    do{
        printf("Valor: %d\n",no->valor);
        printf("-------------------------------\n");
        no = no->prox;
    }while(no != li);
}

