#include "head.h"

void apri_crea(char data_path[])
{                   /*funzione per L'apertura o creazione di un file 
                    mod=1 se si vuole aprire in lettura
                    mod=2 se si vuole aprire in scrittura
                    3=scrittura e lettura */
    FILE *fcon;

    if(!(fcon=fopen(data_path,"ab+") ) )
    {
        printf("Errore nell'apertura del file\n");
        exit(-1);
    }
    fclose(fcon);
}

Save *leggiSaves(char *path_name,int *n_saves)
{                       /*funzione che legge tutti i saves e riempie una struttura di 
                        Save*/
    int n_righe;
    FILE *fcon=fopen(path_name,"rb");
    n_righe=savesCounter(fcon);

    Save *salvataggi=xmalloc(n_righe*sizeof(Save));
    printf("save\n");
    fread(salvataggi,sizeof(Save),n_righe,fcon);
    fclose(fcon);

    return salvataggi;
}
int savesCounter(FILE *fcon)
{   
                            /*funzione che conta le linee del file e ci dice se e vuoto
                            ritorna 0 se è vuoto sennò il numero di righe*/
    int n;
    if(fread(&n,sizeof(int),1,fcon)!=1)
    {
        return 0;
    }
    return n;
}

void stampaSalvataggi(Save *salvataggi,int n)
{
    int i,j;

    for(i=0;i<n;i++)
    {
        printf("Salvataggio n.%d\nVittorie : %d\nVincitori:\n",salvataggi[i].n_save,salvataggi[i].vittorie);
        for(j=0;j<salvataggi[i].vittorie;j++)
        {
            printf("Nome:%s\nVita:%d\nDPS:%.2f\n",salvataggi[i].vincitori[j].nome,salvataggi[i].vincitori[j].vita,salvataggi[i].vincitori[j].dps);
        }
    }
}

int upload_file(Save *salvataggi,char *path_name,int n,Save *nuovo_salvataggio)
{
    FILE *fcon=fopen(path_name,"wb");
    
    fwrite(&n,sizeof(int),1,fcon);
    fwrite(salvataggi,sizeof(Save),n,fcon);

    if(nuovo_salvataggio!=NULL)
    {
        fwrite(nuovo_salvataggio,sizeof(Save),1,fcon);
    }
    fclose(fcon);
    return 1;
}