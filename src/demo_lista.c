#include "monitor.h"

#include <stdio.h>

int main(void) {
    NoLeitura *inicio = NULL;

    printf("Lista inicial: %zu no(s)\n", lista_quantidade(inicio));

    lista_adicionar(&inicio, 24.5);
    lista_adicionar(&inicio, 80.0);

    printf("Depois das insercoes: %zu no(s)\n", lista_quantidade(inicio));

    const NoLeitura *atual = inicio;
    size_t indice = 0;
    while (atual != NULL) {
        printf("No %zu: %.1f C\n", indice, atual->valor);
        atual = atual->proximo;
        indice++;
    }

    bool possui_dados = false;
    double media = lista_media(inicio, &possui_dados);
    if (possui_dados) {
        printf("Media: %.2f C\n", media);
    }

    lista_liberar(&inicio);
    printf("Depois de liberar: %zu no(s)\n", lista_quantidade(inicio));
    return 0;
}
