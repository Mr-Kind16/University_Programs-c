#include <stdio.h>
#define DIMMAX 100

int ins_dim(void)
{
    int dim=0;
    do
    {
        printf("Inserisci la lunghezza del vettore\n");
        scanf("%d",&dim);
    }while(dim<1 || dim>DIMMAX);
    return dim;
}

void riempi_vet(int vet[],int dim)
{           /*la funzione riempie un vettore di dim elementi*/
    int i=0;
    
    while(i<dim)
    {
        do
        {
            printf("inserisci il numero nella posizione %d: \n",i+1);
            scanf("%d",&vet[i]);
        }while(vet[i]<100 || vet[i]>999);
        i++;
    }
    
}

int decine(int num)
{               //funzione che estrapola le decine da un intero
    int d;
    
    d=(num/10)%10;
    d=d*d*d;
    return d;
}

int unità(int num)
{               //funzione che estrapola le unità da un intero
    int u;
    
    u=num%10;
    u=u*u*u;
    return u;
}

int centinaia(int num)
{               //funzione che estrapola le centinaia da un intero
    int c;
    
    c=num/100;
    c=c*c*c;
    return c;
}

int verifica_arm(int num)
{           //funzione che verifica se un numero è di armstrong
    int idoneo=0;
    int u=unità(num);
    int d=decine(num);
    int c=centinaia(num);
    
    if(u+d+c==num)
    {
        idoneo=1;
    }
    return idoneo;
}

void azzera_non_arm(int vet[],int dim)
{                       //funzione che azzere gli elementi di un vettore che non sono numeri di armstrong
    int i=0;
    
    while(i<dim)
    {
        if(!verifica_arm(vet[i]))
        {
            vet[i]=0;
        }
        i++;
    }
}

void stampa_vet(int dim,int vet[])
{
    int i=0;
    
    printf("Il vettore ha:\n");

    while(i<dim)
    {
        if(vet[i]!=0)
        {
            printf("%d\n",vet[i]);
        }
        i++;
    }
}

int main (void)
{
    int dim=ins_dim();
    int vet[DIMMAX];
    
    riempi_vet(vet,dim);
    azzera_non_arm(vet,dim);
    stampa_vet(dim,vet);
    
    return 0;
}







