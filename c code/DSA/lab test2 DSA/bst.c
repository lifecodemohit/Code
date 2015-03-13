#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct _BST{
	char name[100];
	_BST *left;
	_BST *right;
}bst;
bst InitTree(char *name);
bst Insert(char *name, bst **T);
int Delete(char *name, bst **T);
int Find(char *name, bst *T);
int Height(bst *T);
int PrintTree(BST *T, int order);
int main(){
	int t; //number of operations to be performed
	scanf("%d", &t);
	char name[100];
	char operation[20];
	bst *root;
	root = NULL;
	while(t>0){
		scanf("%s", operation);
		if(strcmp(operation, "InitTree")==0){
			scanf("%s", name);
			root= InitTree(name);
			}
		else if(strcmp(operation, "Insert")==0){
			scanf("%s %s", first_name, last_name);
			Insert(first_name, last_name);
			}
		else if(strcmp(operation, "FindMin")==0){
			FindMin();
			}
		else if(strcmp(operation, "Print")==0){
			Print();
			}
		else if(strcmp(operation, "DeleteMin")==0){
			DeleteMin();
			}
		else if(strcmp(operation, "Delete")==0){
			scanf("%d", &index);
			Delete(index);
			}
		t--;

	}
}