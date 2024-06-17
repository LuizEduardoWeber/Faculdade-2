#include <stdio.h>
#include <string.h>

#define NUM_RIOS 10
#define NUM_MESES 24

void mostrarMenu();
void mostrarVazaoRio(int rio, int mes);
void alterarVazaoRio(int rio, int mes);
void calcularMediaVazaoRio(int rio, int mesInicial, int mesFinal);
void mostrarMaiorVazaoRio(int rio);
void mostrarMenorVazaoRio(int rio);
void mostrarRioMaiorVazao();
void mostrarRiosAcimaVazao(float vazao);

char nomesRios[NUM_RIOS][20] = {"Rio Piraquara", "Rio Pequeno", "Rio Miringuava", "Rio Passaúna", "Rio da Várzea", "Rio Bananas", "Rio das Pedras", "Rio Vitorino", "Rio Marmeleiro", "Rio Cachoeirinha"};
float vazoes[NUM_RIOS][NUM_MESES] = {
    {1.80, 2.29, 2.40, 2.55, 2.56, 2.51, 2.38, 2.17, 2.01, 2.12, 1.69, 1.50, 1.40, 1.52, 2.44, 2.00, 2.36, 1.90, 2.15, 2.13, 1.73, 1.72, 2.07, 2.12},
    {1.84, 2.89, 1.80, 0.92, 0.61, 1.55, 1.13, 2.45, 1.25, 1.69, 2.91, 4.48, 4.12, 3.07, 5.46, 1.88, 1.90, 2.14, 1.46, 2.08, 1.84, 5.22, 5.42, 2.70},
    {1.00, 2.99, 0.84, 0.51, 0.48, 1.43, 1.00, 5.21, 0.80, 0.90, 2.36, 3.73, 6.92, 4.94, 10.01, 1.05, 1.74, 2.62, 0.77, 2.84, 1.11, 7.12, 5.09, 1.29},
    {1.59, 1.43, 2.03, 0.91, 1.09, 1.26, 0.90, 1.48, 1.03, 1.70, 1.06, 0.78, 1.59, 0.90, 0.74, 1.02, 1.35, 2.37, 1.09, 1.64, 2.04, 2.26, 2.43, 2.40},
    {3.09, 4.21, 1.94, 0.83, 1.17, 5.22, 3.64, 9.35, 3.54, 4.48, 5.73, 13.09, 10.98, 7.59, 19.38, 6.13, 5.70, 6.76, 4.60, 4.24, 3.83, 9.59, 11.02, 6.47},
    {4.67, 3.22, 1.06, 0.80, 1.71, 8.36, 3.97, 18.02, 3.14, 2.61, 2.08, 15.76, 23.80, 8.81, 7.19, 1.98, 1.16, 3.16, 2.41, 4.60, 2.58, 18.04, 3.89, 1.14},
    {2.97, 2.40, 1.00, 0.93, 1.58, 5.15, 3.01, 11.66, 2.20, 2.70, 1.02, 7.18, 17.79, 6.03, 3.40, 1.40, 1.08, 2.93, 1.79, 5.58, 2.43, 16.60, 5.87, 1.06},
    {3.10, 6.08, 3.84, 1.83, 5.11, 17.84, 13.31, 10.99, 5.09, 2.55, 1.42, 2.75, 15.83, 18.17, 4.98, 2.23, 1.53, 2.26, 2.30, 1.89, 6.02, 19.75, 11.45, 3.71},
    {1.99, 4.52, 1.15, 1.46, 5.14, 9.77, 7.55, 6.73, 1.06, 0.81, 0.64, 3.10, 10.22, 5.69, 2.70, 0.74, 0.74, 2.58, 1.49, 0.97, 4.01, 11.59, 2.56, 0.74},
    {0.33, 0.33, 0.27, 0.25, 0.21, 0.24, 0.23, 0.36, 0.25, 0.27, 0.34, 0.48, 0.47, 0.45, 0.52, 0.32, 0.35, 0.37, 0.32, 0.42, 0.32, 0.44, 0.34, 0.28}
};

