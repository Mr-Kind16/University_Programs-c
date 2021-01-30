#include "head.h"


int main (void)
{
    apri_crea(DATA_PATH); //aprendo il file in appending all'inizio ci assicuriamo che esista

    menu(DATA_PATH);

    return 1;
}