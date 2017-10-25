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

int valor_posicao(Elem *li, int pos){
    if(li == NULL){
        cout << "Lista Vazia, posição inválida!";
        return -1;
    }
    int tamanho = tamanho_lista(li);
    if(pos <= tamanho && pos > 0){
        int cont = 1;
        Elem *aux = li;
        int valor;
        while(aux->prox != li){
            if(cont == pos){
                valor = aux->valor;
                return valor;
            }
            cont++;
            aux = aux->prox;
        }
    }else{
        cout << "Posição Inválida!";
        return -1;
    }
}

int consulta_lista_pos(Elem* li, int pos){
    if(li == NULL || pos <= 0)
        return 0;
    Elem *no = li;
    int i = 1;
    while(no->prox != li && i < pos){
        no = no->prox;
        i++;
    }
    if(i != pos)
        return 0;
    else{
        cout<< "Valor do elemento na posicao: "<<  no->valor;
        return 1;
    }
}

int consulta_lista_mat(Elem* li, int val){
    if(li == NULL)
        return 0;
    Elem *no = li;
    int contador = 0;
    while(no->prox != li && no->valor != val){
        contador++;
        no = no->prox;
    }
    if(no->valor != val){
        cout << "Valor não encontrado!";
        return 0;
    }
    else{
        cout<< "Valor encontrado na posição "<< contador;
        return 0;
    }
}

Elem* insere_lista_final(Elem* li, int val){
    Elem *no = new Elem;
    if(no == NULL)
        return li;
    no->valor = val;
    if(li == NULL){//lista vazia: insere início
        li = no;
        no->prox = no;
    }else{
        Elem *aux = li;
        while(aux->prox != li){
            aux = aux->prox;
        }
        aux->prox = no;
        no->prox = li;
    }
    return li;
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

Elem* insere_lista_ordenada(Elem* li, int val){
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return li;
    no->valor = val;
    if(li == NULL){//insere início
        li = no;
        no->prox = no;
        return li;
    }
    else{
        if(li->valor > val){//insere início
            Elem *atual = li;
            while(atual->prox != li)//procura o último
                atual = atual->prox;
            no->prox = li;
            atual->prox = no;
            li = no;
            return li;
        }
        Elem *ant = li, *atual = li->prox;
        while(atual != li && atual->valor < val){
            ant = atual;
            atual = atual->prox;
        }
        ant->prox = no;
        no->prox = atual;
        return li;
    }
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

