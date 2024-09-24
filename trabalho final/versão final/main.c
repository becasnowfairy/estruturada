#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar os dados de uma praia
typedef struct {
    int id;
    char nome[50];
    char tipo[10];
    int idLocalidade;
} Praia;

// Estrutura para armazenar os dados de uma localidade
typedef struct {
    int id;
    char nome[50];
} Localidade;

// Função para criar um novo ficheiro de praias
void criarFicheiroPraias() {
    FILE *fp = fopen("praia.dat", "wb");
    if (fp == NULL) {
        printf("Erro ao criar ficheiro de praias\n");
        exit(1);
    }
    fclose(fp);
}

// Função para criar um novo ficheiro de localidades
void criarFicheiroLocalidades() {
    FILE *fp = fopen("localidade.dat", "wb");
    if (fp == NULL) {
        printf("Erro ao criar ficheiro de localidades\n");
        exit(1);
    }
    fclose(fp);
}

// Função para inserir uma praia no ficheiro
void inserirPraia() {
    Praia praia;
    FILE *fp = fopen("praia.dat", "ab");
    if (fp == NULL) {
        printf("Erro ao abrir ficheiro de praias\n");
        exit(1);
    }

    printf("Digite o nome da praia: ");
    fgets(praia.nome, sizeof(praia.nome), stdin);
    praia.nome[strlen(praia.nome) - 1] = '\0'; // remover o caractere de nova linha

    printf("Digite o tipo da praia (oceânica/fluvial): ");
    fgets(praia.tipo, sizeof(praia.tipo), stdin);
    praia.tipo[strlen(praia.tipo) - 1] = '\0'; // remover o caractere de nova linha

printf("Digite o ID da localidade: ");
scanf("%d", &praia.idLocalidade);
getchar(); // add this line

    // gerar ID automático
    praia.id = 1;
    if (fseek(fp, 0, SEEK_END) == 0) {
        fseek(fp, -sizeof(Praia), SEEK_END);
        fread(&praia.id, sizeof(int), 1, fp);
        praia.id++;
    }

    fwrite(&praia, sizeof(Praia), 1, fp);
    fclose(fp);
}

// Função para inserir uma localidade no ficheiro
void inserirLocalidade() {
    Localidade localidade;
    FILE *fp = fopen("localidade.dat", "ab");
    if (fp == NULL) {
        printf("Erro ao abrir ficheiro de localidades\n");
        exit(1);
    }

   printf("Digite o nome da localidade: ");
fgets(localidade.nome, sizeof(localidade.nome), stdin);
localidade.nome[strlen(localidade.nome) - 1] = '\0'; // remover o caractere de nova linha
getchar(); // add this line 

    // gerar ID automático
    localidade.id = 1;
    if (fseek(fp, 0, SEEK_END) == 0) {
        fseek(fp, -sizeof(Localidade), SEEK_END);
        fread(&localidade.id, sizeof(int), 1, fp);
        localidade.id++;
    }

    fwrite(&localidade, sizeof(Localidade), 1, fp);
    fclose(fp);
}

// Função para listar as praias
void listarPraias() {
    Praia praia;
    FILE *fp = fopen("praia.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir ficheiro de praias\n");
        exit(1);
    }

    printf("Listagem de praias:\n");
    while (fread(&praia, sizeof(Praia), 1, fp) == 1) {
        printf("ID: %d\n", praia.id);
        printf("Nome: %s\n", praia.nome);
        printf("Tipo: %s\n", praia.tipo);
        printf("ID Localidade: %d\n\n", praia.idLocalidade);
    }

    fclose(fp);
}

// Função para listar as localidades
void listarLocalidades() {
    Localidade localidade;
    FILE *fp = fopen("localidade.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir ficheiro de localidades\n");
        exit(1);
    }

    printf("Listagem de localidades:\n");
    while (fread(&localidade , sizeof(Localidade), 1, fp) == 1) {
        printf("ID: %d\n", localidade.id);
        printf("Nome: %s\n\n", localidade.nome);
    }

    fclose(fp);
}

// Função para listar as praias por localidade
void listarPraiasPorLocalidade() {
    int idLocalidade;
    Praia praia;
    FILE *fp = fopen("praia.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir ficheiro de praias\n");
        exit(1);
    }

printf("Digite o ID da localidade: ");
scanf("%d", &idLocalidade);
getchar(); // add this line

    printf("Listagem de praias da localidade %d:\n", idLocalidade);
    while (fread(&praia, sizeof(Praia), 1, fp) == 1) {
        if (praia.idLocalidade == idLocalidade) {
            printf("ID: %d\n", praia.id);
            printf("Nome: %s\n", praia.nome);
            printf("Tipo: %s\n\n", praia.tipo);
        }
    }

    fclose(fp);
}

// Função para procurar uma praia pelo nome
void procurarPraia() {
    char nome[50];
    Praia praia;
    FILE *fp = fopen("praia.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir ficheiro de praias\n");
        exit(1);
    }

    printf("Digite o nome da praia: ");
fgets(nome, sizeof(nome), stdin);
nome[strlen(nome) - 1] = '\0'; // remover o caractere de nova linha
getchar(); // add this line 


    printf("Resultados da busca:\n");
    while (fread(&praia, sizeof(Praia), 1, fp) == 1) {
        if (strcmp(praia.nome, nome) == 0) {
            printf("ID: %d\n", praia.id);
            printf("Nome: %s\n", praia.nome);
            printf("Tipo: %s\n", praia.tipo);
            printf("ID Localidade: %d\n\n", praia.idLocalidade);
        }
    }

    fclose(fp);
}

