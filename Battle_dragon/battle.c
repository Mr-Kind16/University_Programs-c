#include "head.h"

void sceltaStatsDrago(Drago *d)
{   
                        /*funzione per l'inserimento dei dati di un drago*/
    char nome[LUN_MAX_NOMI];

    printf("Inserisci il Nome del drago\n");
    scanf("%s",nome);
    d->nome=xmalloc(strlen(nome)+1);
    strcpy(d->nome,nome);

    do{
        printf("Inserisci quanta vita ha il drago(multipli di 1000):\n");
        scanf("%d",&d->vita);
    }while(d->vita%1000!=0);

    do{
        printf("Inserisci il dps del drago (min:100;max:500):\n");
        scanf("%f",&d->dps);
    }while((d->dps<100) ||(d->dps>500));
    return;
}

int sceltaVincitore(Drago d1,Drago d2)
{                   /*funzione per la battaglia tra due draghi*/
    int i=0;
    srand(time(NULL));

    while((d1.vita>0) && (d2.vita>0))
    {
        printf("Situazione attuale:\n%s Ha %d LF\n %s Ha %d LF \n",d1.nome,d1.vita,d2.nome,d2.vita);

        printf("*********ROUND :%d**********\nChi attaccherà?\n",++i);
        suspense();

        if(rand()%2)
        {
            d2.vita-=d1.dps;
            printf("%s ha attaccato causando un danno di %f a %s\n",d1.nome,d1.dps,d2.nome);
        }
        else
        {
            d1.vita-=d2.dps;
            printf("%s ha attaccato causando un danno di %f a %s\n",d2.nome,d2.dps,d1.nome);
        }
    }

    if(d1.vita<0)
    {
        printf("********%s HA VINTO LA BATTAGLIA***********\n",d2.nome);
        return 2;
    }
    else
    {
        printf("********%s HA VINTO LA BATTAGLIA***********\n",d1.nome);
        return 1;
    }
}

void battle(char *path_name)
{
    Drago drago1,drago2;
    int vincitore;

    printf("Inserisci i dati del primo drago\n");
    sceltaStatsDrago(&drago1);
    printf("Inserisci i dati del secondo drago\n");
    sceltaStatsDrago(&drago2);

    vincitore=sceltaVincitore(drago1,drago2);

    if(vincitore==1)
    {
        salvaVittoria(path_name,drago1);
    }
    else
    {
        salvaVittoria(path_name,drago2);
    }
    return;
}