#include<stdio.h>                                //For standard input/output functions #include<stdlib.h>                               //For standard library functions
void dfs();                                            // For Deapth First Search(DFS) Traversal
void bfs();                                            // For Breadth First Search(BFS) Traversal

struct link                                            // Structure for adjacency list
{
struct node *next;
struct link *adj;
};

struct node                                          // Structure for elements in the graph
{
int data,status;
struct node *next;
struct link *adj;
};

struct node *start,*p,*q;                   //Declaring pointer variable for structure node
struct link *l,*k;                                 //Declaring pointer variable for structure node

void create()                                        // Function to Create the graph
{
int dat,flag=0;dat=1;                          //Initializing 'flag' & 'dat' with a value of '0' & '1' start=NULL;                                      //'start' pointing to NULL, as no value is being input till now printf("Enter the nodes in the graph(0 to end): ");
while(dat)
{
scanf("%d",&dat);                           //Getting the data from user 
 if(dat==0)                                    //If data entered is '0' then assume its the end of inputting elements 
break;
p=(struct node*)malloc(sizeof(struct node));  //reserving memory space for nodal element p->data=dat;                                                       //storing the input data into node's data element
p->status=0;
p->next=NULL;                                                 //next element is set to NULL p->adj=NULL;                                                   //previous element is set to NULL
 if(flag==0)                                                          //If flag's value is zero then follow below procedure 
{
start=p;
q=p;
flag++;
}                                                                            //If flag's value is not zero then follow below method else
{
q->next=p;
q=p;
}
}                                                                           //Finishing the data entry loop p=start;                                                               //Assigning the pointer 'p' the starting location while(p!=NULL)
{                                                    
printf("Enter the links to %d (0 to end) : ",p->data);
flag=0;                                                                //Setting the initial value of 'flag' be '0' 
while(1)
{
scanf("%d",&dat);
if(dat==0)
break;
k=(struct link*)malloc(sizeof(struct link));          //Allocating memory space for "link" element k->adj=NULL;
if(flag==0)
{
p->adj=k;
l=k;
flag++;
}
else
{
l->adj=k;
l=k;
}
q=start;
while(q!=NULL)
{
if(q->data==dat)
k->next=q;
q=q->next;
}
}
p=p->next;
}
}

void bfs()                        //Function for Breadth First Traversal of Graph 
{
int q[20],i=1,j=0;
p=start;
while(p!=NULL)
{
p->status=0;
p=p->next;
}
p=start;
q[0]=p->data;
p->status=1;
while(1)
{
if(q[j]==0)
break;
p=start;
while(p!=NULL)
{
if(p->data==q[j])
break;
p=p->next;
}
k=p->adj;
while(k!=NULL)
{
q=k->next;
if(q->status==0)
{
q[i]=q->data;
q->status=1;
q[i+1]=0;
i++;
}
k=k->adj;
}
j++;
}
j=0;
printf("Breadth First Search Results\n");
while(q[j]!=0)                                               //For printing the BFS result array 
{
printf("%d ",q[j]);                     
j++;
}
getche();

}//Function for Depth First Search(BFS) Traversal.
void dfs()
{
int stack[20],top=1;
printf("Deapth First Search Results");
p=start;
while(p!=NULL)
{
p->status=0;
p=p->next;
}
p=start;
stack[0]=0;
stack[top]=p->data;
p->status=1;
while(1)
{
if(stack[top]==0)
break;
p=start;
while(p!=NULL)
{
if(p->data==stack[top])
break;
p=p->next;
}
printf("%d ",stack[top]);        //Printing the DFS result 
 top--;
k=p->adj;
while(k!=NULL)
{
q=k->next;
if(q->status==0)
{
top++;
stack[top]=q->data;
q->status=1;
}
k=k->adj;
}
}
}

int main()
{
int ch;
create();                               //Invoking the create function 
while(1)
{
printf("1: DFS\n2: BSF\n0: Exit\nEnter your choice: ");
scanf("%d",&ch);             //User enters his choice 
switch(ch)
{
case 1:
dfs();                                   //For Depth First Traversal 
break;
case 2:
bfs();                                  //For Breadth First Traversal 
break;
case 0:
exit(0);                             //If Zero then exit the program (Omit this line if you don't want that) 
break;
default:
printf("Incorrect choice!");
}
}
return 0;
}                         
