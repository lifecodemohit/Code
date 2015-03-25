//author- Devyani 2012034

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



int v;

typedef enum { false, true } bool;

struct Q
{
    int front, rear, capc;
    int* arr;
};

struct Q* create(int capc)
{
struct Q* q =(struct Q*)malloc(sizeof(struct Q));
q->capc=capc;
q->front=q->rear = -1;
q->arr=(int*) malloc(q->capc * (sizeof(int)));

return q;
}

bool isempty(struct Q* q)
{
return q->front ==-1 ? true : false;
}

bool isfull(struct Q* q)
{
return q->rear==q->capc - 1 ? true : false;
}

void enqueue(struct Q* q, int item)
{
if (isfull(q))
return;
        
q->arr[++q->rear] = item;
if (isempty(q))
++q->front;
}

int dequeue(struct Q* q)
{
if (isempty(q))
return INT_MIN;
        
int item = q->arr[q->front];
if (q->front == q->rear)
q->front = q->rear = -1;
else
++q->front;
        
return item;
}

int initmatrix(int col[],int n)
{
int i;
for (i = 0; i < n; ++i)
col[i] = -1;
}

bool Bipartite(int Graph[v][v], int src,int V,int e)
{

int i,j;
/*
for(i=0;i<V;i++){
for (j=0;j<V;j++){
//G[i][j]=0;
printf("%d",G[i][j]);

}
printf("\n");

}*/
  int matrix[V], colour, tmp, w;
  initmatrix(matrix, V);
    
  struct Q* q= create(V);
  colour = 1;
  matrix[src] = colour;
    enqueue(q, src);

while(!isempty(q))
 {
 tmp = dequeue(q);
  colour = 1 - matrix[tmp];

for (w = 0; w < V; ++w)
{
 if (Graph[tmp][w] && matrix[w]==-1)
{
 matrix[w]=colour;
 enqueue(q, w);
  }
            
 else if (Graph[tmp][w] && matrix[w] ==matrix[tmp])
  return false; 
        }
    }
    
    return true;
}

int main()
{
int v1,v2;
int e;
int i,j;
int t;
//printf("enter no. of vertices and edges\n");
scanf("%d",&t);

while(t>0){
scanf("%d %d",&v,&e);
int Graph[v][v];

for(i=0;i<v;i++){
for (j=0;j<v;j++){
Graph[i][j]=0;
//printf("%d",G[i][j]);

}
//printf("\n");

}



for(i=1;i<=e;i++){
//printf("edge %d: ",i);
scanf("%d %d",&v1,&v2);
Graph[v1-1][v2-1]=1;
Graph[v2-1][v1-1]=1;
}
/*
for(i=0;i<v;i++){
for (j=0;j<v;j++){
//G[i][j]=0;
printf("%d",G[i][j]);

}
printf("\n");

}printf("\n\n");*/
    
Bipartite(Graph, 0,v,e) ? printf("YES\n") : printf("NO\n");
t--;	
}
 //   printf("\n");
    return 0;
}
