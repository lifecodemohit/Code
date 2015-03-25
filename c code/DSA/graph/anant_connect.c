#include <stdio.h>
#include <stdlib.h>

struct AdjListNode
{
	int id;
	struct AdjListNode *next;
};

struct AdjList
{
	struct AdjListNode *head;
};

struct graph
{
	int V;
	struct AdjList *neighbors;
};

struct queue
{
	int front;
	int rear;
	int *arr;
};

int comparator(const void *a, const void *b) 
{
	return (0-(*(int*)a - *(int*)b));
}

void enqueue(struct queue *q, int i)
{
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

int dequeue(struct queue *q)
{
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

int IsEmpty(struct queue *q)
{
	if (q->front == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

struct graph *CreateGraph(int number_of_nodes)
{
	int i;
	struct graph *g = malloc(sizeof(struct graph));
	g->V = number_of_nodes;
	g->neighbors = malloc(sizeof(struct AdjList)*number_of_nodes);
	for (i=0; i<number_of_nodes; i++) {
		(g->neighbors)[i].head = malloc(sizeof(struct AdjListNode));
		((g->neighbors)[i].head)->id = i + 1;
		((g->neighbors)[i].head)->next = NULL;
	}
	return g;
}

void AddEdge(struct graph *g, int i, int j)
{
	struct AdjListNode *temp = malloc(sizeof(struct AdjListNode));
	temp->id = j;
	temp->next = (g->neighbors[i-1].head)->next;
	(g->neighbors[i-1].head)->next = temp;

	struct AdjListNode *kemp = malloc(sizeof(struct AdjListNode));
	kemp->id = i;
	kemp->next = (g->neighbors[j-1].head)->next;
	(g->neighbors[j-1].head)->next = kemp;
}

void PrintGraph(struct graph *g)
{
	int i;
	struct AdjListNode *temp_current = NULL;
	struct AdjListNode *temp_next = NULL;
	for (i=0; i<(g->V); i++) {
		temp_current = ((g->neighbors)[i]).head;
		temp_next = temp_current->next;
		while (temp_current!=NULL) {
			printf("%d ", temp_current->id);
			temp_current = temp_current->next;
		}
		printf("\n");
	}
}

void BFS(struct graph *g, int i, int *visited)
{
	int j, u, v;
	for (j=0; j<g->V; j++) {
		visited[j] = 0;
	}
	visited[i] = 1;
	struct queue *q = malloc(sizeof(struct queue));
	q->front = -1;
	q->rear = -1;
	q->arr = malloc(sizeof(int)*g->V);
	struct AdjListNode *temp = NULL;
	enqueue(q, i);
	while (!IsEmpty(q)) {
		u = dequeue(q);
		temp = g->neighbors[u].head;
		while (temp!=NULL) {
			v = temp->id - 1;
			if (visited[v]==0) {
				visited[v] = 1;
				enqueue(q, v);
			}
			temp = temp->next;
		}
		visited[u] = 2;
	}
}

void DFS(struct graph *g, int u, int *visited, int *n)
{
	int v;
	struct AdjListNode *temp = g->neighbors[u].head->next;
	while (temp!=NULL) {
		v = temp->id - 1;
		if (visited[v]==0) {
			n[0] = n[0] + 1;
			visited[v] = 1;
			DFS(g, v, visited, n);
		}
		temp = temp->next;
	}
}

int main()
{
	int v, e, x, y, i, count = 0;

	scanf("%d %d", &v, &e);
	struct graph *g = CreateGraph(v);

	int *visited = malloc(sizeof(int)*v);

	for (i=0; i<v; i++) {
		visited[i] = 0;
	}

	for (i=0; i<e; i++) {
		scanf("%d %d", &x, &y);
		AddEdge(g, x, y);
	}

	int *array = malloc(sizeof(int)*v);
	int *n = malloc(sizeof(int)); 
	n[0] = 1;

	for (i=0; i<v; i++) {
		if (visited[i]==0) {
			visited[i] = 1;
			DFS(g, i, visited, n);
			array[count] = n[0];
			n[0] = 1;
			count++;
		}
	}

	qsort(array, count, sizeof(int), comparator);
	printf("%d\n", count);
	for (i=0; i<count; i++) {
		printf("%d\n", array[i]);
	}
	return 0;
}