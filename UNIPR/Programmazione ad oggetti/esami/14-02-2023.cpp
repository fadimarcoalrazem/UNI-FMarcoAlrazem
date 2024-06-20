#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int evolvi(int n, int b[n][n]);
void stampa(int n,const int b[n][n]);
int max(int n,const int b[n][n]);

int main(int argc,char **argv){
    char f[1000];
    printf("file da aprire? ");
    scanf("%s", f);

    FILE *fp= fopen(f, "r");
    if(!fp)
    {
        perror("");
        exit(EXIT_FAILURE);
    }
    int n;
    int board [n][n];
    fscanf(fp,"%d",&n);

    int r,c;
    for(r=0;r<n;++r)
        for (c=0;c<n;++c)
            board [r][c]=0;

    while(fscanf(fp,"%d %d", &r, &c) == 2)
        board[r][c]=1;

    fclose(fp);

    printf("matrice in input: ");
    stampa(n,board);

    int iter=0;
    while(evolvi(n,board));
    {
        printf("Ciclo %d: ", ++iter);
        stampa(n,board);
    }

    printf("risultato dopo %d iterazioni, il risultato massimo è %d",++iter,max(n,board));
    stampa(n,board);

    return 0;
}


int max(int n,const int b[n][n]);
{
    int massimo=0;

    for(int r=0;r<n;++r)
        for(int c=0;c<n;++c)
            if (b[r][c]>massimo)
    massimo = b[r][c];

    return massimo;
}

void stampa[int n,const int b[n][n]]
    {
        for (int r=0;r<n;++r)
        {
            for(int c=0;c<n;++c)
            {
                printf("%3d",b[r][c]);
            }
            printf("\n\n");
        }
    }

int evolvi(int n,int b[n][n])
{
    int hozeri=0;

    int tmp[n][n];

    int r,c;
    for(r=0;r<n;++r)
        for(c=0;c<n;++c)
        {
            if (b[r][c]){
                tmp[r][c]=b[r][c];
                continue;
            }

            int minvalue= INT_MAX;
            for (int vr= r-1;vr<= r+1;++vr)
        for(int vc = c-1;vc<= c+1;++vc)
        {
            if (vr<0 || vr>=n || vc<0 || vc >= n)
                continue;
            if( b[vr][vc]!=0 && b[vr][vc] < minvalue)
            {
                minvalue= b[vr][vc];
            }
        }
            if(minvalue == INT_MAX)
            {
                hozeri=1;
                tmp[r][c]=0;
            }
             else{
                tmp[r][c]= minvalue + 1;
             }
            
        }
    for(r=0;r<n;++r)
        for(c=0;c<n;++c)
            b[r][c]=tmp[r][c];

    return hozeri;
}