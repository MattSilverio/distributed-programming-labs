#include "calcula.h"
#include <stdio.h>
#include <stdlib.h>

void prog_100(char *host, int x, int y) {
    CLIENT *clnt;
    int *result_add, *result_sub;
    operandos args;

    // Configuração dos argumentos
    args.x = x;
    args.y = y;

#ifndef DEBUG
    // Criação do cliente RPC
    clnt = clnt_create(host, PROG, VERSAO, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror(host);
        exit(1);
    }
#endif /* DEBUG */

    // Chamada remota para ADD
    result_add = add_100(&args, clnt);
    if (result_add == (int *) NULL) {
        clnt_perror(clnt, "call failed for add_100");
    } else {
        printf("Soma: %d + %d = %d\n", x, y, *result_add);
    }

    // Chamada remota para SUB
    result_sub = sub_100(&args, clnt);
    if (result_sub == (int *) NULL) {
        clnt_perror(clnt, "call failed for sub_100");
    } else {
        printf("Subtração: %d - %d = %d\n", x, y, *result_sub);
    }

#ifndef DEBUG
    // Destruição do cliente RPC
    clnt_destroy(clnt);
#endif /* DEBUG */
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Uso: %s <host> <x> <y>\n", argv[0]);
        exit(1);
    }
    char *host = argv[1];
    int x = atoi(argv[2]);
    int y = atoi(argv[3]);

    prog_100(host, x, y);
    exit(0);
}