// Função para alterar uma localidade
void alterarLocalidade() {
    int idLocalidade;
    Localidade localidade;
    FILE *fp = fopen("localidade.dat", "r+b");
    if (fp == NULL) {
        printf("Erro ao abrir ficheiro de localidades\n");
        exit(1);
    }

  printf("Digite o ID da localidade a alterar: ");
scanf("%d", &idLocalidade);
getchar(); // add this line

    fseek(fp, (idLocalidade - 1) * sizeof(Localidade), SEEK_SET);
    fread(&localidade, sizeof(Localidade), 1, fp);

    printf("Digite o novo nome da localidade: ");
    fgets(localidade.nome, sizeof(localidade.nome), stdin);
    localidade.nome[strlen(localidade.nome) - 1] = '\0'; // remover o caractere de nova linha

    fseek(fp, (idLocalidade - 1) * sizeof(Localidade), SEEK_SET);
    fwrite(&localidade, sizeof(Localidade), 1, fp);

    fclose(fp);
}

// Função para alterar uma praia
void alterarPraia() {
    int idPraia;
    Praia praia;
    FILE *fp = fopen("praia.dat", "r+b");
    if (fp == NULL) {
        printf("Erro ao abrir ficheiro de praias\n");
        exit(1);
    }

printf("Digite o ID da praia a alterar: ");
scanf("%d", &idPraia);
getchar(); // add this line

    if (fseek(fp, (idPraia - 1) * sizeof(Praia), SEEK_SET) != 0) {
        printf("Erro ao posicionar ponteiro de ficheiro\n");
        fclose(fp);
        exit(1);
    }

    if (fread(&praia, sizeof(Praia), 1, fp) != 1) {
        printf("Erro ao ler praia do ficheiro\n");
        fclose(fp);
        exit(1);
    }

    printf("Digite o novo nome da praia: ");
    if (fgets(praia.nome, sizeof(praia.nome), stdin) == NULL) {
        printf("Erro ao ler nome da praia\n");
        fclose(fp);
        exit(1);
    }
    praia.nome[strlen(praia.nome) - 1] = '\0'; // remove newline character

    printf("Digite o novo tipo da praia (oceânica/fluvial): ");
    if (fgets(praia.tipo, sizeof(praia.tipo), stdin) == NULL) {
        printf("Erro ao ler tipo da praia\n");
        fclose(fp);
        exit(1);
    }
    praia.tipo[strlen(praia.tipo) - 1] = '\0'; // remove newline character

    if (fseek(fp, (idPraia - 1) * sizeof(Praia), SEEK_SET) != 0) {
        printf("Erro ao posicionar ponteiro de ficheiro\n");
        fclose(fp);
        exit(1);
    }

    if (fwrite(&praia, sizeof(Praia), 1, fp) != 1) {
        printf("Erro ao escrever praia no ficheiro\n");
        fclose(fp);
        exit(1);
    }

    fclose(fp);
}

// Função para exportar as praias para um ficheiro CSV
void exportarPraias() {
    Praia praia;
    FILE *fp = fopen("praia.dat", "rb");
    FILE *fpCsv = fopen("praia.csv", "w");
    if (fp == NULL || fpCsv == NULL) {
        printf("Erro ao abrir ficheiro de praias ou ficheiro CSV\n");
        exit(1);
    }

    fprintf(fpCsv, "Localidade;Praia;Tipo\n");
    while (fread(&praia, sizeof(Praia), 1, fp) == 1) {
        Localidade localidade;
        FILE *fpLocalidade = fopen("localidade.dat", "rb");
        fseek(fpLocalidade, (praia.idLocalidade - 1) * sizeof(Localidade), SEEK_SET);
        fread(&localidade, sizeof(Localidade), 1, fpLocalidade);
        fclose(fpLocalidade);

        fprintf(fpCsv, "%s;%s;%s\n", localidade.nome, praia.nome, praia.tipo);
    }

    fclose(fp);
    fclose(fpCsv);
}

int main() {
    criarFicheiroPraias();
    criarFicheiroLocalidades();

    int opcao;
    do {
        printf("Menu:\n");
        printf("1. Inserir Praia\n");
        printf("2. Inserir Localidade\n");
        printf("3. Listar Praias\n");
        printf("4. Listar Localidades\n");
        printf("5. Listar Praias por Localidade\n");
        printf("6. Procurar Praia\n");
        printf("7. Alterar Localidade\n");
        printf("8. Alterar Praia\n");
        printf("9. Exportar Praias para ficheiro CSV\n");
        printf("10. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar(); // remover o caractere de nova linha

        switch (opcao) {
            case 1:
                inserirPraia();
                break;
            case 2:
                inserirLocalidade();
                break;
            case 3:
                listarPraias();
                break;
            case 4:
                listarLocalidades();
                break;
            case 5:
                listarPraiasPorLocalidade();
                break;
            case 6:
                procurarPraia();
                break;
            case 7:
                alterarLocalidade();
                break;
            case 8:
                alterarPraia();
                break;
            case 9:
                exportarPraias();
                break;
            case 10:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida\n");
        }
    } while (opcao != 10);

    return 0;
}