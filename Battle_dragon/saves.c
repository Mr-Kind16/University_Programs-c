#include "head.h"

void crea_save(char *path_name)
{                   //funzione che crea un nuovo salvataggio
    int n_saves;
    Save *salvataggi=leggiSaves(path_name,&n_saves);;

    Save nuovo_salvataggio;
    nuovo_salvataggio.n_save=1;
    nuovo_salvataggio.vittorie=0;
    upload_file(salvataggi,path_name,n_saves+1,&nuovo_salvataggio);
}

int salva(char *path_name,int pos,Drago vincitore)
{               //funzione che salva una partita
                //ritorna 1 se è stata salvata correttamente sennò 0
    Save *salvataggi;
    int esito=0,j;
    int n;
    salvataggi=leggiSaves(path_name,&n);

                //non controlliamo la pos visto che lo controlliamo gia in precedenza 
    if(salvataggi[pos-1].vittorie==3)
    {               //controllo se sono state gia salvate tre vittorie
        printf("Sono stati già salvate 3 vittorie su questo salvataggio\n");
    }

    j=salvataggi[pos-1].vittorie;
    strcpy(salvataggi[pos-1].vincitori[j].nome,vincitore.nome);
    salvataggi[pos-1].vincitori[j].vita=vincitore.vita;
    salvataggi[pos-1].vincitori[j].dps=vincitore.dps;

    salvataggi[pos-1].vittorie++;
    stampaSalvataggi(salvataggi,n);
    return  upload_file(salvataggi,path_name,n,NULL);
}



void salvaVittoria(char *path_name,Drago vincitore)
{               /*Funzione che salva una vittoria*/
    int scelta,esito=0;
    FILE *fcon;
    fcon=fopen(path_name,"rb");
    int n=savesCounter(fcon);
    fclose(fcon);
    
    if(n==0)
    {               //caso in cui il File è vuoto
        printf("File vuoto, devi creare un nuovo salvataggio 1=yes 0=no\n");
        scanf("%d",&scelta);
        if(scelta)
        {
            crea_save(path_name);
            esito=salva(path_name,n+1,vincitore);
        }
    }
    else
    {             //caso in cui nel file ci sono dei salvataggi
        do{
            printf("Ci sono %d salvataggi disponibili\nPuoi scergliene uno col suo nuomero o crearne uno nuovo (0)\n",n);
            scanf("%d",&scelta);
        }while((scelta<0) ||(scelta>n));

        if(scelta==0)
        {                           //se si vuole creare in nuovo salvataggio
            crea_save(path_name);
            esito=salva(path_name,n+1,vincitore)==1;
        }
        else
        {                           //caso se si vuole selezionare un salvataggio esistente
           esito=salva(path_name,scelta,vincitore);
        }
    }
    if(esito==0)
    {               //controllo esito salvataggio
        printf("Partita non salvata correttamente\n");
    }
    else
    {
        printf("Partita salvata correttamente\n ");
    }
}
