#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h> 

#define LUN_MAX_NOMI 20
#define DATA_PATH "saves.txt"


typedef struct drago{
    char *nome;
    int vita;
    float dps;
}Drago;

typedef struct save{
    int n_save;
    int vittorie;
    Drago vincitori[3];
}Save;

void menu(char *path_name);
void* xmalloc(size_t size);
void suspense(void);
void sceltaStatsDrago(Drago *d);
int sceltaVincitore(Drago d1,Drago d2);
void battle(char *path_name);
void apri_crea(char data_path[]);
int leggiSaves(char *path_name,Save *salvataggi);
int lineCounter(char *path_name);
void crea_save(char *path_name);
int salva(char *path_name,int pos,Drago vincitore);
void salvaVittoria(char *path_name,Drago vincitore);
void stampaSalvataggi(Save *salvataggi,int n);
int upload_file(Save *salvataggi,char *path_name,int n);