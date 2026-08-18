#include "monitor.h"
#include "teste.h"

int main(void) {
    VERIFICAR_PROXIMO(celsius_para_fahrenheit(0.0), 32.0,
                      "0 C deve corresponder a 32 F");
    VERIFICAR_PROXIMO(celsius_para_fahrenheit(25.0), 77.0,
                      "25 C deve corresponder a 77 F");

    VERIFICAR(!leitura_valida(-40.1), "valor abaixo de -40 deve ser invalido");
    VERIFICAR(leitura_valida(-40.0), "-40 deve pertencer a faixa valida");
    VERIFICAR(leitura_valida(125.0), "125 deve pertencer a faixa valida");
    VERIFICAR(!leitura_valida(125.1), "valor acima de 125 deve ser invalido");

    VERIFICAR(strcmp(classificar_leitura(126.0), "INVALIDA") == 0,
              "leitura fora da faixa deve ser INVALIDA");
    VERIFICAR(strcmp(classificar_leitura(79.9), "NORMAL") == 0,
              "leitura abaixo de 80 deve ser NORMAL");
    VERIFICAR(strcmp(classificar_leitura(80.0), "ALERTA") == 0,
              "leitura a partir de 80 deve ser ALERTA");

    return finalizar_testes("01");
}
