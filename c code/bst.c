#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	char abc;
	struct node *left, *right;
}BST;
BST *root = NULL;
int leaves = 0;
char Lflag;
char Rflag;
BST *get_node(char c){
	BST *temp;
	temp = (BST *)malloc(sizeof(BST));
	temp->abc = c;
	temp->left = NULL;
	temp->right = NULL;
	leaves+=1;
	return temp;
}

BST *initTree(char a){
	root = NULL;
	root = get_node(a);
	leaves = 1;
	return root;
}

void insert(char a, BST *t){
	if(root==NULL){
		initTree(a);
		return;
	}
	if(a < t->abc && t->left != NULL){
		insert(a, t->left);
	}
	else if(a < t->abc && t->left ==NULL){
		t->left = get_node(a);
		return;
	}
	else if(a >= t->abc && t->right !=NULL){
		insert(a, t->right);
	}
	else if(a >= t->abc && t->right==NULL){
		t->right = get_node(a);
		return;
	}
	else
		return;
}
void inorder(BST *t){
	if(t!=NULL){
		inorder(t->left);
		printf("%c ", t->abc);
		inorder(t->right);
	}
}
int inorder_pos(BST *t, char a[]){
/*
	if(t!=NULL && (strcmp(a, t->abc)!=0)){
		inorder(t->left);
		i++;
		inorder(t->right);
	}
	else

		return i;
*/
	return 1;
}
void preorder(BST *t){
	if(t!=NULL){
		printf("%c ", t->abc);
		preorder(t->left);
		preorder(t->right);
	}
}
void postorder(BST *t){
	if(t!=NULL){
		postorder(t->left);
		postorder(t->right);
		printf("%c ", t->abc);
	}
}
int print(BST *T, int order){
	if (order==0){
		inorder(T);
	}
	else if(order==-1){
		preorder(T);
	}
	else{
		postorder(T);
	}
	return;
}	
int find(char a, BST *t){
	if(t==NULL){
		printf("Empty tree\n");
		return;
	}
	if(a==t->abc){
		printf("Yes it is\n");
		Rflag = (t->right)->abc;
		Lflag = (t->left)->abc;
		return 1;
	}
	if(a < t->abc && t->left!=NULL){
		find(a, t->left);
	}
	else if(a < t->abc && t->left ==NULL)
		printf("not present\n");
		
	else if(a > t->abc && t->right !=NULL)
		find(a, t->right);
	else if(a > t->abc && t->right == NULL){
		printf("Not present\n");
		return 0;
	}
	return 0;
}
void countleaves(BST *t){
	if(t==NULL){
		printf("%d \n", leaves);
		leaves = 0;
	}
	else if(t!=NULL){
		if(t->left==NULL && t->right==NULL){
			leaves+=1;
		}
		countleaves(t->left);
		countleaves(t->right);
	}
}

int findSucc(char a){
	if(find(a, root)==1){
		printf("%d\n", Rflag);
		return;
	}
	return;
}
int findPre(char a){
	if(find(a, root)==1){
		printf("%d\n", Lflag);
		return;
	}
	return;
}
int Hleft(BST *t){
	int h=0;
	if(t==NULL){
		return 0;
	}
	while(t->left!=NULL){
		t = t->left;
		h++;
	}
	return h;
}
int Hright(BST *t){
	int h=0;
	if(t==NULL){
		return 0;
	}
	while(t->right!=NULL){
		t = t->right;
		h++;
	}
	return h;
}
int maximum(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}
int height(BST *t){
	int h = maximum(Hleft(t), Hright(t));
	return h+1;
}
int main(){
	int q,h=0;
	char a;
	int ord;
	while(1){
		printf("1.InitTree\t2.Insert\t3.print\t4.Find\t5.FindSuccesor\t6.FindPre\t7.count\t8.height\t9.exit\n");
		scanf("%d", &q);
		switch(q){
			case 1:
				printf("Enter the character: ");
				scanf(" %c", &a);
				initTree(a);
				break;
			case 2:
				printf("Enter the character: ");
				scanf(" %c", &a);
				insert(a, root);
				break;
			case 3:
				printf("Enter the order: ");
				scanf("%d", &ord);
				print(root, ord);
				printf("\n");
				break;
			case 4:
				printf("Enter the character: ");
				scanf(" %c", &a);
				find(a, root);
				break;
			case 5:
				printf("Enter the character: ");
				scanf(" %c", &a);
				findSucc(a);
				break;
			case 6: 
				printf("Enter the character: ");
				scanf(" %c", &a);
				findPre(a);
				break;
			case 7:
				countleaves(root);
				break;
			case 8:
				h = height(root);
				printf("%d\n", h);
				break;
			case 9:
				h = height(root);
				exit(0);
				break;
		}
	}
	return;
}
				