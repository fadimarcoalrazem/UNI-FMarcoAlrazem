#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *leggiparola(FILE*);
int doppia(char *);
int assonante(char *);

int main(int argc,char **argv){

    char nomefile[10000]="promr.txt";
    printf("inserisci il nome di un file");
    scanf("%s", nomefile);

    FILE *txt=fopen(nomefile,"r");
    if(!txt)
    {
        perror("");
        exit(1);
    }

    char *parola;
    char **parole=NULL;
    int nparole=0;

    while(parola=leggiparola(txt))
    {
        int trovata=0;
        for(int i=0;i<nparole;++i)
            if(!strcmp(parola,parole[i]))
            {
                trovata=1;
                break;
            }

            if(!trovata)
            {
                parole=realloc(parole,sizeof(char*)*(nparole+1));
                parole[nparole] = parola;
                ++nparole;
            }
    }
    printf("\n");

printf("le parole doppie sono: \n")
for(int i=0;i<nparole;++i)
    if(doppia(parole[i]))
        printf(" %s",parole[i]);

printf("le parole assonanti sono: \n")
for(int i=0;i<nparole;++i)
    if(doppia(parole[i]))
        printf(" %s",parole[i]);

    return 0;
}

char leggiparola(FILE* f)
{
    char parola[10000];
    char pulita[10000];

    while(1)
    {
        if(fscanf(f," %s",parola) != 1)
            return NULL;

        for(int i=0;i<strlen(parola);++i)
        {
            parola[i]=tolower(parola[i]);
        }
    
    int ip=0;
    for(int i=0;i<strlen(parola);++i)
    {
        if(isalpha(parola[i]))
        {
            pulita[ip] = parola[i];
            ++ip;
        }
    }
    pulita[ip]= '\0';

    if(strlen(pulita))
    {
        char *p=malloc(strlen(pulita)+1);
        strcpy(p,pulita);
        return p;
     }
   }
}

int doppia(char *s)
{
    if(strlen(s)%2)
     return 0;

    int mid= strlen(s)/2;

    for(int i=0;i<mid;++i)
     if(s[i] != s[i+mid])
      return 0;

    return 1;
}

int assonante(char *s)
{
    if(!strlen(s)%2 || strlen(s) == 1)
        return '0'
}