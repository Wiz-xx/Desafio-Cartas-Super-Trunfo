#include <stdio.h>
#include <string.h>

#define ESTRELA 0
#define CARTAS 100

typedef struct {

    char estado[50];
    int codigo;
    char nomeCidade[50];
    int populacao;  // numero de habitantes
    float pib;  // em bilhoes de R$
    float area;  // em km²
    int pontosTuristicos;

    // Atributos derivados 
    float densidadePopulacional; 
    float pibPerCapita;
} CARTA;

// Função para calcular propriedades derivadas 
void calcularPropriedades(CARTA *c){
    if (c->area > 0)
        c->densidadePopulacional = c->populacao / c->area;
    else 
        c->densidadePopulacional = 0;

    if (c->populacao > 0)
        c->pibPerCapita = (c->pib * 1000000000) / c->populacao;
    
    else
        c->pibPerCapita = 0;
}

void cadastrarCarta(CARTA *c) {
    printf("\n--- Cadastro de Carta ---\n");
    printf("Estado: ");
    scanf(" %[^\n]", c->estado);

    printf("Codigo da cidade: ");
    scanf("%d", &c->codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", c->nomeCidade);

    printf("Populacao: "); 
    scanf("%d", &c->populacao);

    printf("Pib (em bilhoes R$): ");
    scanf("%f", &c->pib);

    printf("Area (em km²): ");
    scanf("%f", &c->area);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &c->pontosTuristicos);

    calcularPropriedades(c); // Chama função para calcular densidade e Pib per capita
}
// Função para exibir as Cartas ;-;
void exibirCarta(CARTA c) {
    printf("\n--- Carta da Cidade ---\n");
    printf("Estado: %s\n", c.estado);
    printf("Codigo: %d\n", c.codigo);
    printf("Cidade: %s\n", c.nomeCidade);
    printf("Populacao: %d habitantes\n", c.populacao);
    printf("PIB: R$ %.2f bilhoes\n", c.pib); 
    printf("Area: %.2f km²\n", c.area);
    printf("Pontos turisticos: %d\n", c.pontosTuristicos);
    printf("Densidade populicional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", c.pibPerCapita);
}
int main(){
    CARTA cartas[CARTAS];
    int total = 0;
    int opcao;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Cadastrar nova carta\n");
        printf("2. Exibir todas as cartas\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

       switch (opcao){
        case 1:
            if (total < CARTAS){
                cadastrarCarta(&cartas[total]);
                total++;
            }else{
                printf("Limite maximo de cartos atingido.\n");
            }
            break;
        case 2: 
            for (int i = 0; i < total; i++){
                exibirCarta(cartas[i]);
            }
            break;
        case 0: 
            printf("Encerrando o programa\n");
            break;
        default:
            printf("Opcao invalida\n");
       }
    } while (opcao != 0);
    return ESTRELA;
}
