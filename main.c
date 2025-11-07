#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "quick.h"

int main() {
    FP *f = criar_fila();
    int opc, codigo, prioridade, nova_prioridade;

    do {
        printf("\n=== MENU ===\n");
        printf("1 - Inserir item na fila\n");
        printf("2 - Atualizar prioridade\n");
        printf("3 - Remover do inicio\n");
        printf("4 - Listar fila\n");
        printf("5 - Ordenar (QuickSort - pivô primeiro)\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                printf("Digite codigo e prioridade: ");
                scanf("%d %d", &codigo, &prioridade);
                inserir_fim(f, codigo, prioridade);
                break;

            case 2:
                printf("Digite codigo e nova prioridade: ");
                scanf("%d %d", &codigo, &nova_prioridade);
                if (atualizar_item(f, codigo, nova_prioridade))
                    printf("Atualizado.\n");
                else
                    printf("Nao encontrado.\n");
                break;

            case 3:
                if (remover_inicio(f, &codigo, &prioridade))
                    printf("Removido: codigo=%d prioridade=%d\n", codigo, prioridade);
                else
                    printf("Fila vazia.\n");
                break;

            case 4:
                listar_fila(f);
                break;

            case 5: {
                if (fila_vazia(f)) {
                    printf("Fila vazia.\n");
                    break;
                }

                Registro vetor[100];
                copiar_para_vetor(f, vetor);

                quick_sort(vetor, f->tamanho);

                printf("\n--- Vetor ordenado (pivô primeiro) ---\n");
                for (int i = 0; i < f->tamanho; i++)
                    printf("(codigo=%d, prioridade=%d)\n", vetor[i].codigo, vetor[i].prioridade);
                break;
            }

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opc != 0);

    destruir_fila(&f);
    return 0;
}
