#include<stdio.h>
#include<stdlib.h>

int mod = 1000000007;
unsigned long long int modExp(long long int a, long long int b){
	unsigned long long int result = 1;
	while(b>0){
		if(b%2==1){
			result = (result*a)%mod;
		}
		b >>= 1;
		a = (a*a)%mod;
	}
	return result;
}
typedef struct _AdjListNode{
	int id;
	struct _AdjListNode *next;
}AdjListNode;
typedef struct _AdjList{
	AdjListNode *head; 
	int weight;
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

void addEdge(graph *my_graph, int i, int j){

	if(my_graph->arr[i].head!=NULL && i < my_graph->v && j < my_graph->v){
		AdjListNode *tempNode = (AdjListNode*)malloc(sizeof(AdjListNode));
		tempNode->id = j;
		tempNode->next = my_graph->arr[i].head->next; 
		my_graph->arr[i].head->next = tempNode;
		my_graph->arr[i].weight = 1;
	}

}
void printGraph(graph *G){
	int i = 0;
	int n = G->v;
	for(i=0; i<n; i++){
		AdjList tempList = G->arr[i];
		AdjListNode *tempNode = tempList.head;
		printf("%d, (%d) ", tempNode->id, tempList.weight);
		while(tempNode->next!=NULL){
			tempNode = tempNode->next;
			printf("%d ", tempNode->id);
		}
		printf("\n");
	}
}

int alpha(int n){
	return (n)*2;
}
int beta(int n){
	return (n)/2;
}
int findL(int n){
	printf("%d %d\n", alpha(n), beta(n));
	return ((n+alpha(n) + 2*(beta(n)))/2) -1;
}
int findK(int n){
	return findL(n)%100000;
}

int main(){
	printf("%d\n", findL(6));
	int N, Q, i, u, v, m;
	scanf("%d %d", &N, &Q);
	graph *my_graph=createGraph(N);
	for(i=0; i<N-1; i++){
		scanf("%d %d", &u, &v);
		u--; v--;
		addEdge(my_graph, u, v);	
	}
	int q;
	for(i=0; i<Q; i++){
		scanf("%d", &q);
		if(q==0){
			scanf("%d %d", &v, &m);
			v--;
			int K = findK(m);
			AdjList tempList = my_graph->arr[v];
			tempList.weight += K*m; 
			printf("blah blah %d\n", tempList.weight);
		}
		else{
			scanf("%d", &v);

		}
	}
	printGraph(my_graph);
	return 0;
}