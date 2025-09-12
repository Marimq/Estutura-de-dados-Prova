#ifndef FILA_H
#define FILA_H

#define MAX 10 

typedef struct {
    int dados[MAX];
    int qtd;
} Fila;

Fila* cria_fila();
void libera_fila(Fila* f);

int fila_vazia(Fila* f);
int fila_cheia(Fila* f);

int busca_linear(Fila* f, int valor);
int insere_fim(Fila* f, int valor);
int remove_fila(Fila* f);
void listar_fila(Fila* f);


void bubble_sort(Fila* f, int ordem);

#endif
