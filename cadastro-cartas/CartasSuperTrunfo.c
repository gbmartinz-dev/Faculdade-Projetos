#include <stdio.h>
#include <string.h>
#include <math.h>

/*
  Desafio Super Trunfo - Países (Nível Mestre)
  - Leitura de duas cartas (continua igual)
  - Menus dinâmicos para escolher 2 atributos distintos
  - Comparação por atributo (densidade: menor vence)
  - Soma dos atributos e decisão final (tratamento de empate)
  - Uso de switch, default, ternário e tratamento de entradas inválidas
*/

typedef struct {
  char estado;
  char codigo[4];
  char nome[100];
  int populacao;
  float area;
  float pib;
  int pontosTur;
} Carta;

/* Retorna o nome do atributo */
const char* nome_atributo(int escolha) {
  switch (escolha) {
    case 1: return "População";
    case 2: return "Área (km²)";
    case 3: return "PIB (bilhões de reais)";
    case 4: return "Número de Pontos Turísticos";
    case 5: return "Densidade Demográfica (hab/km²)";
    default: return "Atributo Desconhecido";
  }
}

/* Retorna o valor do atributo escolhido para a carta.
   Para densidade, trata divisão por zero retornando um valor muito grande. */
double valor_atributo(const Carta *c, int escolha) {
  switch (escolha) {
    case 1: return (double)c->populacao;
    case 2: return (double)c->area;
    case 3: return (double)c->pib;
    case 4: return (double)c->pontosTur;
    case 5: return (c->area == 0.0f) ? 1e30 : ((double)c->populacao / (double)c->area);
    default: return 0.0;
  }
}

/* Exibe menu de atributos; se exclude != 0, omite essa opção do menu.
   Retorna a escolha válida (1..5). Repete até o usuário fornecer uma opção válida. */
int escolher_atributo(int exclude) {
  int escolha = 0;
  while (1) {
    printf("\nEscolha um atributo para comparar:\n");
    for (int i = 1; i <= 5; ++i) {
      if (i == exclude) continue; /* não mostrar opção já escolhida */
      printf("  %d - %s\n", i, nome_atributo(i));
    }
    printf("Opção: ");
    if (scanf("%d", &escolha) != 1) {
      /* entrada inválida (ex: letra) -> limpar buffer e repetir */
      int ch;
      while ((ch = getchar()) != EOF && ch != '\n');
      printf("Entrada inválida. Digite um número entre 1 e 5 (exceto a opção já escolhida).\n");
      continue;
    }
    if (escolha < 1 || escolha > 5 || escolha == exclude) {
      printf("Opção inválida. Tente novamente.\n");
      continue;
    }
    return escolha;
  }
}

