#include<stdio.h>
#include<stdlib.h>

struct node
{
    int dest;
    struct node* next;
};

struct list
{
    struct node *head;
};

struct Graph
{
    int V;
    struct list* array;
};

struct node* newlistnode(int dest)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->dest = dest;
    newnode->next = NULL;
    return newnode;
};

struct Graph* create(int V)
{
    struct Graph* graph = (struct graph*)malloc(sizeof(struct node));
    graph->V = V;
    graph->array = (struct list*)malloc(V* sizeof(struct list));
    int i;
    for(i=0; i<V; i++)
        graph->array[i].head = NULL;
    return graph;
};

void addedge(struct Graph* graph)
{
    int src;
    int dest;
    printf("Enter src>> ");
    scanf("%d", &src);
    printf("\nEnter dest>> ");
    scanf("%d", &dest);
    struct node* newnode = newlistnode(dest);
    newnode->next = graph->array[src].head;
    graph->array[src].head  newnode;
    graph->array[src].head = newnode;
    newnode = newlistnode(src);
    newnode->next = graph->array[dest].head;
    graph->array[dest].head = newnode;
}

void print(struct Graph* graph)
{
    int v; 
    for(v = 0; v<graph->V; v++)
    {
        struct node* ptr = graph->array[v].head;
        printf("\nAdjacency list of vertex %d\n head ". v);
        while(ptr)
        {
            printf("-> %d", ptr->dest);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    int V;
    struct Graph* graph = create(V);
    printf("\nMaximum Number of vertices>> ");
    scanf("%d", &V);
    int q;
    while(1)
    {
        printf("1. addedge\n 2.exit\n 3. print\n");
        
        if("q==1")
        {
            printf("")


























