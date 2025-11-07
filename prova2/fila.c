#include "fila.h"
#include <stdio.h>
#include <stdlib.h>


FP* fp_criar(void) {
    FP* f = (FP*) malloc(sizeof(FP));
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
        f->tamanho = 0;
    }
    return f;
}


void fp_destruir(FP** ref) {
    if (ref != NULL && *ref != NULL) {
        No* atual = (*ref)->inicio;
        while (atual != NULL) {
            No* prox = atual->prox;
            free(atual);
            atual = prox;
        }
        free(*ref);
        *ref = NULL;
    }
}


int fp_inserir(FP* f, Item x) {
    if (f == NULL) return 0;

    
    No* aux = f->inicio;
    while (aux != NULL) {
        if (aux->dados.chave == x.chave)
            return 0;
        aux = aux->prox;
    }

    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return 0;

    novo->dados = x;
    novo->prox = novo->ant = NULL;

 
    if (f->inicio == NULL) {
        f->inicio = f->fim = novo;
    }
    else {
        No* atual = f->inicio;
        while (atual != NULL && atual->dados.prioridade >= x.prioridade)
            atual = atual->prox;

        if (atual == f->inicio) {
            
            novo->prox = f->inicio;
            f->inicio->ant = novo;
            f->inicio = novo;
        }
        else if (atual == NULL) {
            
            novo->ant = f->fim;
            f->fim->prox = novo;
            f->fim = novo;
        }
        else {
            
            novo->prox = atual;
            novo->ant = atual->ant;
            atual->ant->prox = novo;
            atual->ant = novo;
        }
    }
    f->tamanho++;
    return 1;
}

int fp_remover_max(FP* f, Item* out) {
    if (f == NULL || f->inicio == NULL) return 0;

    No* temp = f->inicio;
    *out = temp->dados;

    f->inicio = temp->prox;
    if (f->inicio != NULL)
        f->inicio->ant = NULL;
    else
        f->fim = NULL;

    free(temp);
    f->tamanho--;
    return 1;
}

int fp_topo(const FP* f, Item* out) {
    if (f == NULL || f->inicio == NULL) return 0;
    *out = f->inicio->dados;
    return 1;
}


int fp_atualizar(FP* f, int chave, int nova_prioridade) {
    if (f == NULL || f->inicio == NULL) return 0;

    No* atual = f->inicio;
    while (atual != NULL && atual->dados.chave != chave)
        atual = atual->prox;

    if (atual == NULL) return 0;

    Item temp = atual->dados;
    temp.prioridade = nova_prioridade;

    
    if (atual->ant != NULL)
        atual->ant->prox = atual->prox;
    else
        f->inicio = atual->prox;

    if (atual->prox != NULL)
        atual->prox->ant = atual->ant;
    else
        f->fim = atual->ant;

    free(atual);
    f->tamanho--;

    
    return fp_inserir(f, temp);
}


int fp_remover_chave(FP* f, int chave, Item* out) {
    if (f == NULL || f->inicio == NULL) return 0;

    No* atual = f->inicio;
    while (atual != NULL && atual->dados.chave != chave)
        atual = atual->prox;

    if (atual == NULL) return 0;

    *out = atual->dados;

    if (atual->ant != NULL)
        atual->ant->prox = atual->prox;
    else
        f->inicio = atual->prox;

    if (atual->prox != NULL)
        atual->prox->ant = atual->ant;
    else
        f->fim = atual->ant;


    free(atual);
    f->tamanho--;
    return 1;
}


int fp_vazia(const FP* f) {
    return (f == NULL || f->tamanho == 0);
}


int fp_tamanho(const FP* f) {
    if (f == NULL) return -1;
    return f->tamanho;
}


int fp_listar(const FP* f) {
    if (f == NULL || f->inicio == NULL) return 0;

    No* atual = f->inicio;
    printf("Fila de prioridade:\n");

    while (atual != NULL) {

        printf("Chave: %d | Prioridade: %d\n", atual->dados.chave, atual->dados.prioridade);
        atual = atual->prox;
        
    }
    return 1;
}
