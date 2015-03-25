//author-Devyani 2012034

#include<stdio.h>
#include<stdlib.h>


#define maxV   100000

typedef struct Q
{
        int capc;
        int size;
        int front;
        int rear;
        int *elts;
}Q;

Q * create(int maxelts)
{
Q *Que;
Que=(Q *)malloc(sizeof(Q));
  Que->elts=(int *)malloc(sizeof(int)*maxelts);
  Que->size = 0;
  Que->capc = maxelts;
  Que->front = 0;
  Que->rear = -1;
 return Que;
}

void dequeue(Q *Que)
{
 if(Que->size==0)
   {
   printf("Empty\n");
    return;
  }
  else
   {
  Que->size--;
   Que->front++;
  if(Que->front==Que->capc)
   {
      Que->front=0;
      }
      }
  return;
}
int front(Q *Que)
{
 if(Que->size==0)
 {
 printf("Empty\n");
   exit(0);
 }
  return Que->elts[Que->front];
}
void enqueue(Q *Que,int elt)
{
  if(Que->size == Que->capc)
    {
    printf("Full\n");
    }
  else
  {
  Que->size++;
  Que->rear = Que->rear + 1;
  if(Que->rear == Que->capc)
   {
   Que->rear = 0;
   }
   Que->elts[Que->rear] = elt;
    }
   return;
}
int bfs(int graph[][maxV], int *size, int currentV,int *visited)
{
int countv=0; 
 visited[currentV] = 1;
  Q *Que = create(maxV);
  enqueue(Que,currentV);
 while(Que->size)
  {
   currentV = front(Que);
	countv++;
 dequeue(Que);
   int i;
   for(i=0;i<size[currentV];i++)
      {
    if(!visited[graph[currentV][i]])
      {
  visited[graph[currentV][i]] = 1;
  enqueue(Que,graph[currentV][i]);
                        }
              }
        }
 return countv;
        

}


int main()
{
int countbfs=0;

int iter=0,c;
        int graph[maxV][maxV],size[maxV]={0},visited[maxV]={0};
        int v,e,i;
        scanf("%d %d",&v,&e);

int countv[v];
int u;
for(u=0;u<v;u++){
countv[u]=0;
}

        int v1,v2;
        for(i=1;i<=e;i++)
        {
      scanf("%d %d",&v1,&v2);
       graph[v1][size[v1]++] = v2;
graph[v2][size[v2]++] = v1;
        }
        int currentV;
 for(currentV=1;currentV<=v;currentV++)
        {
   if(!visited[currentV])
                {
   countv[iter++]= bfs(graph,size,currentV,visited);
countbfs++;
                }
			
		//countv[i++]=c;
        }

//	printf("bfs is called %d times.\n",countbfs);
printf("%d\n",countbfs);
int j,k,temp;
//n=countbfs;

//int largest=countv[0];
/*
for(j=0;j<countbfs;j++){
if(countv[j]>largest){
largest=countv[j];
}
//printf("component %d has %d vertices\n",j,countv[j]);

}
printf("largest %d",largest);	*/

/*
for(j=0;j<countbfs;j++)
{
for(k=0;k<countbfs;k++){
if(countv[j] < countv[k]){
  temp=countv[j];
  countv[j]=countv[k];
  countv[k]=temp;
    }
}

}

for(j=0;j<countbfs;j++){
printf("%d\n",countv[j]);	
}
*/

  
  for(i=0;i<countbfs;i++)
     {
           for(j=0;j<countbfs-i;j++)
           {
                 if(countv[j]<countv[j+1])
                 {
                       temp=countv[j+1];
                       countv[j+1]=countv[j];
                       countv[j]=temp;
                 }
           }
     }
     
     //printf("\n\n Array in the Descending order is - \n");
     for(i=0;i<countbfs;i++)
     {
           printf("%d\n",countv[i]);
     }
	
        return 0;
}
