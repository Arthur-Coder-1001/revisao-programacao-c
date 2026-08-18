# Guia docente

## Finalidade

O repositório sustenta uma revisão prática de C em três aulas de 100 minutos. A sequência usa quatro branches cumulativas, atividades de casa entre os encontros e GitHub Actions como feedback formativo. O prazo final recomendado é a semana seguinte à terceira aula.

| Aula | Escopo | Ponto de parada |
|---|---|---|
| 1 | etapas 01 e 02: dados, decisões, vetores e funções | estatísticas validadas |
| 2 | etapa 03: ponteiros, lista e memória dinâmica | lista demonstrada e liberada |
| 3 | etapa 04: arquivos, acesso ao estado e consolidação | persistência validada e revisão respondida |

| Etapa | Branch | Competências verificadas |
|---|---|---|
| 01 | `pratica/01-fundamentos` | expressões, tipos, condições e fronteiras |
| 02 | `pratica/02-vetores-funcoes` | laços, vetores, funções e ausência de dados |
| 03 | `pratica/03-struct-ponteiros` | `struct`, ponteiros, alocação e lista encadeada |
| 04 | `pratica/04-arquivos` | abertura, escrita, leitura, fechamento e reconstrução da lista |

Os testes são cumulativos: cada etapa repete todas as anteriores. Isso detecta regressões durante a evolução do código.

## Preparação antes da aula

1. Confirme que o workflow da `main` está habilitado.
2. Faça um fork de teste com uma conta secundária, se disponível.
3. Confirme que um push em cada nome de branch inicia o workflow correto.
4. Mantenha a solução de referência fora deste repositório público.
5. Disponibilize o material conceitual com os comportamentos esperados, a agenda das três aulas e as atividades de casa.

## Limites da validação

Os testes ficam visíveis porque o repositório é público. Portanto, a CI oferece feedback e verifica contratos observáveis, mas não comprova autoria nem entendimento. A avaliação deve incluir leitura do código, histórico dos commits e defesa oral curta.

Um participante também controla o próprio fork e pode modificar o workflow ou os testes. Para avaliação somativa, use GitHub Classroom com testes protegidos ou valide a entrega em infraestrutura controlada pelo docente.

## Diagnóstico rápido

- workflow não iniciou: conferir se Actions foi habilitado no fork e se o nome da branch é exato;
- compilação falhou: reproduzir `make clean && make build`;
- teste falhou: executar `make test ETAPA=NN` e ler a primeira mensagem;
- push foi ao repositório errado: conferir `git remote -v`;
- etapa perdeu código anterior: confirmar que a nova branch partiu da `main` atualizada.
