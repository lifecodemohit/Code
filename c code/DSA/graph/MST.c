#include<stdio.h>
#include<stdlib.h>
typedef struct _edge{
	int src, dest, w;
}Edge;

typedef struct _graph{
	int v,e;
	Edge *edge; 
}graph;

graph *createGraph(int V, int E){
	graph *g = (graph*)malloc(sizeof(graph));
	g->v = V;
	g->e = E;
	g->edge = (Edge*)malloc(E*(sizeof(Edge)));
	return g;
}

typedef struct _subset{
	int parent;
	int rank;
}subset;


int find(subset subsets[], int i){
	if(subsets[i].parent!=i)
		subsets[i].parent = find(subsets, subsets[i].parent);
	return subsets[i].parent;
}
int Union(subset subsets[], int x, int y){
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);
	if(subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if(subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;
	else{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
	return;
}

int myComp(const void *a, const void *b){
	Edge *a1 = (Edge*)a;
	Edge *b1 = (Edge*)b;
	return a1->w > b1->w;
}
void swap(int *a, int *b){
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
int kruskal(graph *g){
	int V = g->v;
	Edge result[V];
	int E = 0;
	int i= 0;
	int j = 0;
	qsort(g->edge, g->e, sizeof(g->edge[0]), myComp);
	subset *subsets = (subset*)malloc(V*sizeof(subset));
	for(j=0; j<V; ++j){
		subsets[j].parent = j;
		subsets[j].rank = 0;
	}
	while(E<V-1){
		Edge next_edge = g->edge[i++];
		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);
		if(x!=y){
			result[E++] = next_edge;
			Union(subsets, x, y);
		}
	}
	int a, b, c;
	for(i=0; i<E; ++i){
		a = result[i].src;
		a++;
		b = result[i].dest;
		b++;
		c = result[i].w;
		if(a>b){
			swap(&a, &b);
		}
		printf("%d %d %d\n", a, b, c);
	}
	return;
}
int main(){
	int t;
	scanf("%d", &t);
	while(t>0){
		t--;
		int v,e,i;
		int a, b, c;
		scanf("%d %d", &v, &e);
		graph *G = createGraph(v,e);
		for(i=0; i<e; i++){
			scanf("%d %d %d", &a, &b, &c);
			a--;
			b--;
			G->edge[i].src = a;
			G->edge[i].dest = b;
			G->edge[i].w = c;
		}
/*		
		printf("lalala\n");
		for(i=0; i<e; i++){
			printf("%d %d %d\n", ++G->edge[i].src, ++G->edge[i].dest, G->edge[i].w);
		}
		printf("lalala\n");
*/
		kruskal(G);
	}
	return 0;
}