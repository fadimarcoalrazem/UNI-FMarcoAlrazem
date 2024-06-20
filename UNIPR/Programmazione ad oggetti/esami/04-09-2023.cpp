#include<stdio.h>
#include<stdlib.h>

void readdata(FILE*,char *N,char *K, char *M);
int* simul(int m, int k, int n);



void readdata(FILE*,char *N,char *K, char *M)
{
    *m=0;
    *k=0;
    *n=0;

    fscanf(fp, "%d %d %d",n,k,m);
}

int* simul(int m, int k, int n)
{
    int persone[m];
    for (int i=0;i<m;++i)
        persone[i]=i+1;
    int indice=0;

    while(m>n)
    {
        for(int i=1;i<k;++i)
        {
            do{
                indice=(indice+1) % m;
            } while(persone[indice]==0);
        }
        persone[indice=0];
        --m;
        do{
            indice=(indice+1)%m;
        } while(persone[indice]==0);
    }

    int *eletti=malloc(sizeof(int) *n);

    for(int i=0, j=0;i<m ;++i)
        if(persone[i])
            eletti[j++]=persone[i];
    return eletti;
}




int main(int argc,char **argv)
{
    FILE *fp=fopen("elezioni.txt", "r")
    if(!fp){
        perror("errore");
        exit(1);
    }

    int m,k,n;

    while(1)
    {
        readdata(fp,&m,&k,&n);
        if(!m)
            exit(0);

        printf("%d estratti su %d usando %d per la conta: ",n,m,k);

        int *eletti=simul(m,k,n);

        for(int i=0;i<n;++i)
         printf("%d", eletti[i]);
        printf("\b\b \n");

        free(eletti);
    }
    fclose(fp);
    return 0;
}