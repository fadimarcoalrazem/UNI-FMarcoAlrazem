#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main (int argc,char **argv){

    int n = 0;
    int nparole=0;
    char **parole;
    do{
        printf("Enter a number between 8 and 14: ");
        scanf(" %d", &n);
    } while (n<8 || n>14);

    FILE *dict = fopen("dict.txt", "r");
    if(!dict)
    {
        perror("error");
        exit(EXIT_FAILURE);
    }

    char tmp[1000];
    while(fscanf(dict, " %s", tmp) == 1)
    {
        if(strlen(tmp) == n)
        {
            parole = realloc(parole, (nparole+1)*sizeof(char **));
            parole[nparole] = malloc((n+1)*sizeof(char));
            strcpy(parole[nparole],tmp);
            ++nparole;
        }
    }
    fclose(dict);

    srand(time(0));
    int rparola = rand() % nparole;
    char indovino[15]= "          ";

    int tentativi = n/1.5
    int indovinate=0;

    do
    {
        char c;
        printf("ti rimangono %d tentativi per indovinare:  %s",tentativi, indovino);
        printf("inserisci una lettera: ");
        scanf(" %c", &c);

        int presente=0;
        int i;
        for(int i=0;i<n;++i)
        {
            if(c == parole[rparola][i])
            {
                presente=1;
                indovino[i]=c;
                ++indovinate;
            }
        }
        if(!presente)
        --tentativi;
    }
    while(tentativi>0 && !indovinate==n);

    if(!tentativi)
    {
        printf("hai perso");
    }
    else {
        printf("hai vinto!");
    }


    return 0;
}