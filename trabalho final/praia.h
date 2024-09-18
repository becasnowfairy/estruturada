#ifndef PRAIA_H
#define PRAIA_H

typedef struct {
    int id;
    char nome[50];
    char tipo[10];
    int idLocalidade;
} Praia;

typedef struct {
    int id;
    char nome[50];
} Localidade;

#endif