# Sistema de Cartas de Cidades

Este projeto em C implementa um sistema simples de cadastro e exibição de **cartas de cidades brasileiras**, contendo informações como população, PIB, área e pontos turísticos. O sistema também calcula automaticamente a **densidade populacional** e o **PIB per capita** com base nos dados fornecidos.

---

## Funcionalidades

- Cadastro de novas cartas com:
  - Estado
  - Código da cidade
  - Nome da cidade
  - População
  - PIB (em bilhões de R$)
  - Área (em km²)
  - Número de pontos turísticos
- Cálculo automático de:
  - Densidade populacional (hab/km²)
  - PIB per capita (R$)
- Exibição formatada das cartas cadastradas

---

## Lógica Derivada

- **Densidade populacional** = população / área
- **PIB per capita** = (PIB em R$) / população  
  *(o PIB fornecido é em bilhões de R$, por isso é multiplicado por 1.000.000.000 no cálculo)*

---

## Como Usar

1. Compile o código:
   ```bash
   gcc -o cartas cartas.c
