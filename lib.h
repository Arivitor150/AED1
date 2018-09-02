typedef struct Agenda{
    int cphone;
    char name[10];
}tipoagenda;

void menu();
void refreshVar(void *pBuffer, void **op, void **count, void **lp, tipoagenda **FirstC, tipoagenda **LastC);
void AddTo(void *pBuffer, int *count);
void PrintAll(void *pBuffer, tipoagenda **FirstC, tipoagenda **LastC);