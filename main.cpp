#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include "ListaCirc.h"
using namespace std;
int main(){
    Elem* li = cria_lista();
    printf("Tamanho: %d\n\n\n\n",tamanho_lista(li));
    li = insere_lista_final(li,10);
    li = insere_lista_inicio(li,20);
    li = insere_lista_inicio(li,30);
    li = insere_lista_inicio(li,40);
    imprime_lista(li);
    int valor=  valor_posicao(li, 3);
    cout<<"Valor da posição "<< valor << endl;
    printf("\n\n\n\n Tamanho: %d\n",tamanho_lista(li));
    //li = remove_lista(li,10);
    printf("\n\n\n\n Tamanho: %d\n",tamanho_lista(li));
    printf("\n\n\n\n Errado:  \n");
    //libera_lista(li);
    //imprime_lista(li);
    printf("\n\n\n\n Tamanho: %d\n",tamanho_lista(li));
    system("pause");
    return 0;
}

