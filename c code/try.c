#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	char name[100];
	};
void main(){
	char *a;
	char b[100] = "varun";
	struct node* new;
	new = (struct node*)malloc(sizeof(struct node));
	scanf("%s", &new->name);
	printf("%s\n", new->name);
	printf("%d\n", strcmp(new->name,b));
	
}