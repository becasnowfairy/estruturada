#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store beach information
typedef struct {
    int IDPraia;             // Unique beach identifier
    char nomePraia[50];      // Beach name
    char tipo[10];           // Beach type: "oceanica" or "fluvial"
    int IDLocalidade;        // Identifier of the associated locality
} Praia;

// Structure to store locality information
typedef struct {
    int IDLocalidade;        // Unique locality identifier
    char nomeLocalidade[50]; // Locality name
} Localidade;

// Function prototypes
void inserirPraia(Praia praias[], int *numPraias, Localidade localidades[], int numLocalidades);
void inserirLocalidade(Localidade localidades[], int *numLocalidades);
void listarPraias(Praia praias[], int numPraias);
void listarLocalidades(Localidade localidades[], int numLocalidades);
void listarPraiasPorLocalidade(Praia praias[], int numPraias, Localidade localidades[], int numLocalidades);
void procurarPraia(Praia praias[], int numPraias);
void alterarLocalidade(Localidade localidades[], int numLocalidades);
void alterarPraia(Praia praias[], int numPraias);
void exportarPraiasCSV(Praia praias[], int numPraias, Localidade localidades[], int numLocalidades);

int main() {
    Praia praias[100];        // Array to store up to 100 beaches
    Localidade localidades[100]; // Array to store up to 100 localities
    int numPraias = 0, numLocalidades = 0; // Counters for the number of beaches and localities
    int opcao;

    do {
        // Display the menu
        printf("\nMenu:\n");
        printf("1. Insert Beach\n");
        printf("2. Insert Locality\n");
        printf("3. List Beaches\n");
        printf("4. List Localities\n");
        printf("5. List Beaches by Locality\n");
        printf("6. Search Beach by Name\n");
        printf("7. Edit Locality\n");
        printf("8. Edit Beach\n");
        printf("9. Export Beaches to CSV\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &opcao);
        getchar(); // Clear the buffer to avoid issues when entering strings

        // Execute the corresponding function based on the user's choice
        switch (opcao) {
            case 1:
                inserirPraia(praias, &numPraias, localidades, numLocalidades);
                break;
            case 2:
                inserirLocalidade(localidades, &numLocalidades);
                break;
            case 3:
                listarPraias(praias, numPraias);
                break;
            case 4:
                listarLocalidades(localidades, numLocalidades);
                break;
            case 5:
                listarPraiasPorLocalidade(praias, numPraias, localidades, numLocalidades);
                break;
            case 6:
                procurarPraia(praias, numPraias);
                break;
            case 7:
                alterarLocalidade(localidades, numLocalidades);
                break;
            case 8:
                alterarPraia(praias, numPraias);
                break;
            case 9:
                exportarPraiasCSV(praias, numPraias, localidades, numLocalidades);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while (opcao != 0); // The program continues until the user chooses to exit

    return 0;
}

// Function to insert a new beach
void inserirPraia(Praia praias[], int *numPraias, Localidade localidades[], int numLocalidades) {
    if (numLocalidades == 0) {
        printf("No localities available. Insert a locality first.\n");
        return;
    }

    Praia novaPraia;
    novaPraia.IDPraia = *numPraias + 1; // Auto-incremented beach ID

    printf("Beach Name: ");
    fgets(novaPraia.nomePraia, sizeof(novaPraia.nomePraia), stdin);
    novaPraia.nomePraia[strcspn(novaPraia.nomePraia, "\n")] = '\0'; // Remove newline character

    printf("Beach Type (oceanica/fluvial): ");
    fgets(novaPraia.tipo, sizeof(novaPraia.tipo), stdin);
    novaPraia.tipo[strcspn(novaPraia.tipo, "\n")] = '\0'; // Remove newline character

    printf("Locality ID (1-%d): ", numLocalidades);
    scanf("%d", &novaPraia.IDLocalidade);
    getchar(); // Clear buffer

    // Ensure the locality ID is valid
    if (novaPraia.IDLocalidade < 1 || novaPraia.IDLocalidade > numLocalidades) {
        printf("Invalid Locality ID. Beach not inserted.\n");
        return;
    }

    praias[*numPraias] = novaPraia;
    (*numPraias)++;

    printf("Beach successfully inserted!\n");
}

// Function to insert a new locality
void inserirLocalidade(Localidade localidades[], int *numLocalidades) {
    Localidade novaLocalidade;
    novaLocalidade.IDLocalidade = *numLocalidades + 1; // Auto-incremented locality ID

    printf("Locality Name: ");
    fgets(novaLocalidade.nomeLocalidade, sizeof(novaLocalidade.nomeLocalidade), stdin);
    novaLocalidade.nomeLocalidade[strcspn(novaLocalidade.nomeLocalidade, "\n")] = '\0'; // Remove newline character

    localidades[*numLocalidades] = novaLocalidade;
    (*numLocalidades)++;

    printf("Locality successfully inserted!\n");
}

// Function to list all beaches
void listarPraias(Praia praias[], int numPraias) {
    if (numPraias == 0) {
        printf("No beaches to display.\n");
        return;
    }

    for (int i = 0; i < numPraias; i++) {
        printf("ID: %d, Name: %s, Type: %s, Locality ID: %d\n",
               praias[i].IDPraia, praias[i].nomePraia, praias[i].tipo, praias[i].IDLocalidade);
    }
}

// Function to list all localities
void listarLocalidades(Localidade localidades[], int numLocalidades) {
    if (numLocalidades == 0) {
        printf("No localities to display.\n");
        return;
    }

    for (int i = 0; i < numLocalidades; i++) {
        printf("ID: %d, Name: %s\n", localidades[i].IDLocalidade, localidades[i].nomeLocalidade);
    }
}

// Function to list beaches by locality
void listarPraiasPorLocalidade(Praia praias[], int numPraias, Localidade localidades[], int numLocalidades) {
    int idLocalidade;
    printf("Enter Locality ID: ");
    scanf("%d", &idLocalidade);
    getchar(); // Clear buffer

    printf("Beaches in Locality ID %d:\n", idLocalidade);
    for (int i = 0; i < numPraias; i++) {
        if (praias[i].IDLocalidade == idLocalidade) {
            printf("ID: %d, Name: %s, Type: %s\n", praias[i].IDPraia, praias[i].nomePraia, praias[i].tipo);
        }
    }
}

// Function to search for a beach by name
void procurarPraia(Praia praias[], int numPraias) {
    char nome[50];
    printf("Enter the name of the beach: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0'; // Remove newline character

    for (int i = 0; i < numPraias; i++) {
        if (strcmp(praias[i].nomePraia, nome) == 0) {
            printf("ID: %d, Name: %s, Type: %s, Locality ID: %d\n",
                   praias[i].IDPraia, praias[i].nomePraia, praias[i].tipo, praias[i].IDLocalidade);
            return;
        }
    }
    printf("Beach not found!\n");
}

// Function to edit a locality
void alterarLocalidade(Localidade localidades[], int numLocalidades) {
    int id;
    printf("Enter the Locality ID to edit: ");
    scanf("%d", &id);
    getchar(); // Clear buffer

    for (int i = 0; i < numLocalidades; i++) {
        if (localidades[i].IDLocalidade == id) {
            printf("New Locality Name: ");
            fgets(localidades[i].nomeLocalidade, sizeof(localidades[i].nomeLocalidade), stdin);
            localidades[i].nomeLocalidade[strcspn(localidades[i].nomeLocalidade, "\n")] = '\0'; // Remove newline character
            printf("Locality updated successfully!\n");
            return;
        }
    }
    printf("Locality not found!\n");
}

// Function to edit a beach
void alterarPraia(Praia praias[], int numPraias) {
    int id;
    printf("Enter the Beach ID to edit: ");
    scanf("%d", &id);
    getchar(); // Clear buffer

    for (int i = 0; i < numPraias; i++) {
        if (praias[i].IDPraia == id) {
            printf("New Beach Name: ");
            fgets(praias[i].nomePraia, sizeof(praias[i].nomePraia), stdin);
            praias[i].nomePraia[strcspn(praias[i].nomePraia, "\n")] = '\0'; // Remove newline character
            printf("New Beach Type (oceanica/fluvial): ");
            fgets(praias[i].tipo, sizeof(praias[i].tipo), stdin);
            praias[i].tipo[strcspn(praias[i].tipo, "\n")] = '\0'; // Remove newline character
            printf("Beach updated successfully!\n");
            return;
        }
    }
    printf("Beach not found!\n");
}

// Function to export beaches to a CSV file
void exportarPraiasCSV(Praia praias[], int numPraias, Localidade localidades[], int numLocalidades) {
    FILE *file = fopen("beaches.csv", "w");
    if (file == NULL) {
        printf("Error creating file!\n");
        return;
    }

    fprintf(file, "Locality Name;Beach Name;Beach Type\n");

    for (int i = 0; i < numPraias; i++) {
        for (int j = 0; j < numLocalidades; j++) {
            if (praias[i].IDLocalidade == localidades[j].IDLocalidade) {
                fprintf(file, "%s;%s;%s\n", localidades[j].nomeLocalidade, praias[i].nomePraia, praias[i].tipo);
            }
        }
    }

    fclose(file);
    printf("Beaches successfully exported to CSV!\n");
}
