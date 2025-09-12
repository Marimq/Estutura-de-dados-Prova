#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

Fila* cria_fila(){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    if(f != NULL){
        f->qtd = 0;
    }
    return f;
}

void libera_fila(Fila* f){
    free(f);
}

int fila_vazia(Fila* f){
    if(f == NULL){
        return 1;
    } else {
        return (f->qtd == 0);
    }
}

int fila_cheia(Fila* f){
    if(f == NULL){
        return 0;
    } else {
        return (f->qtd == MAX);
    }
}

int busca_linear(Fila* f, int valor){
    if(f == NULL || f->qtd == 0){
        return -1;
    } else {
        for(int i = 0; i < f->qtd; i++){
            if(f->dados[i] == valor){
                return i;
            }
        }
    }
    return -1;
}

int insere_fim(Fila* f, int valor){
    if(f == NULL || fila_cheia(f)){
        return 0;
    } else {
        if(busca_linear(f, valor) != -1){
            return 0;
        } else {
            f->dados[f->qtd] = valor;
            f->qtd++;
            return 1;
        }
    }
}

int remove_fila(Fila* f){
    if(f == NULL || fila_vazia(f)){
        return -1;
    } else {
        int retorno = f->dados[0];
        for (int j = 0; j < f->qtd - 1; j++){
            f->dados[j] = f->dados[j + 1];
        }
        f->qtd--;
        return retorno;
    }
}

void listar_fila(Fila* f){
    if(fila_vazia(f)){
        printf("Fila está vazia\n");
    } else {
        printf("Fila: ");
        for(int i = 0; i < f->qtd; i++){
            printf("%d ", f->dados[i]);
        }
        printf("\n");
    }
}

void bubble_sort(Fila* f, int ordem){
    if(f == NULL || f->qtd < 2){
        return;
    } else {
        int aux;
        for(int i = 0; i < f->qtd - 1; i++){
            int trocou = 0;
            for(int j = 0; j < f->qtd - 1 - i; j++){
                if((ordem == 1 && f->dados[j] > f->dados[j+1]) ||
                   (ordem == 0 && f->dados[j] < f->dados[j+1])){
                    aux = f->dados[j];
                    f->dados[j] = f->dados[j+1];
                    f->dados[j+1] = aux;
                    trocou = 1;
                }
            }
            if(!trocou){
                break;
            }
        }
    }
}

/*
Complexidade Bubble Sort:
- Melhor caso: O(n) (fila já ordenada)
- Pior caso: O(n²) (fila inversa)
*/
