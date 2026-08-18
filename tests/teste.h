#ifndef TESTE_H
#define TESTE_H

#include <math.h>
#include <stdio.h>
#include <string.h>

static int falhas = 0;

#define VERIFICAR(condicao, mensagem)                                           \
    do {                                                                         \
        if (!(condicao)) {                                                       \
            fprintf(stderr, "FALHOU: %s (linha %d)\n", mensagem, __LINE__);     \
            falhas++;                                                            \
        }                                                                        \
    } while (0)

#define VERIFICAR_PROXIMO(obtido, esperado, mensagem)                           \
    VERIFICAR(fabs((obtido) - (esperado)) < 0.0001, mensagem)

static int finalizar_testes(const char *etapa) {
    if (falhas == 0) {
        printf("SUCESSO: todos os testes da etapa %s passaram.\n", etapa);
        return 0;
    }

    fprintf(stderr, "TOTAL: %d teste(s) falharam na etapa %s.\n", falhas, etapa);
    return 1;
}

#endif
