# Roteiro de evolução: do monitor em C ao modelo em C++

Este repositório preserva um mesmo problema para duas etapas de aprendizagem:

1. revisar algoritmos, memória e programação procedural em C;
2. refatorar a solução em C++ para discutir responsabilidades, encapsulamento e legibilidade.

## Estado procedural ao final da revisão

| Elemento em C | Responsabilidade atual | Candidato em C++ |
|---|---|---|
| `Sensor` | agrupar tag, vetor e quantidade | classe `Sensor` |
| `sensor_adicionar_leitura` | preservar faixa e capacidade | método `Sensor::adicionarLeitura` |
| `calcular_estatisticas` | derivar mínima, máxima e média | consulta de `Sensor` ou serviço de estatísticas |
| `NoLeitura` e funções `lista_*` | controlar nós e memória dinâmica | contêiner da biblioteca padrão |
| `salvar_leituras` e `carregar_leituras` | persistir e reconstruir dados | `RepositorioLeituras` |
| `exibir_relatorio` | formatar uma visão dos dados | `RelatorioSensor` ou camada de apresentação |

Essa tabela é uma hipótese de refatoração, não uma regra de que toda função deve virar método.

## Fluxo concentrado e dependente de condições

Uma versão monolítica poderia abrir arquivo, ler valores, validar, calcular e escolher a saída dentro de uma única função. Cada `if`, `while` e `switch` acrescenta um caminho possível. Quando as decisões ficam concentradas, aumenta o número de combinações que precisam ser compreendidas e testadas naquele trecho.

A solução procedural deste repositório já inicia a melhora:

```c
if (carregar_leituras(caminho, &historico)) {
    bool possui_dados;
    double media = lista_media(historico, &possui_dados);

    if (possui_dados) {
        printf("Media: %.1f C\n", media);
    }
}

lista_liberar(&historico);
```

As decisões internas de abertura, leitura, validação e encadeamento ficam atrás de funções com entradas, resultados e erros definidos. C permite essa boa decomposição, embora uma `struct` pública ainda possa ser alterada diretamente.

## Direção da refatoração em C++

```cpp
class Sensor {
public:
    explicit Sensor(std::string tag);
    bool adicionarLeitura(double valor);
    Estatisticas estatisticas() const;

private:
    std::string tag_;
    std::vector<double> leituras_;
};

class RepositorioLeituras {
public:
    void salvar(const Sensor& sensor, const std::filesystem::path& caminho) const;
    Sensor carregar(const std::filesystem::path& caminho) const;
};
```

O fluxo de uso pode ficar menor:

```cpp
Sensor sensor = repositorio.carregar("leituras.txt");
RelatorioSensor::exibir(sensor);
```

O ganho esperado vem de decisões de projeto combinadas:

- `Sensor` protege sua coleção e seus invariantes;
- o contêiner gerencia memória sem chamadas manuais a `malloc` e `free`;
- o repositório concentra detalhes de arquivo;
- cada componente possui um comportamento esperado menor e testes mais focados;
- o fluxo principal coordena objetos, sem repetir regras internas.

POO não reduz automaticamente complexidade ciclomática. Um método grande e repleto de condições continua complexo. A melhora ocorre quando as responsabilidades e decisões são decompostas de maneira coesa.

## Ponte para Python

Python oferece `list` como coleção dinâmica de uso geral; sua representação não é uma lista encadeada. C++ oferece diferentes contêineres, como `std::vector` e `std::list`, com características distintas. A lista encadeada manual em C torna visíveis nós, endereços e liberação de memória, enquanto essas abstrações oferecem gerenciamento automático dos recursos internos.

## Evidências para comparar antes e depois

- quantidade de pontos que podem alterar diretamente o estado;
- tamanho e número de decisões de cada função ou método;
- necessidade de gerenciamento manual de memória;
- facilidade de testar uma responsabilidade isolada;
- clareza do fluxo principal;
- possibilidade de criar um objeto em estado inválido.
