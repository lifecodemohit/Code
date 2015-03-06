#include<stdio.h>
#include<stdlib.h>
typedef struct node{
		int data;
		node *left, *right;
}avl;
avl *root =NULL;
avl *getnode(int x){
	avl *temp;
	temp=(avl*)malloc(sizeof(avl));
	temp->data = x;
	temp->left = NULL;
	temp->right=NULL;
	return temp;
}
avl *initTree(int x){
	root = NULL;
	root = getnode(x);
	return root;
}
