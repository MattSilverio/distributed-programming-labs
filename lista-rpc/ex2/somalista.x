#define VERSION_NUMBER 1

struct lista{
    int num;
    struct lista *prox;
};

typedef struct lista *lista;

program SOMALISTA_PROG {
    version SOMALISTA_PROG{
        int SOMA_LISTA(lista) = 1;
        void IMPRIME_LISTA(lista) = 2;
    } = 1;
} = 0x13;