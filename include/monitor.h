#ifndef MONITOR_H
#define MONITOR_H

#include <stdbool.h>
#include <stddef.h>

#define MAX_LEITURAS 10

typedef struct {
    char tag[16];
    double leituras[MAX_LEITURAS];
    size_t quantidade;
} Sensor;

typedef struct {
    double minima;
    double maxima;
    double media;
} Estatisticas;

double celsius_para_fahrenheit(double temperatura);
bool leitura_valida(double valor);
const char *classificar_leitura(double valor);
bool calcular_estatisticas(const Sensor *sensor, Estatisticas *resultado);
bool sensor_adicionar_leitura(Sensor *sensor, double valor);
void exibir_relatorio(const Sensor *sensor);

#endif
