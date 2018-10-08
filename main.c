#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Agenda{
    int cfone;
    char nome[10];
}tipoagenda;

void menu(void *pBuffer,void *op);
void attVar(void *pBuffer, void **op, void **count, void **lp);
void *adcTo(void *pBuffer, void *count);
void *remover(void *pBuffer, void *count, void *lp);
void printAll(void *pBuffer, void *count, void *lp);

int main(){
	
    void *pBuffer;  // Inicio da agenda
    void *op;       // Opção do menu
    void *count;    // Número de contatos
    void *lp;       // contato a ser exibido(varia até ser igual ao número de contatos)

    pBuffer = ((void*)malloc((sizeof(int)*3) + sizeof(tipoagenda)));
  //pBuffer = 3 vars de controle + 1 contato vazio;

    (*(int *)pBuffer) = 0; // Menu de Opção
    (*(int *)(pBuffer + sizeof(int))) = 0; // Looping
    (*(int *)(pBuffer + (2*sizeof(int)))) = 1; // Variavel Contadora, o primeiro é auxiliar
    printf("op- %d \n",*(int *)pBuffer);
    printf("lp- %d \n",*(int *)(pBuffer + sizeof(int)));
    printf("count- %d \n",*(int *)(pBuffer+(2*sizeof(int))));

	attVar(pBuffer,&op,&count,&lp);
	menu(void *pBuffer,void *op);
    //attVar(pBuffer,&op,&count,&lp);
    //pBuffer = adcTo(pBuffer, count);
    attVar(pBuffer,&op,&count,&lp);
    pBuffer = adcTo(pBuffer, count);
    attVar(pBuffer,&op,&count,&lp);
    pBuffer = adcTo(pBuffer, count);
    attVar(pBuffer,&op,&count,&lp);
    printAll(pBuffer,count,lp);
    pBuffer = remover(pBuffer, count, lp);
    attVar(pBuffer,&op,&count,&lp);
    



    free(pBuffer);
    return 0;
}

//-------------------------------------------------------------/
//--------------------------FUNÇÕES----------------------------/
//-------------------------------------------------------------/

void attVar(void *pBuffer, void **op, void **count, void **lp){
    *op = pBuffer;
    *lp = pBuffer+sizeof(int);
    *count = pBuffer + (2*sizeof(int));
}

void *adcTo(void *pBuffer, void *count){
        tipoagenda *add;
        *(int *)count = (*(int *)count) + 1;
//printf("count- %d \n",*(int *)(pBuffer+(2*sizeof(int))));

        pBuffer = realloc(pBuffer, (3 * sizeof(int)) + ( (*(int *)count) * sizeof(tipoagenda)));
        add = pBuffer + (3 * sizeof(int)) + ( (*(int *)count) * sizeof(tipoagenda));

//printf("Buffer(add): %p \n", pBuffer + (3 * sizeof(int)) + sizeof(tipoagenda) + ( (*(int *)count) * sizeof(tipoagenda)));
        printf("Digite o Numero \n");
        scanf("%d",&add->cfone);
        getchar(); //pega o enter, para ele n ser pego pela proxima leitura
        printf("Digite o Nome \n");
//__fpurge(stdin); // no achou a função, para limpar o buffer do teclado(windows)
        fgets (add->nome , (10 * sizeof(char)) , stdin);
        printf("\n");
return pBuffer;
}

void printAll(void *pBuffer, void *count, void *lp){
//printf("Buffer(print): %p \n", pBuffer + (3 * sizeof(int)) + sizeof(tipoagenda) + ( (*(int *)count) * sizeof(tipoagenda)));
   tipoagenda *exibe;

    if((*(int *)count) > 0){
        for( *(int *)lp = 2; *(int *)lp <= *(int *)count; (*(int *)lp)++ ){
                //printf("Buffer(print): %p \n", pBuffer + (3 * sizeof(int)) + ( (*(int *)lp) * sizeof(tipoagenda)));
                exibe = pBuffer + (3 * sizeof(int)) + ( (*(int *)lp) * sizeof(tipoagenda));
            //  exibe = inicio da area de memoria + vars de controle + contato vazio + contato a ser exibido;
                printf("Fone: %d \n", exibe->cfone);
                printf("Nome: %s \n", exibe->nome);
        }
    }
}

