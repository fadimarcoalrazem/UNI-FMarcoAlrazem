#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char leggi_file(void);
char sentence2morse(char *,char **);


char leggi_file(void)
{
    FILE *fp=fopen("morse.txt", "r");
    if(!fp)
    {
        perror("");
        exit(1);
    }

    char **morse= malloc(26*sizeof(char));
    char lettera,codifica[1000];

    for(int i=0;i<26;++i)
    {
        fscanf(fp,"%c %s", lettera, codifica);
        morse[i]=malloc((strlen(codifica)+1)*sizeof(char));
        strcpy(morse[i],codifica);
    }

    return morse;
}

char *sentence2morse(char *frase,char **codifica)
{
    char tmp[10000] = " ";

    for(int i=0;i<strlen(frase);++i)
    {
        if(frase[i]==' ')
        {
            strcat(tmp,"  ");
        }
        else
        {
            char lettera=toupper(frase[i]);
            strcat(tmp,codifica[lettera - 'A']);
            strcat(tmp," ");
        }
      }
      char *risultato = malloc((strlen(tmp)+1) * sizeof(char));
      strcpy(risultato,tmp);

      return risultato;
    }

    int main(int argc,char **argv){
        char **morse= leggi_file();
        printf("dal file leggo codifiche: \n");
        for (int i=0;i<26,++i)
        {
            printf("%c -> %s",'A' + i,morse[i]);
        }

        while(1)
        {
            char scelta,tmp[1000],result;
            printf("inserisci 'c' per codifica, 'd' per decodifica e 'x' per uscire ");
            scanf("\n%c",&scelta);

            switch(scelta)
            {
                case 'x':
                printf("uscita in corso..");
                exit(EXIT_SUCCESS);
                case 'c':
                printf("inserire frase da codificare: ");
                scanf("[^]",tmp);
                result =  sentence2morse(tmp,codifica);
                printf("la frase [%s] si codifica come [%s]",tmp,result);
                free(result);
                break;
                    default:
                printf("seclta sbagliata")
            }
        }

    return 0;
    
    }