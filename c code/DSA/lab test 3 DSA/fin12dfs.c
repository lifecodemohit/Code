#include <stdio.h>
#include <stdlib.h>

struct AdjListNode
{
    int id;
    struct AdjListNode* next;
};
struct AdjList{
    struct AdjListNode *head;  // pointer to head node of list
};
struct Graph{
    int V;
    struct AdjList* array;
};
struct AdjListNode* newAdjListNode(int dest){
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->id = dest;
    newNode->next = NULL;
    return newNode;
}
struct Graph* createGraph(int V){
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
void addEdge(struct Graph* graph, int src, int dest){
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

int dfsVisit(struct Graph *G, int u, int *color, int *pred, int *topo){
	color[u] = 1;
	struct AdjListNode *neighbors = G->array[u].head;
	while(neighbors!=NULL){
		if(color[neighbors->id]==1){
			//printf("Loop Found\n");
			return -1;
		}
		else if(color[neighbors->id]==0){
			pred[neighbors->id] = u;
			if(dfsVisit(G, neighbors->id, color, pred, topo) < 0)
				return -1;
		}
		neighbors = neighbors->next;
	}
	color[u] = 2;
	printf("Topo 0, u ---> %d, %d\n", topo[0], u);
	topo[topo[0]++] = u;
	return 0;
}
void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
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
	int T, N, M, src, dest, i, loops = 0;
	int *color, *pred, *topo;
	scanf("%d",&T);
	while(T--) {
		loops = 0;
		scanf("%d %d", &N, &M);
		// color = (int*) malloc(N * sizeof(int));        
		// pred = (int*) malloc(N * sizeof(int));
		// topo = (int*) malloc((N+1) * sizeof(int));
        int color[N];
        int pred[N];
		int topo[N+1]; 
        topo[0] = 1;
		struct Graph* graph = createGraph(N);
		while(M--) {
			scanf("%d %d", &src, &dest);
			if(src != dest)
    			addEdge(graph, src, dest);
    	}
    	for(i=0;i<N;i++) {
    		color[i] = 0;
    		pred[i] = -1;
    	}
    	for(i=0;i<N;i++) {
    		if(color[i] == 0) {
    			loops += dfsVisit(graph,i,color,pred,topo);
    		}
    	}
    	
    	if(loops < 0) {
    		printf("-1\n");
    	}
    	else {
    		for(i=N;i>0;i--) 
				printf("%d ",topo[i]);
    		
    		printf("\n");
    	}
        // printGraph(graph);	
    }
    return 0;
}
