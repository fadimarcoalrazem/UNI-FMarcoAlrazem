#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bivi{
    int ind_a[100];
    int ind_b[100];
    int ind_c[100]
    int n;
};

void pop(struct bivi *stack, int *ind_a,int *ind_b,int *ind_c);
void push(struct bivi *stack,const int *ind_a,const int *ind_b,const int *ind_c);

int main(int argc,char **argv){
    struct bivi stack;

    char a[51], b[51], c[101], dest[101];

    FILE *fp= fopen("intarsi.txt", "r");
    if(!fp)
    {
        perror("errore in apertura del file");
        exit(1);
    }
    while((fscanf(fp,"%[^,],%[^,],%[^\n]",a,b,c)==3))

    {
        stack.n=0;

        int ia=0,ib=0,ic=0;
        while(ia<strlen(a) && ib<strlen(b))
        {
            if(c[ic]==' ')
            {
                dest[ic]=' ';
                ++ic;
            }
            else if(a[ia]==c[ic] && a[ia] != b[ib])
            {
                dest[ic]='a';
                ++ic;
                ++ia;
            }
            else if(b[ib]==c[ic] && a[ia]!=b[ib])
            {
                dest[ic]='b';
                ++ic;
                ++ib;
            }
            else if(a[ia]==b[ib] && c[ic]==b[ib])
            {
                push(&stack,ia,ib,ic);
                dest[ic]='a';
                ++ic;
                ++ia;
            }
            else
            {
                pop(&stack,&ia,&ib,&ic);
                dest[ic]='b';
                ++ic;
                ++ib;
            }
        }
        while(ia<strlen(a))
        {
            dest[ic]='a';
            ++ic;
            ++ia;
        }
        while(ib<strlen(b))
        {
            dest[ic]='b';
            ++ib;
            ++ic;
        }

        dest[ic]='\0';
        printf("lo schema che da %s e %s mi porta a %s è %s\n",a,b,c,dest);
    }
    return 0;
}

void pop(struct bivi *stack, int *ind_a,int *ind_b,int *ind_c);
{
    if(!stack->n)
    {
        fprintf(stderr,"Errore: stack vuoto");
        exit(EXIT_FAILURE);
    }
    *ind_a=stack->ind_a[stack->n-1];
    *ind_b=stack->ind_b[stack->n-1];
    *ind_c=stack->ind_c[stack->n-1];
    stack->n = stack->n-1;
}
void push(struct bivi *stack,const int *ind_a,const int *ind_b,const int *ind_c);
{
    stack->ind_a[stack->n] = ind_a;
    stack->ind_b[stack->n] = ind_b;
    stack->ind_c[stack->n] = ind_c;
    stack->n = stack->n+1;
}
