#include<stdio.h>
#include<stdlib.h>
typedef struct _AdjListNode{
	int id;
	struct _AdjListNode *next;
}AdjListNode;
typedef struct _AdjList{
	AdjListNode *head; 
}AdjList;
typedef struct _graph{
	int v;
	AdjList *arr;
}graph;


graph *createGraph(int num){
	graph *my_graph = (graph*)malloc(sizeof(graph));
	my_graph->v = num;
	AdjList *tempArr;
	tempArr = (AdjList*)malloc(num*sizeof(AdjList));
	int i;
	for(i=0; i<num; i++){
		tempArr[i].head = (AdjListNode*)malloc(sizeof(AdjListNode));
		tempArr[i].head->id = i;
		tempArr[i].head->next = NULL;
	}
	my_graph->arr = tempArr;
	return my_graph;
}
void DestroyGraph(graph *G){
	// banana banana banana
	int i, n = G->v;
	AdjList tempList;
	AdjListNode *tempNode;		
	for(i=0; i<n; i++){
		tempList = G->arr[i];
		tempList.head->next = NULL;

	}
	free(G);
}
void addEdge(graph *my_graph, int i, int j){

	if(my_graph->arr[i].head!=NULL){
		if(i < my_graph->v && j < my_graph->v){
			AdjListNode *tempNode = (AdjListNode*)malloc(sizeof(AdjListNode));
			tempNode->id = j;
			tempNode->next = my_graph->arr[i].head->next; 
			my_graph->arr[i].head->next = tempNode;
		}
	}
	if(my_graph->arr[j].head!=NULL){
		if(j < my_graph->v && i < my_graph->v){
			AdjListNode *tempNode = (AdjListNode*)malloc(sizeof(AdjListNode));
			tempNode->id = i;
			tempNode->next = my_graph->arr[j].head->next; 
			my_graph->arr[j].head->next = tempNode;
		}
	}
}
void deleteEdge(graph *G, int i, int j){
	if(i < G->v && j < G->v){
		//deleting edge i-j
		AdjList tempList = G->arr[i];
		AdjListNode *tempNode = tempList.head;
		AdjListNode *tempNode2 = tempList.head;
		while(tempNode->next!=NULL && tempNode->id!=j){
			tempNode2 = tempNode;
			tempNode = tempNode->next;
		}
		if(tempNode->id==j){
			tempNode2->next = tempNode->next;
		}
		//deleting edge j-i
		tempList = G->arr[j];
		tempNode = tempList.head;
		tempNode2 = tempList.head;
		while(tempNode->next!=NULL && tempNode->id!=i){
			tempNode2 = tempNode;
			tempNode = tempNode->next;
		}
		if(tempNode->id==i){
			tempNode2->next = tempNode->next;
		}
	}
}
void printGraph(graph *G){
	int i = 0;
	int n = G->v;
	for(i=0; i<n; i++){
		AdjList tempList = G->arr[i];
		AdjListNode *tempNode = tempList.head;
		printf("%d ", tempNode->id);
		while(tempNode->next!=NULL){
			tempNode = tempNode->next;
			printf("%d ", tempNode->id);
		}
		printf("\n");
	}
}
void addNode(graph *my_graph, int n){
	my_graph = (graph*)realloc(sizeof(graph));
	int m = my_graph->v;
	my_graph->v = n;
	AdjList *tempArr;
	tempArr = (AdjList*)malloc(num*sizeof(AdjList));
	int i;
	for(i=m; i<n; i++){
		tempArr[i].head = (AdjListNode*)malloc(sizeof(AdjListNode));
		tempArr[i].head->id = i;
		tempArr[i].head->next = NULL;
	}
	my_graph->arr = tempArr;
	return my_graph;

}
void printStats(graph *G){
	printf("number of nodes: %d\n", G->v);
	int numEdges=0;
	int i, n = G->v;
	AdjList tempList;
	AdjListNode *tempNode;
	for(i=0; i<n; i++){
		tempList = G->arr[i];
		tempNode = tempList.head;
		if(tempNode->id > i)
			numEdges++;
		while(tempNode->next!=NULL){
			tempNode = tempNode->next;
			if(tempNode->id > i)
				numEdges++;
		}
	}	
	printf("number of edges: %d\n", numEdges);
	printf("avg degree: %d\n", numEdges*2/n);
	int minD = 100;
	int maxD = 0;
	int count = 0;	
	for(i=0; i<n; i++){
		tempList = G->arr[i];
		tempNode = tempList.head;
		count++;
		while(tempNode->next!=NULL){
			tempNode = tempNode->next;
			count++;
		}
		if(count<=minD){
			minD = count;
		}
		if(count>=maxD){
			maxD = count;
		}
		count = 0;
	}
	printf("Min degree: %d\nMax degree: %d\n", minD, maxD);
}
void main(){
	graph *my_graph=createGraph(5);
	addEdge(my_graph, 0, 4);
	addEdge(my_graph, 1, 2);
	addEdge(my_graph, 0, 3);
	addEdge(my_graph, 4, 3);
	printGraph(my_graph);
	deleteEdge(my_graph, 1, 2);
	printGraph(my_graph);
	printStats(my_graph);
	DestroyGraph(my_graph);
	printGraph(my_graph);
}