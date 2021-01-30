#include <stdio.h>
#define DIMMAX 100

int ins_dim(void);
void riempi_vet(int vet[],int dim);
int shift_vet(int dim,int pos_i,int vet[]);
int compatta1(int dim,int vet[]);
void stampa_vet(int dim,int vet[]);


int main(void)
{
    int dim=ins_dim();
    int vet[DIMMAX];
    
    riempi_vet(vet,dim);
    dim=compatta1(dim,vet);
    stampa_vet(dim,vet);
    return 0;
    
}

int compatta1(int dim,int vet[])
{         //la funzione compatta un vettore ordinato o non
    int i=0;
    
    while(i<dim-1)
    {       //ciclo che scorre tutto il vettore fino alla nenultima posizione
        if(vet[i]==vet[i+1])
        {       //nel caso c'è una ricorrenza di due elementi adiacenti 
                //si shifta il vettore chiamando la funzione shift_vet()
            dim=shift_vet(dim,i+1,vet);
        }
        i++;
    }
    return dim;
}

int shift_vet(int dim,int pos_i,int vet[])
{
                        //funzione che shifta di elementi un vettore
    int i=pos_i;
    int j,dim_2;
    
    while(i<dim && vet[pos_i]==vet[i])
    {
        i++;
    }
    
    j=pos_i;
    dim_2=i;
    while(i<dim)
    {
        vet[j]=vet[i];
        j++;
        i++;
    }
    return j;
}

int ins_dim(void)
{                   /*la funzione controlla il numero inserito                           dall'utente ossia la lunghezza del vettore*/
    int dim=0;
    do
    {
        printf("Inserisci la lunghezza del vettore desiderata\n");
        scanf("%d",&dim);
    }while(dim<1||dim>DIMMAX);
    
    return dim;
    
}

void riempi_vet(int vet[],int dim)
{           /*la funzione riempie un vettore di dim elementi*/
    int i=0;
    
    while(i<dim)
    {
        printf("inserisci il numero nella posizione %d: \n",i+1);
        scanf("%d",&vet[i]);
        i++;
    }
    
}

void stampa_vet(int dim,int vet[])
{
    int i=0;
    
    printf("Il vettore ha:\n");
    while(i<dim)
    {
        printf("%d\n",vet[i]);
        i++;
    }
}









