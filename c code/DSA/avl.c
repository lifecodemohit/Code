#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data, height;
	node *left, *right, *parent;
}bst;
bst *root = NULL;
bst get_node(int data){
	bst *temp = NULL;
	temp = (*bst)malloc(sizeof(*bst));
	
}