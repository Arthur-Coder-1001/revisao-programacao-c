# Prática de revisão de programação em C

Repositório-base das atividades cumulativas de algoritmos e programação procedural em C.

[![Validação da prática](https://github.com/rafaelrezo/revisao-programacao-c/actions/workflows/validacao.yml/badge.svg)](https://github.com/rafaelrezo/revisao-programacao-c/actions/workflows/validacao.yml)

Neste repositório, **contrato de uma função** significa o acordo sobre o que ela recebe, o que faz, o que devolve e quais entradas ou erros precisa rejeitar. O cabeçalho, as instruções e os testes descrevem esse comportamento esperado.

## Requisitos

- Git configurado para acessar o GitHub;
- GCC com suporte a C17;
- GNU Make;
- terminal Linux, macOS ou Ubuntu no WSL.

## Fluxo de trabalho

1. Faça um fork deste repositório para sua conta.
2. Clone o seu fork, não o repositório original.
3. Trabalhe nas branches indicadas, em ordem.
4. Antes do push, execute localmente `make build` e o teste da etapa.
5. Depois do push, consulte **Actions > Validação da prática** no seu fork.
6. Integre a branch à sua `main` somente depois que a validação ficar verde.

| Etapa | Branch obrigatória | Teste local |
|---|---|---|
| 1. Tipos, expressões e decisões | `pratica/01-fundamentos` | `make test ETAPA=01` |
| 2. Vetores e funções | `pratica/02-vetores-funcoes` | `make test ETAPA=02` |
| 3. `struct` e ponteiros | `pratica/03-struct-ponteiros` | `make test ETAPA=03` |
| 4. Arquivos | `pratica/04-arquivos` | `make test ETAPA=04` |

Depois de concluir as implementações, observe o comportamento das estruturas com:

```bash
make demo ETAPA=03
make demo ETAPA=04
```

O primeiro comando mostra inserção, percurso, média e liberação da lista. O segundo cria um arquivo, recupera seus valores e mostra as leituras reconstruídas.

As especificações, os checkpoints e as saídas esperadas estão no material da disciplina. Não altere `.github/`, `tests/`, `include/monitor.h` nem o `Makefile` para contornar uma validação.

Se o GitHub mostrar um aviso de que os workflows estão desabilitados no fork, abra **Actions** e confirme a habilitação. O workflow é executado no seu fork depois de um push para um dos nomes de branch previstos.

## Comandos iniciais

```bash
make build
make run
```

O código inicial compila, mas as funções contêm pontos de implementação. Os testes falham até que os requisitos de cada etapa sejam atendidos. Cada validação também repete os testes das etapas anteriores para detectar regressões.

## Estrutura

```text
.
├── .github/workflows/validacao.yml
├── include/monitor.h
├── src/main.c
├── src/monitor.c
├── src/demo_lista.c
├── src/demo_arquivo.c
├── tests/
├── CONTRIBUTING.md
├── EVOLUCAO_POO.md
└── GUIA_DOCENTE.md
```

- `include/monitor.h` define o contrato que deve ser preservado;
- `src/monitor.c` concentra os pontos de implementação;
- `tests/` contém a validação automática visível;
- `CONTRIBUTING.md` detalha o fluxo de branches e diagnóstico;
- `EVOLUCAO_POO.md` preserva o mapa de refatoração do mesmo código para C++;
- `GUIA_DOCENTE.md` documenta preparação, limites e uso formativo.

## Licença

Distribuído sob a licença MIT. Consulte `LICENSE`.
