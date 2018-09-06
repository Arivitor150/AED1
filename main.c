#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

void attVar(void *pBuffer, void **op, void **count, void **lp){
    *op = pBuffer;
    *lp = pBuffer+sizeof(int);
    *count = pBuffer + (2*sizeof(int));

}

void adcTo(void *pBuffer, int *count){

        *count = *count + 1;

        pBuffer = realloc(pBuffer, (3 * sizeof(int)) + ( (*count) * sizeof(tipoagenda)));
        tipoagenda * test;

        test = pBuffer + (3 * sizeof(int)) + ( (*(int *)(pBuffer + (2*sizeof(int)))) * sizeof(tipoagenda));

        printf("Digite o Numero\n");
        scanf("%d",&test->cfone);
        printf("Digite o Nome\n");
        //__fpurge(stdin);
        fgets (test->nome , (sizeof(char)*10) , stdin);

}

void printAll(void *pBuffer, void *count, void *lp){
    printf("Buffer: %p\n", pBuffer + (3 * sizeof(int)) + ( (*(int *)count) * sizeof(tipoagenda)));

    if(*(int *)count > 0){
        tipoagenda * test;
        for(*(int *)lp = 0; (*(int *)lp) < (*(int *)count); (*(int *)lp)++){

                test = pBuffer + (3 * sizeof(int)) + ( (*(int *)lp) * sizeof(tipoagenda));
                printf("\n");
                printf("Phone:%d\n", test->cfone);
                printf("Name:%s\n", test->nome);
                printf("\n");
        }
}
}

void menu(){
        /*pBuffer = realloc(pBuffer, (sizeof(pBuffer) + sizeof(tipoagenda)));
        tipoagenda * test;
        test = pBuffer + (sizeof(int)*3) + sizeof(tipoagenda);
        test->cphone = 999;
        test->name[0] = 't';
        printf("R2:%d\n", sizeof(pBuffer));
        printf("Ce : %d\n", &test->cphone);
        printf("No : %d\n", &test->name[0]);
        // *(int *)pBuffer = 7;
        // *(int *)(pBuffer + sizeof(int)) = 9;
        // *op = 10;
        // *lp = 5;
        //printf("RefV : %d\n", *(int *)pBuffer);
        */


 //   tipoagenda * test;
  //  test = pBuffer + (sizeof(int)*3) + sizeof(tipoagenda);
   // printf("Ce : %d\n", test->cphone);
   // printf("No : %d\n", test->name[0]);
    //printf("M: %d\n", pBuffer);

        //printf("Main : \n");
   // printf("OP : %i\n", op);
   // printf("LP : %i\n", *(int *)lp);
    //printf("CO : %i\n", *(int *)counT);

}
