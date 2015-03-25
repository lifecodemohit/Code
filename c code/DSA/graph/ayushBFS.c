#include<stdio.h>
#include<stdlib.h>

struct adjnode
{
    int n;
    struct adjnode* next;
};

struct adjlist
{
    struct adjnode *head;
};

struct graph
{
   int V;
   struct adjlist* array;
};

struct adjnode* newlistnode(int n)
{
    struct adjnode* newNode =(struct adjnode*) malloc(sizeof(struct adjnode));
    newNode->n = n;
    newNode->next = NULL;
    return newNode;
}

struct graph *newgraph(int v)
{
    struct graph *g=(struct graph*)malloc(sizeof(struct graph));
    g->V=v;
    g->array=(struct adjlist*)malloc(v*sizeof(struct adjlist));
    int i;
    for(i=0;i<v;i++)
    {
        ((g->array)[i]).head = malloc(sizeof(struct adjnode));
        g->array[i].head=NULL;
    }
    return g;
}

void add(struct graph *g,int s, int d)
{
    //int v;
    struct adjnode* newn=newlistnode(d);
    newn->next=g->array[s].head;
    g->array[s].head=newn;
    newn=newlistnode(s);
    newn->next=g->array[d].head;
    g->array[d].head=newn;
}



int BFS(struct graph *g)
{
    int visited[g->V],level[g->V],i;
    for(i=0;i<g->V;i++)
    {
        visited[i] = 0;
        level[i]=0;
    }

    int v;
    for (v = 0; v <g->V; v++) {
    if ( ! visited[v] ) {

    int q[1000000];
    int front=0;
    int rear=0;

    visited[v] = 1;
    level[v]=0;
    q[rear]=v;
    rear++;

    while(rear!=front)
    {
	int w;
        w=q[front];
        front++;

        struct adjnode *a=g->array[w].head;

        while(a!=NULL)
        {
            if(visited[a->n]!=1)
            {
                visited[a->n] =1;
                level[a->n]=1+level[w];
                q[rear]=a->n;
                rear++;
            }
            else
            {
                if(level[a->n]==level[w])
                {
                    return 0;
                }
            }
            a=a->next;
        }
    }
    }
 }
    return 1;
}

int main()
{
    int t;
    scanf("%d",&t);
    int a,b,V,E,i,c;
    while(t!=0)
    {
        scanf("%d %d",&V,&E);
	if(V==2)
{
		printf("YES\n");
		continue;
}
        struct graph *g=newgraph(V);
        for(i=0;i<E;i++)
        {
            scanf("%d %d",&a,&b);
            add(g,a-1,b-1);
        }
        c=BFS(g);
        if(c==0)
            printf("NO\n");
        else
            printf("YES\n");
        t--;
    }
    return 0;
}