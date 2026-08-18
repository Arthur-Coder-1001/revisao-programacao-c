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

typedef struct NoLeitura {
    double valor;
    struct NoLeitura *proximo;
} NoLeitura;

typedef enum {
    LEITURA_INVALIDA,
    LEITURA_NORMAL,
    LEITURA_ALERTA
} EstadoLeitura;

double celsius_para_fahrenheit(double temperatura);
bool leitura_valida(double valor);
EstadoLeitura classificar_leitura(double valor);
const char *estado_como_texto(EstadoLeitura estado);
bool calcular_estatisticas(const Sensor *sensor, Estatisticas *resultado);
bool sensor_adicionar_leitura(Sensor *sensor, double valor);
void exibir_relatorio(const Sensor *sensor);
bool lista_adicionar(NoLeitura **inicio, double valor);
size_t lista_quantidade(const NoLeitura *inicio);
double lista_media(const NoLeitura *inicio, bool *possui_dados);
void lista_liberar(NoLeitura **inicio);
bool salvar_leituras(const char *caminho, const NoLeitura *inicio);
bool carregar_leituras(const char *caminho, NoLeitura **inicio);

#endif