int main() {
  /* Variáveis para armazenar duas cartas (continuação do código anterior) */
  Carta c1 = {0}, c2 = {0};

  /* Entrada de dados - Carta 1 */
  printf("Carta 1:\n");
  printf("Estado (A-H): ");
  scanf(" %c", &c1.estado);

  printf("Código da Carta (ex: A01): ");
  scanf(" %3s", c1.codigo);

  printf("Nome da Cidade: ");
  scanf(" %99[^\n]", c1.nome);

  printf("População: ");
  scanf("%d", &c1.populacao);

  printf("Área (km²): ");
  scanf("%f", &c1.area);

  printf("PIB (em bilhões de reais): ");
  scanf("%f", &c1.pib);

  printf("Número de Pontos Turísticos: ");
  scanf("%d", &c1.pontosTur);

  printf("\n"); /* separador */

  /* Entrada de dados - Carta 2 */
  printf("Carta 2:\n");
  printf("Estado (A-H): ");
  scanf(" %c", &c2.estado);

  printf("Código da Carta (ex: B02): ");
  scanf(" %3s", c2.codigo);

  printf("Nome da Cidade: ");
  scanf(" %99[^\n]", c2.nome);

  printf("População: ");
  scanf("%d", &c2.populacao);

  printf("Área (km²): ");
  scanf("%f", &c2.area);

  printf("PIB (em bilhões de reais): ");
  scanf("%f", &c2.pib);

  printf("Número de Pontos Turísticos: ");
  scanf("%d", &c2.pontosTur);

  printf("\n--- Dados cadastrados ---\n\n");

  /* Exibição resumida das cartas (opcional, para confirmação) */
  printf("Carta 1: %s (%s)\n", c1.nome, c1.codigo);
  printf("Carta 2: %s (%s)\n", c2.nome, c2.codigo);

  /* Escolha dos dois atributos (dinâmico: segunda escolha não pode ser igual à primeira) */
  int attr1 = escolher_atributo(0);
  int attr2 = escolher_atributo(attr1);

  /* Valores dos atributos para cada carta */
  double c1_val_attr1 = valor_atributo(&c1, attr1);
  double c2_val_attr1 = valor_atributo(&c2, attr1);
  double c1_val_attr2 = valor_atributo(&c1, attr2);
  double c2_val_attr2 = valor_atributo(&c2, attr2);

  /* Determina vencedores por atributo (1 = carta1, 2 = carta2, 0 = empate) */
  int vencedor_attr1 = 0;
  int vencedor_attr2 = 0;

  /* Para densidade (5), menor valor vence; para os demais, maior vence */
  if (attr1 == 5) {
    vencedor_attr1 = (c1_val_attr1 < c2_val_attr1) ? 1 : (c2_val_attr1 < c1_val_attr1 ? 2 : 0);
  } else {
    vencedor_attr1 = (c1_val_attr1 > c2_val_attr1) ? 1 : (c2_val_attr1 > c1_val_attr1 ? 2 : 0);
  }

  if (attr2 == 5) {
    vencedor_attr2 = (c1_val_attr2 < c2_val_attr2) ? 1 : (c2_val_attr2 < c1_val_attr2 ? 2 : 0);
  } else {
    vencedor_attr2 = (c1_val_attr2 > c2_val_attr2) ? 1 : (c2_val_attr2 > c1_val_attr2 ? 2 : 0);
  }

  /* Soma dos valores dos dois atributos (regra do desafio) */
  double soma_c1 = c1_val_attr1 + c1_val_attr2;
  double soma_c2 = c2_val_attr1 + c2_val_attr2;

  /* Decisão final com tratamento de empate (uso de epsilon para comparação de floats) */
  double eps = 1e-6;
  int vencedor_final = 0; /* 1 = c1, 2 = c2, 0 = empate */
  if (fabs(soma_c1 - soma_c2) < eps) vencedor_final = 0;
  else vencedor_final = (soma_c1 > soma_c2) ? 1 : 2;

  /* Exibição detalhada do resultado */
  printf("\n--- Resultado da Comparação ---\n\n");
  printf("%-25s | %-20s | %-20s\n", "Atributo", c1.nome, c2.nome);
  printf("-------------------------------------------------------------------------\n");

  /* Mostrar atributo 1 */
  printf("%-25s | %-20.4f | %-20.4f  => ", nome_atributo(attr1), c1_val_attr1, c2_val_attr1);
  printf("%s\n", vencedor_attr1 == 0 ? "Empate" : (vencedor_attr1 == 1 ? "Vence: Carta 1" : "Vence: Carta 2"));

  /* Mostrar atributo 2 */
  printf("%-25s | %-20.4f | %-20.4f  => ", nome_atributo(attr2), c1_val_attr2, c2_val_attr2);
  printf("%s\n", vencedor_attr2 == 0 ? "Empate" : (vencedor_attr2 == 1 ? "Vence: Carta 1" : "Vence: Carta 2"));

  printf("\nSoma dos atributos: %s = %.4f  |  %s = %.4f\n", c1.nome, soma_c1, c2.nome, soma_c2);

  /* Mensagem final (uso do operador ternário para selecionar texto) */
  const char *mensagem_final = (vencedor_final == 0) ? "Empate!" :
                              (vencedor_final == 1 ? "Carta 1 venceu a rodada!" : "Carta 2 venceu a rodada!");
  printf("\n>>> %s\n", mensagem_final);

  return 0;
}