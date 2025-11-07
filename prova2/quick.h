#ifndef QUICK_H
#define QUICK_H

typedef struct {
    int codigo;
    int prioridade;
} Registro;


typedef enum {
    PIVO_PRIMEIRO,
    PIVO_ULTIMO,
    PIVO_MEDIANA_DE_TRES
} Estrategia;


void troca(Registro *a, Registro *b);
int compara(Registro a, Registro b);
void quick_sort(Registro *v, int n);

#endif
