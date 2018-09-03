typedef struct Agenda{
    int cfone;
    char nome[10];
}tipoagenda;

void menu();
void attVar(void *pBuffer, void **op, void **count, void **lp);
void adcTo(void *pBuffer, int *count);
void printAll(void *pBuffer, void *count, void *lp);
