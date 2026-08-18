#include "monitor.h"
#include "teste.h"

int main(void) {
    Sensor sensor = {.tag = "TMP-01", .quantidade = 0};

    VERIFICAR(sensor_adicionar_leitura(&sensor, 24.5),
              "deve adicionar uma leitura valida");
    VERIFICAR(sensor.quantidade == 1, "deve atualizar a quantidade");
    VERIFICAR_PROXIMO(sensor.leituras[0], 24.5, "deve armazenar a leitura");

    VERIFICAR(!sensor_adicionar_leitura(&sensor, 126.0),
              "nao deve adicionar leitura invalida");
    VERIFICAR(sensor.quantidade == 1,
              "leitura invalida nao deve alterar a quantidade");
    VERIFICAR(!sensor_adicionar_leitura(NULL, 25.0),
              "deve rejeitar ponteiro de sensor nulo");

    sensor.quantidade = MAX_LEITURAS;
    VERIFICAR(!sensor_adicionar_leitura(&sensor, 25.0),
              "nao deve ultrapassar a capacidade do vetor");

    NoLeitura *lista = NULL;
    VERIFICAR(lista_quantidade(lista) == 0, "lista vazia deve ter tamanho zero");
    VERIFICAR(!lista_adicionar(NULL, 24.5), "deve rejeitar ponteiro de inicio nulo");
    VERIFICAR(lista_adicionar(&lista, 24.5), "deve adicionar o primeiro no");
    VERIFICAR(lista_adicionar(&lista, 80.0), "deve adicionar ao final da lista");
    VERIFICAR(!lista_adicionar(&lista, 126.0), "lista deve rejeitar leitura invalida");
    VERIFICAR(lista_quantidade(lista) == 2, "lista deve conter dois nos");
    if (lista != NULL) {
        VERIFICAR_PROXIMO(lista->valor, 24.5, "primeiro no incorreto");
        if (lista->proximo != NULL) {
            VERIFICAR_PROXIMO(lista->proximo->valor, 80.0, "segundo no incorreto");
        } else {
            VERIFICAR(false, "segundo no nao foi encadeado");
        }
    } else {
        VERIFICAR(false, "primeiro no nao foi criado");
    }

    bool possui_dados = false;
    VERIFICAR_PROXIMO(lista_media(lista, &possui_dados), 52.25, "media da lista incorreta");
    VERIFICAR(possui_dados, "lista preenchida deve informar que possui dados");
    VERIFICAR_PROXIMO(lista_media(NULL, &possui_dados), 0.0,
                      "lista vazia deve produzir media zero");
    VERIFICAR(!possui_dados, "lista vazia deve informar ausencia de dados");

    lista_liberar(&lista);
    lista_liberar(NULL);
    VERIFICAR(lista == NULL, "lista deve ficar nula depois de liberar os nos");
    lista_liberar(&lista);

    return finalizar_testes("03");
}
