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
    struct adjnode* newn=newlistnode(d);
    newn->next=g->array[s].head;
    g->array[s].head=newn;
    newn=newlistnode(s);
    newn->next=g->array[d].head;
    g->array[d].head=newn;
}



int BFS(struct graph *g,int x)
{
    int visited[g->V],i,c=0;
    for(i=0;i<g->V;i++)
    {
        visited[i] = 0;
    }


    int q[g->V];
    int front=0;
    int rear=0;

    visited[x]++;
    q[rear]=x;
    rear++;

    while(rear!=front)
    {
	int w;
        w=q[front];
        front++;

        struct adjnode *a=g->array[w].head;

        while(a!=NULL)
        {
            if(visited[a->n]==0)
            {
                q[rear]=a->n;
                rear++;
            }
            visited[a->n]++;
            a=a->next;
        }
    }
    for(i=0;i<g->V;i++)
    {
    	if(visited[i]<2)
    	{
    		c=1;
    		break;
    	}
    }
    if(c==0)
    	printf("YES\n");
    else
    	printf("NO\n");
}

int main()
{
    int t;
    scanf("%d",&t);
    int a,b,V,E,i,c;
    while(t!=0)
    {
        scanf("%d %d",&V,&E);
        struct graph *g=newgraph(V);
        for(i=0;i<E;i++)
        {
            scanf("%d %d",&a,&b);
            add(g,a-1,b-1);
        }
        BFS(g,0);
        t--;
    }
    return 0;
}
