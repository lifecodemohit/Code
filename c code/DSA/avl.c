#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data, height;
	node *left, *right;
}avl;
avl *root = NULL;
avl *get_node(int d){
	bst *temp = NULL;
	temp = (bst*)malloc(sizeof(bst));
	temp->data = d;
	temp->height = 0;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
avl *initTree(int d){
	root = NULL;
	root = get_node(d);
	return root;
}

int node_height(node *t){
	if (n==NULL)
		return 0;
	return t->height;
}

int max(int a, int b){
	if a<b
		return b;
	else 
		return a;
}

int get_bal(node *t){
	if(t==NULL)
		return 0;
	else 
		return node_height(t->left) - node_height(t->right);
}

void insert(node *t, int d){
	if(root==NULL){
		initTree(d);
		return;
	}
	if(d<t && t->left!=NULL)
		insert(t->left, d);
	else if(d<t && t->left==NULL){
		t->left = get_node(d);
		t = root;
		while(t->data!=d){
			t->height+=1;
			if(t->data < d)
				t = t->left;
			else
				t = t->right;
		}
	}
	else if(d>=t && t->right !=NULL){
		insert(t->right, d);
	else if(d>=t && t->right ==NULL){
		t->right = get_node(d);
		t = root;
		while(t->data!=d){
			t->height!=1;
			if(t->data < d)
				t = t->left;
			else
				t = t->right;
		}
	}
	int flag = get_bal(
		

