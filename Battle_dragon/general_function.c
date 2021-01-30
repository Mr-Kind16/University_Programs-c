#include "head.h"

void* xmalloc(size_t size)
{           /*funzione per l'allocazione dinamica della memoria di size byte*/
    void* puntatore;
    if(!(puntatore=malloc(size)))
    {
        printf("Errore nella memoria\n");
        exit(-1);
    }
    return puntatore;
}
void suspense(void)
{
    int i;
    printf("\n");
    for(i=0;i<4;i++)
    {
        printf(".\n");
        sleep(1);
    }
    return;
}