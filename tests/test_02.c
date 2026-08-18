#include "monitor.h"
#include "teste.h"

int main(void) {
    Sensor sensor = {
        .tag = "TMP-01",
        .leituras = {24.5, 25.0, 80.0, 23.8, 126.0},
        .quantidade = 5,
    };
    Estatisticas resultado;

    VERIFICAR(calcular_estatisticas(&sensor, &resultado),
              "deve haver estatisticas quando existem leituras validas");
    VERIFICAR_PROXIMO(resultado.minima, 23.8, "minima incorreta");
    VERIFICAR_PROXIMO(resultado.maxima, 80.0, "maxima incorreta");
    VERIFICAR_PROXIMO(resultado.media, 38.325, "media incorreta");

    Sensor sem_validas = {
        .tag = "TMP-02",
        .leituras = {126.0, -41.0},
        .quantidade = 2,
    };
    VERIFICAR(!calcular_estatisticas(&sem_validas, &resultado),
              "deve informar ausencia de leituras validas");
    VERIFICAR(!calcular_estatisticas(NULL, &resultado),
              "deve rejeitar ponteiro de sensor nulo");
    VERIFICAR(!calcular_estatisticas(&sensor, NULL),
              "deve rejeitar ponteiro de resultado nulo");

    Sensor quantidade_impossivel = {.tag = "TMP-03", .quantidade = MAX_LEITURAS + 1};
    VERIFICAR(!calcular_estatisticas(&quantidade_impossivel, &resultado),
              "deve rejeitar quantidade maior que a capacidade do vetor");

    return finalizar_testes("02");
}
