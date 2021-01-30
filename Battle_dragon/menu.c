#include "head.h"

void menu(char *path_name)
{               //funzione per il menu utente
    int scelta;
    int n_vittorie;

    printf("********BENVENUTO NEL DRAGON BATTLE ROYALE*********\n");
    do
    {
        printf("***********MENU***********1\n");
        printf("Scegli cosa vuoi fare:\n1:Battaglia da due draghi\n2:BATTAGLIA FINALE\n-1: ESCI\n");
        scanf("%d",&scelta);
        switch(scelta)
        {
            case 1:
            {
                battle(path_name);
            }
            break;
            case 2:
            {
                //finalBattle();
            }
            break;
            case -1:
            {

            }
            break;
            default:
            {
                printf("Scelta errata\n");
            }
        }

    }while(scelta!=-1);
}