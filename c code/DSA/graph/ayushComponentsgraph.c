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
    int visited[g->V],i,components=0,component[g->V];
    for(i=0;i<g->V;i++)
    {
        visited[i] = 0;
    }

    int v;
    for (v = 0; v <g->V; v++) 
    {
    if (!visited[v]) {
    components++;

    int q[1000000];
    int front=0;
    int rear=0;

    visited[v] = 1;
    q[rear]=v;
    rear++;
    

    while(rear!=front)
    {
	component[components]++;
	int w;
        w=q[front];
        front++;

        struct adjnode *a=g->array[w].head;

        while(a!=NULL)
        {
            if(visited[a->n]!=1)
            {
                visited[a->n] =1;
                q[rear]=a->n;
                rear++;
            }
            a=a->next;
        }
    }
    }
    }
    printf("%d\n",components);
    mergeSort(component,1,components);
    for(i=components;i>0;i--)
    	printf("%d\n",component[i]);
    return 0;
}

void merge(int component[], int b, int m, int t)
{
    int i, j, k;
    int s1 = m - b + 1;
    int s2 =  t - m;
    
    int l[s1], r[s2];
 
    for(i = 0; i < s1; i++)
        l[i] = component[b + i];
    for(j = 0; j < s2; j++)
        r[j] = component[m + 1+ j];
 
    i = 0;
    j = 0;
    k = b;
    while (i < s1 && j < s2)
    {
        if (l[i] <= r[j])
        {
            component[k] = l[i];
            i++;
        }
        else
        {
            component[k] = r[j];
            j++;
        }
        k++;
    }
 
    while (i < s1)
    {
        component[k] = l[i];
        i++;
        k++;
    }
 
    while (j < s2)
    {
        component[k] = r[j];
        j++;
        k++;
    }
}
 
void mergeSort(int component[], int b, int t)
{
    if (b < t)
    {
        int m = b+(t-b)/2;
        mergeSort(component, b, m);
        mergeSort(component, m+1, t);
        merge(component, b, m, t);
    }
}

int main()
{
    int a,b,V,E,i,c;
    scanf("%d %d",&V,&E);
    struct graph *g=newgraph(V);
    for(i=0;i<E;i++)
    {
        scanf("%d %d",&a,&b);
        add(g,a-1,b-1);
    }
    BFS(g);
    return 0;
}

