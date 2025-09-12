#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {
    Fila* f = cria_fila();
    int op, valor, pos;

    do {
        printf("\n--- MENU FILA ---\n");
        printf("1 - Inserir no fim\n");
        printf("2 - Remover do inicio\n");
        printf("3 - Pesquisar valor\n");
        printf("4 - Listar fila\n");
        printf("5 - Ordenar crescente\n");
        printf("6 - Ordenar decrescente\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                printf("Digite valor: ");
                scanf("%d", &valor);
                if (insere_fim(f, valor) == 1)
                    printf("Inserido com sucesso!\n");
                else
                    printf("Erro: fila cheia ou valor duplicado!\n");
                break;

            case 2:
                valor = remove_fila(f);
                if (valor == -1)
                    printf("Fila vazia!\n");
                else
                    printf("Removido: %d\n", valor);
                break;

            case 3:
                printf("Digite valor para buscar: ");
                scanf("%d", &valor);
                pos = busca_linear(f, valor);
                if (pos == -1)
                    printf("Nao encontrado!\n");
                else
                    printf("Encontrado na posicao %d\n", pos);
                break;

            case 4:
                listar_fila(f);
                break;

            case 5:
                bubble_sort(f, 1);
                printf("Fila ordenada em ordem crescente!\n");
                listar_fila(f);
                break;

            case 6:
                bubble_sort(f, 0);
                printf("Fila ordenada em ordem decrescente!\n");

                listar_fila(f);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while(op != 0);

    libera_fila(f);
    return 0;
}
