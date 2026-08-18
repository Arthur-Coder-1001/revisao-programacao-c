#include "monitor.h"
#include "teste.h"

#include <stdio.h>

int main(void) {
    const char *caminho = "build/teste_leituras.txt";
    NoLeitura *original = NULL;
    NoLeitura *carregada = NULL;

    VERIFICAR(lista_adicionar(&original, 24.5), "deve preparar a primeira leitura");
    VERIFICAR(lista_adicionar(&original, 80.0), "deve preparar a segunda leitura");
    VERIFICAR(salvar_leituras(caminho, original), "deve salvar a lista em arquivo");
    VERIFICAR(carregar_leituras(caminho, &carregada), "deve carregar o arquivo salvo");
    VERIFICAR(lista_quantidade(carregada) == 2, "arquivo deve reconstruir dois nos");
    if (carregada != NULL) {
        VERIFICAR_PROXIMO(carregada->valor, 24.5, "primeira leitura carregada incorreta");
        if (carregada->proximo != NULL) {
            VERIFICAR_PROXIMO(carregada->proximo->valor, 80.0,
                              "segunda leitura carregada incorreta");
        } else {
            VERIFICAR(false, "segunda leitura nao foi reconstruida");
        }
    } else {
        VERIFICAR(false, "arquivo nao reconstruiu a lista");
    }

    VERIFICAR(!salvar_leituras(NULL, original), "deve rejeitar caminho nulo ao salvar");
    VERIFICAR(!carregar_leituras("build/arquivo-inexistente.txt", &carregada),
              "deve informar falha ao abrir arquivo inexistente");

    lista_liberar(&original);
    lista_liberar(&carregada);
    remove(caminho);
    return finalizar_testes("04");
}
