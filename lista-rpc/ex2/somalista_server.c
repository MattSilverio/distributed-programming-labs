#include "somalista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *soma_lista_1_svc(lista *argp, struct svc_req *rqstp) {
    static int result;
    result = 0; // Reinicialize o resultado para cada chamada
    printf("Requisicao para soma de lista\n");

    while (argp != NULL) {
        result += argp->num;
        argp = argp->prox;
    }

    return &result;
}

void *imprime_lista_1_svc(lista *argp, struct svc_req *rqstp) {
    static char result[1024]; // Buffer para armazenar a string da lista
    result[0] = '\0'; // Reinicialize o buffer

    printf("Requisicao para imprimir lista\n");
    while (argp != NULL) {
        char buffer[32];
        sprintf(buffer, "%d -> ", argp->num);
        strcat(result, buffer);
        argp = argp->prox;
    }

    strcat(result, "NULL\n");
    printf("%s", result); // Imprima no servidor para debug

    return &result;
}
