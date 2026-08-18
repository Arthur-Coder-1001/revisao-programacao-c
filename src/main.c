#include "monitor.h"

int main(void) {
    Sensor sensor = {.tag = "TMP-01", .quantidade = 0};

    sensor_adicionar_leitura(&sensor, 24.5);
    sensor_adicionar_leitura(&sensor, 25.0);
    sensor_adicionar_leitura(&sensor, 80.0);
    sensor_adicionar_leitura(&sensor, 23.8);
    sensor_adicionar_leitura(&sensor, 126.0);

    exibir_relatorio(&sensor);
    return 0;
}
