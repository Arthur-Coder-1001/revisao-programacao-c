#include "monitor.h"

#include <stdio.h>

int main(void) {
    const char *caminho = "build/leituras_demo.txt";
    NoLeitura *original = NULL;
    NoLeitura *carregada = NULL;

    lista_adicionar(&original, 24.5);
    lista_adicionar(&original, 80.0);

    if (!salvar_leituras(caminho, original)) {
        printf("Falha ao salvar %s\n", caminho);
        lista_liberar(&original);
        return 1;
    }
    printf("Arquivo salvo em: %s\n", caminho);

    if (!carregar_leituras(caminho, &carregada)) {
        printf("Falha ao carregar %s\n", caminho);
        lista_liberar(&original);
        return 1;
    }

    printf("Leituras recuperadas: %zu\n", lista_quantidade(carregada));
    const NoLeitura *atual = carregada;
    while (atual != NULL) {
        printf("Leitura recuperada: %.1f C\n", atual->valor);
        atual = atual->proximo;
    }

    lista_liberar(&original);
    lista_liberar(&carregada);
    return 0;
}
