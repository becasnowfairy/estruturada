#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30
#define MAX_MUNICIPIO 51
#define MAX_ICAO 5
#define MAX_IATA 4
#define MAX_NOME 51

/*Crie um array para armazenar os dados referentes aos 30 aeroportos públicos de Portugal. O array deve
utilizar a seguinte estrutura:
typedef struct{
char municipio[51];
char ICAO[5];
char IATA[4];
char nome[51];
} aeroporto;*/

typedef struct
{
    char municipio[MAX_MUNICIPIO];
    char ICAO[MAX_ICAO];
    char IATA[MAX_IATA];
    char nome[MAX_NOME];
} aeroporto;

/*Crie as seguintes funções para a gestão do array de aeroportos:
inserir ( )
listar ( )
procurar ( )
alterar ( )*/

// Função para inserir um novo aeroporto no array
void inserir(aeroporto aeroportos[], int *tamanho) {
    if (*tamanho < MAX) {
        printf("Municipio: ");
        fgets(aeroportos[*tamanho].municipio, MAX_MUNICIPIO, stdin);
        aeroportos[*tamanho].municipio[strcspn(aeroportos[*tamanho].municipio, "\n")] = 0; 

        printf("ICAO: ");
        fgets(aeroportos[*tamanho].ICAO, MAX_ICAO, stdin);
        aeroportos[*tamanho].ICAO[strcspn(aeroportos[*tamanho].ICAO, "\n")] = 0; 

        printf("IATA: ");
        fgets(aeroportos[*tamanho].IATA, MAX_IATA, stdin);
        aeroportos[*tamanho].IATA[strcspn(aeroportos[*tamanho].IATA, "\n")] = 0; 

        printf("Nome: ");
        fgets(aeroportos[*tamanho].nome, MAX_NOME, stdin);
        aeroportos[*tamanho].nome[strcspn(aeroportos[*tamanho].nome, "\n")] = 0; 

        (*tamanho)++;
    } else {
        printf("Array de aeroportos cheio!\n");
    }
}

// Função para listar todos os aeroportos no array
void listar(aeroporto aeroportos[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Aeroporto %d:\n", i + 1);
        printf("Municipio: %s\n", aeroportos[i].municipio);
        printf("ICAO: %s\n", aeroportos[i].ICAO);
        printf("IATA: %s\n", aeroportos[i].IATA);
        printf("Nome: %s\n\n", aeroportos[i].nome);
    }
}

// Função para alterar as informações de um aeroporto
void alterar(aeroporto aeroportos[], int tamanho) {
    char nome[MAX_NOME];
    printf("Insira o nome do aeroporto a alterar: ");
    fgets(nome, MAX_NOME, stdin);
    nome[strcspn(nome, "\n")] = 0; 

    for (int i = 0; i < tamanho; i++) {
        if (strcmp(aeroportos[i].nome, nome) == 0) {
            printf("Insera as novas informações do aeroporto:\n");
            printf("Municipio: ");
            fgets(aeroportos[i].municipio, MAX_MUNICIPIO, stdin);
            aeroportos[i].municipio[strcspn(aeroportos[i].municipio, "\n")] = 0; 

            printf("ICAO: ");
            fgets(aeroportos[i].ICAO, MAX_ICAO, stdin);
            aeroportos[i].ICAO[strcspn(aeroportos[i].ICAO, "\n")] = 0; 

            printf("IATA: ");
            fgets(aeroportos[i].IATA, MAX_IATA, stdin);
            aeroportos[i].IATA[strcspn(aeroportos[i].IATA, "\n")] = 0; 

            printf("Nome: ");
            fgets(aeroportos[i].nome, MAX_NOME, stdin);
            aeroportos[i].nome[strcspn(aeroportos[i].nome, "\n")] = 0; 
            return;
        }
    }

    printf("Aeroporto não encontrado!\n");
}
// Função para procurar um aeroporto
void procurar(aeroporto aeroportos[], int tamanho) {
    char nome[MAX_NOME];
    printf("Insira o nome do aeroporto a procurar: ");
    fgets(nome, MAX_NOME, stdin);
    nome[strcspn(nome, "\n")] = 0; 

    for (int i = 0; i < tamanho; i++) {
        if (strcmp(aeroportos[i].nome, nome) == 0) {
            printf("Aeroporto encontrado!\n");
            printf("Municipio: %s\n", aeroportos[i].municipio);
            printf("ICAO: %s\n", aeroportos[i].ICAO);
            printf("IATA: %s\n", aeroportos[i].IATA);
            printf("Nome: %s\n", aeroportos[i].nome);
            return;
        }
    }

    printf("Aeroporto não encontrado!\n");
}

int main() {
    aeroporto aeroportos[MAX];
    int tamanho = 0;

    int opcao;
    do {
        printf("Menu:\n");
        printf("1. Inserir aeroporto\n");
        printf("2. Listar aeroportos\n");
        printf("3. Procurar aeroporto\n");
        printf("4. Alterar aeroporto\n");
        printf("5. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                inserir(aeroportos, &tamanho);
                break;
            case 2:
                listar(aeroportos, tamanho);
                break;
            case 3:
                procurar(aeroportos, tamanho);
                break;
            case 4:
                alterar(aeroportos, tamanho);
                break;
            case 5:
                printf("A sair...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 5);

    return 0;
}