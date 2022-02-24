#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct para o vetor de string do vocabulario; possui o vetor em si,  e o tamanho dele, para uso de loops.
typedef struct
{
    char **words;
    int size;
} Vocabulary;

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

int main()
{
    Vocabulary voc; // Variavel do vetor de strings que recebera o vocabulario.

    int opt = 0; // Variavel que armazena a opcao do menu
    char stp;    // Variavel que so serve para parar o programa ate que o usuario insira qualquer char

    float *tf_idf_1, *tf_idf_2, *tf_idf_3, *tf_idf_4, *tf_idf_5; // Vetores para armazenar os if_idf das notas 1-5

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
