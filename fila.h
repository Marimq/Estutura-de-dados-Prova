#ifndef FILA_H
#define FILA_H

#define MAX 100

typedef struct {
    int chave;
    int prioridade;
} Item;


typedef struct No {
    Item dados;
    struct No* prox;
    struct No* ant;
} No;


typedef struct {
    No* inicio;
    No* fim;
    int tamanho;
} FP;



FP* fp_criar(void);
void fp_destruir(FP** ref);

int fp_inserir(FP* f, Item x);
int fp_remover_max(FP* f, Item* out);
int fp_topo(const FP* f, Item* out);
int fp_atualizar(FP* f, int chave, int nova_prioridade);
int fp_remover_chave(FP* f, int chave, Item* out);

int fp_vazia(const FP* f);
int fp_tamanho(const FP* f);
int fp_listar(const FP* f);

#endif
