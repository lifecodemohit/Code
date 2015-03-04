#include<stdio.h>
#include<stdlib.h>
struct node{
	int num;
};
struct tree{
	int size;
	struct node data;
	struct tree* lchild;
	struct tree* rchild;
};
int main(){
	struct tree *pq;
	pq.size = 4;
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->num = 10;
	pq->data = temp;
	pq->lchild = NULL;
	pq->rchild = NULL;
	struct tree l;
	l = pq;
	temp = l->data;
	printf("%d", l.data);
	return 0;
}