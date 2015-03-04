#include <stdio.h>
#include <stdlib.h>


struct AdjListNode
{
    int id;
    struct AdjListNode* next;
};

struct AdjList
{
    struct AdjListNode *head;
};

struct Graph
{
    int V;
    struct AdjList* Neighbours;
};


struct AdjListNode* newAdjListNode(int id)
{
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->id = id;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;


    graph->Neighbours = (struct AdjList*) malloc(V * sizeof(struct AdjList));

    int i;
    for (i = 0; i < V; ++i)
        graph->Neighbours[i].head = NULL;

    return graph;
}


void addEdge(struct Graph* graph)
{
    int src, id;
    printf("Enter source of edge: \n");
    scanf("%d", &src);
    printf("Enter data for edge: \n");
    scanf("%d", &id);
    struct AdjListNode* newNode = newAdjListNode(id);
    newNode->next = graph->Neighbours[src].head;
    graph->Neighbours[src].head = newNode;

    newNode = newAdjListNode(src);
    newNode->next = graph->Neighbours[id].head;
    graph->Neighbours[id].head = newNode;
}

void deledge(struct Graph* graph)
{
    int src, id;
    printf("Enter source of edge: \n");
    scanf("%d", &src);
    printf("Enter data for edge: \n");
    scanf("%d", &id);
    int i,j;
    if (src<id)
    {
        i=src;
        j=id;
    }
    else
    {
        i=id;
        j=src;
    }
    if(graph->Neighbours[i].head==j)
    {
        graph->Neighbours[i].head=NULL;
    }
    else
        while (graph->Neighbours[i].head->next!=NULL)
        {
            if (graph->Neighbours[i].head->next==j)
            {
                graph->Neighbours[i].head=NULL;
            }
            graph->Neighbours[i].head->next=graph->Neighbours[i].head->next->next;
        }
    //graph->Neighbours[i].head=NULL;
    //graph->Neighbours[j].head=NULL;
    //free (graph->Neighbours[i].head);

}
void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->Neighbours[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->id);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}


int main()
{
    int n;
    printf("Enter greatest value of vertex");
    scanf("%d",&n);
    int V = n+1;
    struct Graph* graph = createGraph(V);

    while(1)
    {
        int choice;
        printf("1. add edge\n2. Print graph\n3. Delete edge\n4. exit\n ");
        scanf("%d", &choice);
        if(choice == 1)
            addEdge(graph);
        else if(choice ==2)
            printGraph(graph);
        else if(choice ==3)
            deledge(graph);
        else if(choice ==4)
            exit(0);
    }

    return 0;
}