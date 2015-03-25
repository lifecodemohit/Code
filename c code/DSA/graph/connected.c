#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
	int id;
	struct _node *next;
}node;
typedef struct _list{
	node *head;
}list;
typedef struct _graph{
	int v;
	int e;
//	int *visited;
	list *arr;
}graph;
typedef struct _queue
{
	int *arr;
	int front;
	int rear;
}queue;
int visited[100000];
graph *createGraph(int v, int e){
	graph *my_graph = (graph*)malloc(sizeof(graph));
	my_graph->v = v;
	my_graph->e = e;
	list *tempArr = (list*)malloc(v*sizeof(list));
	int i;
	for(i=0; i<v;i++){
		tempArr[i].head = (node*)malloc(sizeof(node));
		tempArr[i].head->id = i;
		tempArr[i].head->next = NULL;
	}
	my_graph->arr = tempArr;
//	my_graph->visited = (int*)malloc(v*sizeof(v));
	for(i=0; i<my_graph->v; i++){
		visited[i] = 0;
	}

	return my_graph;
}
/*
void destroyGraph(graph *g){
	int i, v = g->v;
	list tempList;
	node *tempNode, *tempNode2;
	for(i=0; i<v; i++){
		tempList = g->arr[i];
		tempNode = tempList.head;
		while(tempNode!=NULL){
			tempNode2 = tempNode->next;
			free(tempNode);
			tempNode = tempNode2;
		}
	}
//	free(g->visited);
	free(g->arr);
	free(g);
}
*/
void addEgde(graph *my_graph, int i, int j){
/*
	if(n->arr[i].head!=n&& i<=g->v && j<=g->v){
		node *t = g->arr[i].head;

		while(t->next!=NULL && t->id !=j)
			t = t->next;
		if(t->next == NULL && t->id!=j){
			node *tempNode = (node*)nloc(sizeof(nde));
			tempNode->id = j;n			t->next = tempNode;
			tempNode->next = NULL;
		}
	}
	if(g->arr[j].head!=NULL && i<=g->v && j<=g->v){
		node *t = g->arr[j].head;
		while(t->next!=NULL && t->id !=i)
			t = t->next;
		if(t->next == NULL && t->id!=i){
			node *tempNode = (node*)m
alloc(sizeof(node));
			tempNode->id = i;
			t->next = tempNode;
			tempNode->next = NULL;
		}
	my_graph
*/
	if(my_graph->arr[i].head!=NULL && i < my_graph->v && j < my_graph->v){
		node *tempNode = (node*)malloc(sizeof(node));
		tempNode->id = j;
		tempNode->next = my_graph->arr[i].head->next; 
		my_graph->arr[i].head->next = tempNode;
	}
	if(my_graph->arr[j].head!=NULL){
		if(j < my_graph->v && i < my_graph->v){
			node *tempNode = (node*)malloc(sizeof(node));
			tempNode->id = i;
			tempNode->next = my_graph->arr[j].head->next; 
			my_graph->arr[j].head->next = tempNode;
		}
	}

}
/*
void printGraph(graph *G){
	int i = 0;
	int n = G->v;
	for(i=0; i<n; i++){
		list tempList = G->arr[i];
		node *tempNode = tempList.head;
		printf("%d ", tempNode->id);
		while(tempNode->next!=NULL){
			tempNode = tempNode->next;
			printf("%d ", tempNode->id);
		}
		printf("\n");
	}
}
*/

void enqueue(queue *q, int i){
	if ((q->front==-1)&&(q->rear==-1)) {
		q->front = 0;
		q->rear = 0;
		q->arr[q->rear] = i;
	}

	else {
		(q->rear) = (q->rear) + 1;
		q->arr[q->rear] = i;
	}
}

int IsEmpty(queue *q){
	if (q->front == -1) {
		return 1;
	}
	else {
		return 0;
	}
}


int dequeue(queue *q){
	if (q->front <= q->rear) {
		int i = q->arr[q->front];
		q->front = q->front + 1;
		if (q->front > q->rear) {
			q->front = -1;
			q->rear =  -1;
		}
		return i;
	}
}


int bfs(graph *my_graph, int root){
	int i,n = my_graph->v;
	int level[n];
	visited[root] = 1;
	level[root] = 0;
	queue *q = malloc(sizeof(queue));
	q->front = -1;
	q->rear = -1;
	q->arr = malloc(n*sizeof(int));
	enqueue(q, root);
	int p;
	int sizeOfComp = 0;
	node *tempNode;
	while(!IsEmpty(q)){
		p = dequeue(q);
		sizeOfComp++;
		tempNode = my_graph->arr[p].head->next;
		while(tempNode!=NULL){
			if(visited[tempNode->id]==0){
				enqueue(q,tempNode->id);
				visited[tempNode->id]=1;
//				printf("lalal %d %d\n",tempNode->id, my_graph->visited[tempNode->id]);
			}
			tempNode = tempNode->next;			
		}
		// my_graph->visited[p]=2;
	}
	return sizeOfComp;
}

int cmpfunc (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}

int main(){
	int v, e, i;
	scanf("%d %d", &v, &e);
	graph *my_graph = createGraph(v, e);
	int x,y;
	for(i=0; i<e; i++){
		scanf("%d %d", &x, &y);
		x--;
		y--;
		addEgde(my_graph,x,y);
	}
	int compArr[v];
	int comp = 0;//number of components
	for(i=0;i<v; i++){
//		printf("\nvisited? %d %d\n",i, my_graph->visited[i]);
		if(visited[i]==0){
			compArr[comp]=bfs(my_graph, i);
			comp++;
		}
	}

	qsort(compArr, comp, sizeof(int), cmpfunc);
	printf("%d\n", comp);
	for(i=comp-1; i>=0; i--){
		printf("%d\n", compArr[i]);
	}
//	printGraph(my_graph);
	//destroyGraph(my_graph);
	return 0;
}