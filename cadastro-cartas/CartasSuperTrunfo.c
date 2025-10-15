#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

int main() {
  // Área para definição das variáveis para armazenar as propriedades das cidades
  /* Variáveis da Carta 1 */
  char estado1;
  char codigo1[4];         /* ex: "A01" -> 3 chars + '\0' */
  char nomeCidade1[100];
  int populacao1;
  float area1;
  float pib1;
  int pontosTur1;

  /* Variáveis da Carta 2 */
  char estado2;
  char codigo2[4];
  char nomeCidade2[100];
  int populacao2;
  float area2;
  float pib2;
  int pontosTur2;

  // Área para entrada de dados
  /* Entrada de dados - Carta 1 */
  printf("Carta 1:\n");
  printf("Estado (A-H): ");
  scanf(" %c", &estado1);

  printf("Código da Carta (ex: A01): ");
  scanf(" %3s", codigo1);

  printf("Nome da Cidade: ");
  scanf(" %99[^\n]", nomeCidade1);

  printf("População: ");
  scanf("%d", &populacao1);

  printf("Área (km²): ");
  scanf("%f", &area1);

  printf("PIB (em bilhões de reais): ");
  scanf("%f", &pib1);

  printf("Número de Pontos Turísticos: ");
  scanf("%d", &pontosTur1);

  printf("\n"); /* separador */

  /* Entrada de dados - Carta 2 */
  printf("Carta 2:\n");
  printf("Estado (A-H): ");
  scanf(" %c", &estado2);

  printf("Código da Carta (ex: B02): ");
  scanf(" %3s", codigo2);

  printf("Nome da Cidade: ");
  scanf(" %99[^\n]", nomeCidade2);

  printf("População: ");
  scanf("%d", &populacao2);

  printf("Área (km²): ");
  scanf("%f", &area2);

  printf("PIB (em bilhões de reais): ");
  scanf("%f", &pib2);

  printf("Número de Pontos Turísticos: ");
  scanf("%d", &pontosTur2);

  printf("\n--- Dados cadastrados ---\n\n");

  // Área para exibição dos dados da cidade
  /* Exibição - Carta 1 */
  printf("Carta 1:\n");
  printf("Estado: %c\n", estado1);
  printf("Código: %s\n", codigo1);
  printf("Nome da Cidade: %s\n", nomeCidade1);
  printf("População: %d\n", populacao1);
  printf("Área: %.2f km²\n", area1);
  printf("PIB: %.2f bilhões de reais\n", pib1);
  printf("Número de Pontos Turísticos: %d\n", pontosTur1);

  printf("\n");

  /* Exibição - Carta 2 */
  printf("Carta 2:\n");
  printf("Estado: %c\n", estado2);
  printf("Código: %s\n", codigo2);
  printf("Nome da Cidade: %s\n", nomeCidade2);
  printf("População: %d\n", populacao2);
  printf("Área: %.2f km²\n", area2);
  printf("PIB: %.2f bilhões de reais\n", pib2);
  printf("Número de Pontos Turísticos: %d\n", pontosTur2);

return 0;
} 
