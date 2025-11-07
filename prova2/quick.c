#include "quick.h"


void troca(Registro *a, Registro *b) {
    Registro temp = *a;
    *a = *b;
    *b = temp;
}


int compara(Registro a, Registro b) {
   
    if (a.prioridade > b.prioridade) return -1;
    if (a.prioridade < b.prioridade) return 1;

    if (a.codigo < b.codigo) return -1;
    if (a.codigo > b.codigo) return 1;

    return 0;
}


void quick_sort(Registro *v, int n) {
    if (n <= 1) return;

    int i = 1, j = n - 1;
    Registro pivo = v[0];

    while (i <= j) {
        while (i < n && compara(v[i], pivo) < 0) i++;
        while (j > 0 && compara(v[j], pivo) > 0) j--;

        if (i <= j) {
            troca(&v[i], &v[j]);
            i++;
            j--;
        }
    }

    troca(&v[0], &v[j]); 
    quick_sort(v, j);           
    quick_sort(v + i, n - i);    
}
