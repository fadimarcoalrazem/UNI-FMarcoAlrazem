#include <stdio.h>
#include <stdlib.h>

struct elemento{
    char nome[201];
    int rgt,lft;
};

struct gerarchia{
    struct elemento nodi[100];
    int num_nodi;
};

int find_next_sibling(struct gerarchia tree,int index);
int find_first_son(struct gerarchia tree,int index);
void print_hierarchy(struct gerarchia tree,int index,int level);

int main(int argc,char **argv){
    FILE *fp=fopen("nested2.csv","r");
    if(!fp)
    {
        perror("");
        exit(EXIT_FAILURE);
    }

    struct gerarchia tree;
    tree.num_nodi = 0;

    while(fscanf(fp,"%[^;];%d;%d",tree.nodi[tree.num_nodi].nome, tree.nodi[tree.num_nodi].lft,tree.nodi[tree.num_nodi].rgt)==3)
    {
        tree.numn_nodi++;
    }

    fclose(fp);

    print_hierarchy(tree,0,0);

    return 0;
}

int find_next_sibling(struct gerarchia tree,int index){
    int i;

    for(i=0;i<tree.num_nodi;++i)
    {
        if(tree.nodi[i].lft==(tree.nodi[index].rgt + 1)){
            return i;
        }
    }
    return -1;
}

int find_first_son(struct gerarchia tree,int parent){
    int i;
    for(i=0;i<tree.num_nodi;++i){
        if((tree.nodi[i].lft) == (tree.nodi[parent].lft+1)) && (tree.nodi[i].rgt<tree.nodi[parent].rgt)
        return i;
    }
    return -1;
}
void print_nome(const char *s,const int level){
    int i;
    for(i=0;i<level;++i)
        printf(" ");
    printf("%s\n",s);
}
void print_hierarchy(const struct gerarchia tree, const int index, const int level){
    int search;

    if(index>=tree.num_nodi)
        return;
    
    print_nome(tree.nodi[index].nome,level);
    search=find_first_son(tree,index);
    if (search>=0)
    {
        print_hierarchy(tree,search,level+1);
    }

    search=index;
    if ((search = find_next_sibling(tree,search)) != -1)
    {
        print_hierarchy(tree,search,level);
    }
}