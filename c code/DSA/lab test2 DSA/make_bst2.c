#include <stdio.h>
#include <stdlib.h>
 
typedef struct _node
{
    int data;
    struct _node *left;
    struct _node *right;
}bst;
 
bst *getNode (int data)
{
    bst* temp = (bst*) malloc(sizeof(bst));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

bst *make (int a[], int b[], int *p, int l, int h, int size)
{
    int i;
    if (*p >= size || l > h)
        return NULL;
     bst *root = getNode(a[*p]);
    (*p)++;
 
    if (l == h)
        return root;
 
    for (i = l; i <= h; ++i)
        if (a[*p] == b[i])
            break;
 
    if (i <= h){
        root->left = make (a, b, p, l, i, size);
        root->right = make (a, b, p, i + 1, h, size);
    }
    return root;
}
 
bst *makeTree (int pre[], int post[], int size)
{
    int preIndex = 0;
    return make (pre, post, &preIndex, 0, size - 1, size);
}
 
int nodesAtLevel(bst* t, int i)
{
  if(t == NULL)
    return;
  if(i == 1)
    printf("%d ", t->data);
  else if (i > 1)
  {
    nodesAtLevel(t->left, i-1);
    nodesAtLevel(t->right, i-1);
  }
  return;
}
int height(bst* t)
{
   if(t!=NULL){
     int lheight = height(t->left);
     int rheight = height(t->right);
     if (lheight > rheight)
         return(lheight+1);
     else 
        return(rheight+1);
   }
   else{
    return 0;
   }
} 
int lvlBylvl(bst* root)
{
  int h = height(root);
  int i;
  for(i=1; i<=h; i++)
    nodesAtLevel(root, i);
  return;
} 

int main (){   
    int t,i=0;
    scanf("%d", &t);
    int pre[t],post[t];
    for(i=0; i<t; i++)
        scanf("%d", &pre[i]);
    for(i=0; i<t; i++)
        scanf("%d", &post[i]);
    bst *root = makeTree(pre, post, t);
    lvlBylvl(root);
    printf("\n");
    return 0;
}
