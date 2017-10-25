#ifndef LISTACIRC_H_INCLUDED
#define LISTACIRC_H_INCLUDED
typedef struct elemento Elem;
Elem* cria_lista();
void libera_lista(Elem* li);
int consulta_lista_pos(Elem* li, int pos);
int consulta_lista_mat(Elem* li, int val);
Elem* insere_lista_final(Elem* li, int val);
Elem* insere_lista_inicio(Elem* li, int val);
Elem* insere_lista_ordenada(Elem* li, int val);
Elem* remove_lista(Elem* li, int val);
Elem* remove_lista_inicio(Elem* li);
int valor_posicao(Elem *li, int pos);
Elem* remove_lista_final(Elem* li);
int tamanho_lista(Elem* li);
int lista_vazia(Elem* li);
void imprime_lista(Elem* li);
#endif // LISTACIRC_H_INCLUDED