int main() {
    int opcao;
    do {
        mostrarMenu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                int rio, mes;
                printf("\nDigite o número do rio (1-10): ");
                scanf("%d", &rio);
                printf("\nDigite o mês (1-24): ");
                scanf("%d", &mes);
                mostrarVazaoRio(rio - 1, mes - 1);
                break;
            case 2:
                int rio2, mes2;
                printf("\nDigite o número do rio (1-10): ");
                scanf("%d", &rio2);
                printf("\nDigite o mês (1-24): ");
                scanf("%d", &mes2);
                alterarVazaoRio(rio2 - 1, mes2 - 1);
                break;
            case 3:
                int rio3, mesInicial, mesFinal;
                printf("\nDigite o número do rio (1-10): ");
                scanf("%d", &rio3);
                printf("\nDigite o mês inicial (1-24): ");
                scanf("%d", &mesInicial);
                printf("\nDigite o mês final (1-24): ");
                scanf("%d", &mesFinal);
                calcularMediaVazaoRio(rio3 - 1, mesInicial - 1, mesFinal - 1);
                break;
            case 4:
                int rio4;
                printf("\nDigite o número do rio (1-10): ");
                scanf("%d", &rio4);
                mostrarMaiorVazaoRio(rio4 - 1);
                break;
            case 5:
                int rio5;
                printf("\nDigite o número do rio (1-10): ");
                scanf("%d", &rio5);
                mostrarMenorVazaoRio(rio5 - 1);
                break;
            case 6:
                mostrarRioMaiorVazao();
                break;
            case 7:
                float vazao;
                printf("\nDigite a vazão mínima: ");
                scanf("%f", &vazao);
                mostrarRiosAcimaVazao(vazao);
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao!= 8);

    return 0;
}

void mostrarMenu() {
    printf("Menu:\n");
    printf("1. Mostrar vazão de um rio para um mês\n");
    printf("2. Alterar vazão de um rio para um mês\n");
    printf("3. Calcular média de vazão de um rio\n");
    printf("4. Mostrar mês de maior vazão de um rio\n");
    printf("5. Mostrar mês de menor vazão de um rio\n");
    printf("6. Mostrar rio de maior vazão\n");
    printf("7. Mostrar rios com vazão acima de um valor\n");
    printf("8. Sair\n");
}

void mostrarVazaoRio(int rio, int mes) {
    printf("\nVazão do %s no mês %d: %.2f\n", nomesRios[rio], mes + 1, vazoes[rio][mes]);
}

void alterarVazaoRio(int rio, int mes) {
    float novaVazao;
    printf("\nDigite a nova vazão: ");
    scanf("%f", &novaVazao);
    vazoes[rio][mes] = novaVazao;
    printf("\nVazão alterada com sucesso!\n");
}

void calcularMediaVazaoRio(int rio, int mesInicial, int mesFinal) {
    float soma = 0;
    for (int i = mesInicial; i <= mesFinal; i++) {
        soma += vazoes[rio][i];
    }
    float media = soma / (mesFinal - mesInicial + 1);
    printf("\nMédia de vazão do %s entre os meses %d e %d: %.2f\n", nomesRios[rio], mesInicial + 1, mesFinal + 1, media);
}

void mostrarMaiorVazaoRio(int rio) {
    int mesMaiorVazao = 0;
    float maiorVazao = vazoes[rio][0];
    for (int i = 1; i < NUM_MESES; i++) {
        if (vazoes[rio][i] > maiorVazao) {
            maiorVazao = vazoes[rio][i];
            mesMaiorVazao = i;
        }
    }
    printf("\nMês de maior vazão do %s: %d, com vazão de %.2f\n", nomesRios[rio], mesMaiorVazao + 1, maiorVazao);
}

void mostrarMenorVazaoRio(int rio) {
    int mesMenorVazao = 0;
    float menorVazao = vazoes[rio][0];
    for (int i = 1; i < NUM_MESES; i++) {
        if (vazoes[rio][i] < menorVazao) {
            menorVazao = vazoes[rio][i];
            mesMenorVazao = i;
        }
    }
    printf("\nMês de menor vazão do %s: %d, com vazão de %.2f\n", nomesRios[rio], mesMenorVazao + 1, menorVazao);
}

void mostrarRioMaiorVazao() {
    int rioMaiorVazao = 0;
    float maiorVazao = vazoes[0][0];
    for (int i = 1; i < NUM_RIOS; i++) {
        for (int j = 0; j < NUM_MESES; j++) {
            if (vazoes[i][j] > maiorVazao) {
                maiorVazao = vazoes[i][j];
                rioMaiorVazao = i;
            }
        }
    }
    printf("\nRio de maior vazão: %s, com vazão de %.2f\n", nomesRios[rioMaiorVazao], maiorVazao);
}

void mostrarRiosAcimaVazao(float vazao) {
    printf("\nRios com vazão acima de %.2f:\n", vazao);
    for (int i = 0; i < NUM_RIOS; i++) {
        for (int j = 0; j < NUM_MESES; j++) {
            if (vazoes[i][j] > vazao) {
                printf("\n%s no mês %d: %.2f\n", nomesRios[i], j + 1, vazoes[i][j]);
            }
        }
    }
}