#include <stdio.h>
#include <string.h>
#include <locale.h>

struct Animal {
    char nome[50];
    float consumo_diario;
};

void calcular_alimento(struct Animal animais[], int num_animais, char *nome_animal, int quantidade, float custo) {
    for (int i = 0; i < num_animais; i++) {
        if (strcmp(animais[i].nome, nome_animal) == 0) {
            float consumo_dia = quantidade * animais[i].consumo_diario;
            float consumo_mes = consumo_dia * 30;
            float custo_mes = consumo_mes * custo;

            printf("\nQuantidade por dia: %.2f kg\n", consumo_dia);
            printf("Quantidade por mês: %.2f kg\n", consumo_mes);
            printf("Custo estimado por mês: R$ %.2f\n", custo_mes);
            return;
        }
    }

    printf("\nAnimal não encontrado. Vamos calcular como um novo animal.\n");

    struct Animal novo_animal;
    strcpy(novo_animal.nome, nome_animal);
    printf("Digite o consumo diário (em kg) do animal: ");
    scanf("%f", &novo_animal.consumo_diario);

    float consumo_dia = quantidade * novo_animal.consumo_diario;
    float consumo_mes = consumo_dia * 30;
    float custo_mes = consumo_mes * custo;

    printf("\nQuantidade por dia: %.2f kg\n", consumo_dia);
    printf("Quantidade por mês: %.2f kg\n", consumo_mes);
    printf("Custo estimado por mês: R$ %.2f\n", custo_mes);
}

void nova_consulta(struct Animal animais[], int num_animais) {
    char nome_animal[50];
    int quantidade;
    float custo;

    getchar();
    printf("\nDigite o tipo de animal para consulta: ");
    fgets(nome_animal, sizeof(nome_animal), stdin);
    nome_animal[strcspn(nome_animal, "\n")] = 0;

    printf("Digite a quantidade de animais: ");
    scanf("%d", &quantidade);

    printf("Digite o custo por quilo da ração: ");
    scanf("%f", &custo);

    calcular_alimento(animais, num_animais, nome_animal, quantidade, custo);
}

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    struct Animal animais[] = {
        {"Leopardo", 5.0},
        {"Tigre", 6.0},
        {"Onça", 3.5},
        {"Elefante", 50.0},
        {"Girafa", 30.0},
        {"Zebra", 10.0},
        {"Cavalo", 7.0},
        {"Urso", 10.0},
        {"Lobo", 2.5},
        {"Águia", 0.3},
        {"Crocodilo", 8.0},
        {"Lince", 2.0},
        {"Búfalo", 20.0},
        {"Hipopótamo", 45.0},
        {"Javali", 4.0},
        {"Cervo", 5.5},
        {"Tatu", 1.0},
        {"Macaco", 1.5}
    };

    int num_animais = sizeof(animais) / sizeof(animais[0]);

    int opcao;

    do {
        printf("\nEscolha uma opção:\n");
        printf("1. Realizar nova consulta\n");
        printf("2. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            nova_consulta(animais, num_animais);
        } else if (opcao == 2) {
            printf("Saindo do programa...\n");
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 2);

    return 0;
}
