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

    return finalizar_testes("03");
}
