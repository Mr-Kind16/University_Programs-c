#include "head.h"

void apri_crea(char data_path[])
{                   /*funzione per L'apertura o creazione di un file 
                    mod=1 se si vuole aprire in lettura
                    mod=2 se si vuole aprire in scrittura
                    3=scrittura e lettura */
    FILE *fcon;

    if(!(fcon=fopen(data_path,"a+") ) )
    {
        printf("Errore nell'apertura del file\n");
        exit(-1);
    }
    fclose(fcon);
}

int leggiSaves(char *path_name,Save *salvataggi)
{                       /*funzione che legge tutti i saves e riempie una struttura di 
                        Save*/
    int n_righe=lineCounter(path_name),i,j;
    salvataggi=xmalloc(n_righe*sizeof(Save));
    FILE *fcon=fopen(path_name,"r");

    int n_salvataggio,n_vittorie;
    char nome_drago[LUN_MAX_NOMI];


    for(i=0;i<n_righe;i++)
    {
        fscanf(fcon,"%d %d ",&n_salvataggio,&n_vittorie);
        salvataggi[i].n_save=n_salvataggio;
        salvataggi[i].vittorie=n_vittorie;

        for(j=0;j<n_vittorie;j++)
        {
            fscanf(fcon,"%s %d %f",nome_drago,&salvataggi[i].vincitori[j].vita,&salvataggi[i].vincitori[j].dps);
            salvataggi[i].vincitori[j].nome=xmalloc(strlen(nome_drago)+1);
            strcpy(salvataggi[i].vincitori[j].nome,nome_drago);
        }
        fscanf(fcon,"\n");
        fflush(fcon);
    }
    //stampaSalvataggi(salvataggi,n_righe);
    return n_righe;
}
int lineCounter(char *path_name)
{   
                            /*funzione che conta le linee del file e ci dice se e vuoto
                            ritorna 0 se è vuoto sennò il numero di righe*/
    int n=0;
    char c;
    FILE *fcon=fopen(path_name,"r");
    if(fgetc(fcon)==EOF)   //caso il file sia vuoto
    {
        return 0;
    }
    while(1)
    {                   //ciclo per contare il numero di righe
        c=fgetc(fcon);
        if(c==EOF)
        {
            return n;
        }
        if(c=='\n')
        {
            n++;
        }
    }
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

int upload_file(Save *salvataggi,char *path_name,int n)
{
    FILE *fcon=fopen(path_name,"w");
    int i,j;

    for(i=0;i<n;i++)
    {
        fprintf(fcon,"%d %d ",salvataggi[i].n_save,salvataggi[i].vittorie);
        for(j=0;j<salvataggi[i].vittorie;j++)
        {
            fprintf(fcon,"%s %d %f",salvataggi[i].vincitori[j].nome,salvataggi[i].vincitori[j].vita,salvataggi[i].vincitori[j].dps);
        }
        fprintf(fcon,"\n");
    }
    fclose(fcon);
    return 1;
}