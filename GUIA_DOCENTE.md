# Guia docente

## Finalidade

O repositório sustenta uma revisão prática de C em duas aulas presenciais de 100 minutos e uma terceira parte realizada em casa. A sequência usa quatro branches cumulativas e GitHub Actions como feedback formativo. O prazo final recomendado é a semana seguinte à segunda aula. Uma terceira aula pode ser reservada como contingência, revisão ou validação final, sem planejar uma quarta aula.

| Parte | Realização | Escopo | Ponto de parada |
|---|---|---|---|
| 1 | aula 1 | etapas 01 e 02: dados, decisões, vetores e funções | estatísticas encaminhadas ou validadas |
| 2 | aula 2 | etapa 03: ponteiros, lista e memória dinâmica | lista desenhada, demonstrada e encaminhada |
| 3 | casa | etapa 04: arquivos, acesso ao estado e consolidação | persistência validada e revisão entregue |

## Organização das duplas

- cada estudante mantém o próprio fork e envia a própria evidência;
- a dupla alterna os papéis de digitação e acompanhamento;
- ao final de cada parte, os integrantes revisam diff, resultado e CI um do outro;
- a revisão conjunta não substitui a capacidade individual de explicar o código;
- quando houver uso de IA, cada estudante registra o que aceitou, rejeitou e compreendeu.

## Evidências no Google Classroom

Crie três desafios separados:

| Desafio | Evidência principal | Reflexão individual |
|---|---|---|
| A — dados e controle | fork, CI da etapa 02 e commit | divisão por zero na média |
| B — ponteiros e lista | CI da etapa 03, commit e desenho | necessidade de `NoLeitura **` |
| C — arquivos e consolidação | CI da etapa 04, commit, demonstração e arquivo | lista temporária e contribuição da revisão em dupla |

O Classroom funciona como coleta de evidência e comunicação. O fork, os commits e a CI permanecem como fonte do código executável.

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
5. Disponibilize o material conceitual com os comportamentos esperados, a agenda das duas aulas e a parte 3 como atividade de casa.

## Critério para usar a terceira aula

Reserve a terceira aula somente se, no prazo intermediário, ocorrer uma destas condições:

- menos de 70% dos forks possuem a etapa 03 validada;
- uma falha conceitual sobre `NoLeitura **` aparece de forma recorrente;
- a maioria não consegue explicar o ciclo `malloc` → uso → `free`;
- a etapa 04 apresenta bloqueio coletivo que não pode ser resolvido por feedback escrito;
- a validação oral exige tempo adicional.

Caso contrário, mantenha a parte 3 como trabalho de casa e prossiga com o curso, evitando reservar preventivamente uma quarta aula.

## Limites da validação

Os testes ficam visíveis porque o repositório é público. Portanto, a CI oferece feedback e verifica contratos observáveis, mas não comprova autoria nem entendimento. A avaliação deve incluir leitura do código, histórico dos commits e defesa oral curta.

Um participante também controla o próprio fork e pode modificar o workflow ou os testes. Para avaliação somativa, use GitHub Classroom com testes protegidos ou valide a entrega em infraestrutura controlada pelo docente.

## Diagnóstico rápido

- workflow não iniciou: conferir se Actions foi habilitado no fork e se o nome da branch é exato;
- compilação falhou: reproduzir `make clean && make build`;
- teste falhou: executar `make test ETAPA=NN` e ler a primeira mensagem;
- push foi ao repositório errado: conferir `git remote -v`;
- etapa perdeu código anterior: confirmar que a nova branch partiu da `main` atualizada.
