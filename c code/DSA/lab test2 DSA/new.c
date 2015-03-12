#include<stdio.h>
#include<string.h>
typedef struct node
{
	char first[100];
}ele;
void main(){
	ele a;
	ele b;
	strcpy(a.first,"bansal");
	strcpy(b.first,"bansal");
	printf("%d\n",strcmp(a.first, b.first));
}