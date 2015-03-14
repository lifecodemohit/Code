#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct BST{
	char name[100];
	struct BST *left;
	struct BST *right;
}bst;
bst *getNode(char *naam);
bst *InitTree(char *name);
int Insert(char *name, bst *T);
int count(bst *root);
int pos(char *naam, bst *t);
int Find(char *name, bst *T);
bst* FindMin(bst* t);
bst *Delete(char *name, bst *T);
int Height(bst *T);
int inorder(bst *t);
int preorder(bst *t);
int postorder(bst *t);
int PrintTree(bst *T, int order);
int main(){
	int t; //number of operations to be performed
	scanf("%d", &t);
	char name[100];
	char operation[20];
	bst *root;
	root = NULL;
	int index;
	while(t>0){
		scanf("%s", operation);
		if(strcmp(operation, "InitTree")==0){
			scanf("%s", name);
			root = InitTree(name);
			}
		else if(strcmp(operation, "Insert")==0){
			scanf("%s", name);
			if(root==NULL){
				root=InitTree(name);
			}
			else{
				Insert(name, root);
				printf("%d\n", pos(name, root));
			}
		}
		else if(strcmp(operation, "Delete")==0){
			scanf("%s", name);
			if(Find(name, root)==1){
				root = Delete(name, root);
			}
		}
		else if(strcmp(operation, "Find")==0){
			scanf("%s", name);
			if(Find(name, root)==1){
				printf("%d\n", pos(name, root));
				}
			}

		else if(strcmp(operation, "Height")==0){
			printf("%d\n", Height(root));
			}
		else if(strcmp(operation, "PrintTree")==0){
			scanf("%d", &index);
			PrintTree(root,index);
			printf("\n");
			}
		t--;

	}
}

bst* getNode(char *naam){
	bst *temp;
	temp = (bst*)malloc(sizeof(bst));
	(temp)->left = NULL;
	(temp)->right = NULL;
	strcpy((temp)->name,naam);
	return temp;
}
bst* InitTree(char *name){
	bst *temp;
	temp = getNode(name);
	return temp;
}
int Insert(char *naam, bst *t){
	if((strcmp(naam,t->name)<0) && t->left != NULL){
		Insert(naam, t->left);
	}
	else if((strcmp(naam,t->name)<0) && t->left == NULL){
		t->left = getNode(naam);
		return;
	}
	else if((strcmp(naam,t->name)>=0) && t->right !=NULL){
		Insert(naam, t->right);
	}
	else if((strcmp(naam,t->name)>=0) && t->right ==NULL){
		t->right = getNode(naam);
		return;
	}
	else
		return;	

}

int count(bst *root) {
	if(root!=NULL)
		return count(root->left)+count(root->right)+1;
	else
		return 0;
}
int pos(char *naam,bst *t){
	if(strcmp(naam,t->name)<0)
		return pos(naam, t->left);
	else if(strcmp(naam,t->name)>0)
		return count(t->left)+1+pos(naam, t->right);
	else
		return count(t->left)+1;
}




int Find(char *naam, bst *t){
	if(t==NULL){
		printf("Not Found\n");
		return 0;
	}
	else{
		if(strcmp(naam,t->name)==0){
			return 1;
		}
		else if(strcmp(naam,t->name)<0 && t->left!=NULL){
			Find(naam, t->left);
		}
		else if(strcmp(naam,t->name)<0 && t->left ==NULL){
			printf("Not Found\n");
			return 0;
		}
		else if(strcmp(naam,t->name)>0 && t->right !=NULL)
			Find(naam, t->right);
		else if(strcmp(naam,t->name)>0 && t->right == NULL){
			printf("Not Found\n");
			return 0;
		}
	}
}
bst* FindMin(bst* t)
{
    bst* ptr = t;
    while (ptr->left != NULL)
        ptr = ptr->left;
    return ptr;
}

bst *Delete(char *naam, bst *t){
	if(t==NULL){
		printf("Not Found\n");
		return t;
	}
	if(strcmp(naam, t->name)<0)
		t->left = Delete(naam,t->left);
	else if(strcmp(naam, t->name)>0)
		t->right = Delete(naam,t->right);

	else{
        if(t->left==NULL && t->right==NULL)
        {
            free(t);
            t= NULL;
        }
        else if(t->left == NULL)
        {
            bst *temp = t;
            t=t->right;
            free(temp);
        }
        else if(t->right == NULL)
        {
            bst *temp = t;
            t=t->left;
            free(temp);
        }
        else
        {
            bst *temp = FindMin(t->right);
            strcpy(t->name,temp->name);
            t->right = Delete(temp->name,t->right);
        }
	}
	return t;
}
int Height(bst* t)
{
	if (t==NULL)
		return 0;
	else{
		int lh = Height(t->left);
		int rh = Height(t->right);
		if (lh > rh)
			return(lh+1);
		else 
			return(rh+1);
	}
}
 int inorder(bst *t){
	if(t!=NULL){
		inorder(t->left);
		printf("%s ", t->name);
		inorder(t->right);
	}
	else{
		return 0;
	}
}
int preorder(bst *t){
	if(t!=NULL){
		printf("%s ", t->name);
		preorder(t->left);
		preorder(t->right);
	}
	else{
		return 0;
	}
}
int postorder(bst *t){
	if(t!=NULL){
		postorder(t->left);
		postorder(t->right);
		printf("%s ", t->name);
	}
	else{
		return 0;
	}
}

int PrintTree(bst *t, int order){
	if (order==0){
		inorder(t);
	}
	else if(order==-1){
		preorder(t);
	}
	else{
		postorder(t);
	}
	return;
}