void *remover(void *pBuffer, void *count, void *lp){
        //printf("\033[H\033[J"); //limpa tela
        tipoagenda *rem,*aux;
        aux = pBuffer + (sizeof(int)*3) + sizeof(tipoagenda);

        printf("Digite o numero do contato que você deseja remover. \n");
        	scanf("%d",&(aux->cfone));
        	getchar(); //pega o enter, para ele n ser pego pela proxima leitura
        printf("\n");
        for( (*(int *)lp) = 2; (*(int *)lp) <= (*(int *)count); (*(int *)lp)++){
            rem = pBuffer + (3 * sizeof(int)) + ( (*(int *)lp) * sizeof(tipoagenda));
            if( aux->cfone == rem->cfone ){
            	while(  (*(int *)lp) <= (*(int *)count) ){
					rem = pBuffer + (3 * sizeof(int)) + ( (*(int *)lp) * sizeof(tipoagenda));
            		aux =  pBuffer + (3 * sizeof(int)) + (((*(int *)lp)+1) * sizeof(tipoagenda));
                    strcpy(rem->nome,aux->nome);
                    rem->cfone = aux->cfone;
                }
            (*(int *)count)--;
            pBuffer = realloc(pBuffer, (3 * sizeof(int)) + ((*(int *)count) * sizeof(tipoagenda)));
            return pBuffer;
            }
        }
printf("Contato Não localizado. \n");
return pBuffer;
}

void menu(void *pBuffer,void *op){
        
        printf("\n ---------------- \n");
        printf("1: Printar \n");
        printf("2: Adicionar \n");
        printf("3: Remover \n");
        printf("4: \n");
        printf("\n ---------------- \n");
        
        scanf("%d",&((int *)op);
        
        switch *(int *)op:
			case 1: printAll(pBuffer,count,lp);

			case 2:
			
			case 3:
}
/*
void *remover(void *pBuffer, void *count, void *lp){
   
        tipoagenda *rem,*aux;
        aux = pBuffer + (sizeof(int)*3) + sizeof(tipoagenda);

        printf("Digite o numero do contato que você deseja remover. \n");
        	scanf("%d",&aux->cfone);
        	getchar(); //pega o enter, para ele n ser pego pela proxima leitura
        printf("\n");
        for( *(int *)lp = 2; *(int *)lp <= *(int *)count; (*(int *)lp)++){
            rem = pBuffer + (3 * sizeof(int)) + ( (*(int *)lp) * sizeof(tipoagenda));
            if(aux->cfone == rem->cfone){
                //laço puxa o proximo pra frente no buffer
            	while((*(int *)lp) < (*(int *)count)){
                    aux =  pBuffer + (3 * sizeof(int)) + ( (*(int *)lp) * sizeof(tipoagenda));
            		rem =  pBuffer + (3 * sizeof(int)) + (((*(int *)lp)+1) * sizeof(tipoagenda));
                    aux->cfone = rem->cfone;
                    strcpy(aux->nome,rem->nome);
                    (*(int *)lp)++;
                }
                aux = pBuffer; // aux aponta para à area antiga
                (*(int *)count)--;
                pBuffer = malloc( (3 * sizeof(int)) + ( (*(int *)count) * sizeof(tipoagenda)) );
                //pBuffer para a nova
            
                //copiando para nova area de memo
                (*(int *)pBuffer) = (*(int *)aux);
                (*(int *)(pBuffer + sizeof(int))) = (*(int *)(aux + sizeof(int)));
                (*(int *)(pBuffer + (2 * sizeof(int)))) = (*(int *)(aux + (2 * sizeof(int))));
                for( *(int *)lp = 2; *(int *)lp <= *(int *)count; (*(int *)lp)++){
                    aux =     aux + (sizeof(int)*3) + ( (*(int *)lp) * sizeof(tipoagenda)); 
                    rem = pBuffer + (sizeof(int)*3) + ( (*(int *)lp) * sizeof(tipoagenda));
                    rem->cfone = aux->cfone;
                    strcpy(rem->nome,aux->nome);
                }
            free(aux);
        }
    break;
    }
return pBuffer;
}*/
