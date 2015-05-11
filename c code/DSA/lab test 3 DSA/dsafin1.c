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
	list *arr;
}graph;

int visited[1000];
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
	for(i=0; i<my_graph->v; i++){
		visited[i] = 0;
	}

	return my_graph;
}

void addEgde(graph *my_graph, int i, int j){
	if(my_graph->arr[i].head!=NULL && i < my_graph->v && j < my_graph->v){
		node *tempNode = (node*)malloc(sizeof(node));
		tempNode->id = j;
		tempNode->next = my_graph->arr[i].head->next; 
		my_graph->arr[i].head->next = tempNode;
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
int color[1000];
// 0 white
// 1 black
// 2 grey
int pie[1000];
int d[1000];
int f[1000];
int time;
int flag = 0;
int counter = 0;
int arr[1000];
void dfsVisit(graph *G, int u){
	color[u] = 2;
	time = time+1;
	d[u] = time;
	list tempList = G->arr[u]; 
	node *tempNode = tempList.head;
	while(tempNode->next!=NULL){
		if(color[tempNode->id]==1){
			flag = 1;
			printf("-1\n");
		}
		else if(color[tempNode->id]==0){
			pie[tempNode->id] = u;
			dfsVisit(G, tempNode->id);
		}
		tempNode = tempNode->next;
	}
	color[u] = 1;
	time = time+1;
	f[u] = time;
}

void dfs(graph *G, int root){
	// printf("%d ", root);
	arr[counter] = root;
	counter++;
	int i,n = G->v;
	for(i=0; i<n; i++){
		color[i] = 0;
		pie[i] = -1;
	}
	time = 0;
	for(i=0; i<n; i++){
		if(color[i]==0){
			dfsVisit(G,i);
		}
	}
}

int main(){
	int t;
	scanf("%d", &t);
	while(t>0){
		int v, e, i;
		scanf("%d %d", &v, &e);
		graph *my_graph = createGraph(v, e);
		int x,y;
		for(i=0; i<e; i++){
			scanf("%d %d", &x, &y);
			if(x==y)
				flag = 1;
			addEgde(my_graph,x,y);
		}
		for(i=0; i<v; i++){
			visited[i] =0;
			addEgde(my_graph,i,i);
		}
		for(i=0;i<v; i++){
			if(visited[i]==0){
				dfs(my_graph, i);
			}
		}
		if(flag==0){
			for(i=0; i<counter; i++){
				printf("%d ", arr[i]);
			}		
			printf("\n");
		}
		else{
			printf("-1\n");
		}
		t--;
		counter  = 0;
		flag = 0;
		time = 0;
		// printGraph(my_graph);
	}
	return 0;
}