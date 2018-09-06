#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    void *pBuffer;
    void *op;
    void *count;
    void *lp;

    pBuffer = (void*)malloc((sizeof(int)*3));
    *(int *)pBuffer = 0; // Menu de Opção
    *(int *)(pBuffer + sizeof(int)) = 0; // Looping
    *(int *)(pBuffer + (2*sizeof(int))) = 0; // Variavel Contadora

    attVar(pBuffer, &op, &count, &lp);
    adcTo(pBuffer, count);
    attVar(pBuffer, &op, &count, &lp);

    tipoagenda * test;
    test = pBuffer + (sizeof(int)*3) + ( *(int *)count * sizeof(tipoagenda));
    printf("Phone : %d\n", test->cfone);
    printf("Nome  : %s \n", test->nome);


    /*AddTo(pBuffer, *(int *)op);
    refreshVar(pBuffer, &op, &count, &lp);
    test = pBuffer + (sizeof(int)*3) + ( *(int *)count * sizeof(tipoagenda));
    printf("Phone : %d\n", test->fone);
    printf("Nome  : %s \n", test->nome); */



    return 0;
}
