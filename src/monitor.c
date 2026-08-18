#include "monitor.h"

#include <stdio.h>

double celsius_para_fahrenheit(double temperatura) {
    /* ETAPA 01: implemente a conversão. */
    return temperatura;
}

bool leitura_valida(double valor) {
    /* ETAPA 01: aceite valores entre -40.0 e 125.0, inclusive. */
    (void)valor;
    return false;
}

const char *classificar_leitura(double valor) {
    /* ETAPA 01: retorne "INVALIDA", "ALERTA" ou "NORMAL". */
    (void)valor;
    return "NAO_IMPLEMENTADO";
}

bool calcular_estatisticas(const Sensor *sensor, Estatisticas *resultado) {
    /* ETAPA 02: calcule mínima, máxima e média das leituras válidas. */
    (void)sensor;
    (void)resultado;
    return false;
}

bool sensor_adicionar_leitura(Sensor *sensor, double valor) {
    /* ETAPA 03: valide os ponteiros, a leitura e a capacidade do vetor. */
    (void)sensor;
    (void)valor;
    return false;
}

void exibir_relatorio(const Sensor *sensor) {
    /* ETAPA 03: substitua esta mensagem pelo relatório completo. */
    if (sensor != NULL) {
        printf("Sensor: %s\n", sensor->tag);
    }
}
