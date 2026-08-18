# Como realizar as atividades

Este repositório é distribuído por fork. Cada participante trabalha no próprio fork e mantém a `main` como registro das etapas concluídas.

## Antes de alterar o código

```bash
git switch main
git status
git pull --ff-only origin main
```

O diretório de trabalho deve estar limpo. Crie a branch exata da etapa:

```bash
git switch -c pratica/01-fundamentos
```

## Escopo permitido

Implemente somente `src/monitor.c`. Preserve as assinaturas e os comportamentos esperados descritos em `include/monitor.h`, nas instruções e nos testes. Não altere esses arquivos, o `Makefile` ou o workflow para contornar uma falha.

## Antes do push

```bash
make clean
make build
make test ETAPA=01
git diff --check
git status
```

Substitua a etapa conforme a branch atual. Leia o diff antes do commit e registre somente arquivos relacionados à atividade.

## Depois do push

Abra a aba **Actions** do seu fork e consulte a execução associada ao commit. Quando houver uma falha:

1. abra o job **Validar**;
2. identifique se a falha ocorreu na compilação ou nos testes;
3. reproduza o comando localmente;
4. corrija a causa, sem remover o teste;
5. envie outro commit na mesma branch.

Uma validação verde confirma apenas os casos automatizados. A solução ainda deve ser legível e tecnicamente defensável.

## Sincronizar mudanças do repositório original

Quando houver uma atualização anunciada:

```bash
git switch main
git fetch upstream
git merge --ff-only upstream/main
git push origin main
```

Não execute essa sincronização com alterações locais pendentes.
