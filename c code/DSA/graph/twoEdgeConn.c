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
//int visited[1000];
//int nVisited[1000];
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
/*
	for(i=0; i<my_graph->v; i++){
		visited[i] = 0;
		nVisited[i] = 0;
	}
*/
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

int x = 0;
void bfs(graph *my_graph, int root){
	int i,n = my_graph->v;
	int nVisited[n];
	for(i=0; i<n; i++){
		nVisited[i] = 0;
	}
	nVisited[root]++;
	queue *q = malloc(sizeof(queue));
	q->front = -1;
	q->rear = -1;
	q->arr = malloc(n*sizeof(int));
	enqueue(q, root);
	int p;
	node *tempNode;
	while(!IsEmpty(q)){
		p = dequeue(q);
		tempNode = my_graph->arr[p].head->next;
		while(tempNode!=NULL){
			if(nVisited[tempNode->id]==0){
				enqueue(q,tempNode->id);
			}
			nVisited[tempNode->id]++;
			tempNode = tempNode->next;			
		}
	}
	int flag = 0;
	for(i=0;i<my_graph->v; i++){
		if(nVisited[i]<2){
			flag = 1;
			break;
		}
	}
	if(flag==0)
		printf("YES\n");
	else
		printf("NO\n");
}


int main(){
	int t;
	scanf("%d",&t);
	int v, e, i;
	while(t>0){
		scanf("%d %d", &v, &e);
		graph *my_graph = createGraph(v, e);
		int x,y;
		for(i=0; i<e; i++){
			scanf("%d %d", &x, &y);
			x--;
			y--;
			addEgde(my_graph,x,y);
		}
/*
		for(i=0;i<v; i++){
			if(visited[i]==0)
			nVisited[i]++;
		}
*/
	//	printf("\n");
	//	printGraph(my_graph);
/*
		int flag = 0;
		for(i=0; i<v; i++){
			if(nVisited[i]<=2){
				flag=1;
				break;
			}
			// printf("%d\n", nVisited[i]);
		}
		if(flag==0){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
*/
//		destroyGraph(my_graph);
//		printGraph(my_graph);		
		bfs(my_graph, 0);
		t--;
	}
	return 0;
}