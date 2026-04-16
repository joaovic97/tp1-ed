# tp1-ed
# Processador de Datas em C++

## Descrição

Este programa em C++ lê um arquivo de texto contendo nomes e três datas no formato `DDMMYY` (dia, mês e ano), ordena os nomes alfabeticamente e as datas cronologicamente, gerando um novo arquivo com os dados processados.

## Funcionalidades

- Leitura de arquivo `.txt` com formato específico
- Extração automática de nomes e datas
- Ordenação alfabética dos nomes
- Ordenação cronológica das datas para cada pessoa
- Geração de arquivo de saída com os dados processados
- Makefile automatizado para compilação e execução

## Formato do Arquivo de Entrada

Cada linha do arquivo de entrada deve conter um nome seguido por três datas no formato `DDMMYY` (6 dígitos cada), totalizando:

### Exemplo de entrada (`entrada.txt`):

SIS050765050765050765
LETICIA260326260326260326
JOAQUIM310799060605150280


Onde:
- `ISIS` é o nome
- `050765` é a primeira data (05/07/65)
- `050765` é a segunda data
- `050765` é a terceira data

## Formato do Arquivo de Saída

O arquivo de saída mantém o mesmo formato, porém:
- Os nomes são ordenados alfabeticamente
- As três datas de cada pessoa são ordenadas cronologicamente

### Exemplo de saída (`saida.txt`):

ISIS050765050765050765
JOAQUIM060605150280310799
LETICIA260326260326260326


No exemplo acima, para `JOAQUIM` as datas foram reordenadas de:
- Original: `310799`, `060605`, `150280`
- Ordenado: `060605` (06/06/05), `150280` (15/02/80), `310799` (31/07/99)

## Como Compilar e Executar

### Pré-requisitos

- Compilador C++ (g++ recomendado)
- Make (opcional, mas recomendado)
- Sistema operacional Linux, macOS ou Windows (com MinGW/WSL)

### Usando o Makefile (Recomendado)

**Compilar e executar automaticamente:**
```bash
make all
