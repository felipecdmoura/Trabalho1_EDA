#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opt = 0; // Variavel que armazena a opcao do menu
    char stp;    // Variavel que so serve para parar o programa ate que o usuario insira qualquer char

    while (opt != 5)
    {
        system("cls || clear");
        menu();

        scanf("%d", &opt);

        switch (opt)
        {
        case 1:

            break;

        case 2:

            break;

        case 3:

            break;

        case 4:

            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Opcao invalida! Digite qualquer coisa para voltar:\n");
            scanf(" %c", &stp);
            break;
        }
        /* code */
    }

    return 0;
}

void menu()
{

    printf("---Menu---\n\n");
    printf("Selecione uma das opcoes abaixo: \n");
    printf("1) Ler o dataset do TripAdivisor\n");
    printf("2) Gerar Vocabulario\n");
    printf("3) Exibir TF-IDF\n");
    printf("4) Exibir TF-IDF por Nota\n");
    printf("5) Sair\n");
}