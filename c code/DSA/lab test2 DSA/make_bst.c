#include <stdio.h>
#include <stdlib.h>
 
typedef struct node
{
    int data;
    node *left;
    node *right;
};
 
node *getNode (int data)
{
     node* temp = ( node *) malloc( sizeof( node) );
 
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

node *conTreeUtil (int pre[], int post[], int *preIndex, int l, int h, int size)
{
    if (*preIndex >= size || l > h)
        return NULL;
     node* root = getNode ( pre[*preIndex] );
    (*preIndex)++;
 
    if (l == h)
        return root;
 
    int i;
    for (i = l; i <= h; ++i)
        if (pre[*preIndex] == post[i])
            break;
 
    if (i <= h)
    {
        root->left = conTreeUtil (pre, post, preIndex, l, i, size);
        root->right = conTreeUtil (pre, post, preIndex, i + 1, h, size);
    }
 
    return root;
}
 
node *conTree (int pre[], int post[], int size)
{
    int preIndex = 0;
    return conTreeUtil (pre, post, &preIndex, 0, size - 1, size);
}
 
void printGivenLevel( node* root, int level)
{
  if(root == NULL)
    return;
  if(level == 1)
    printf("%d ", root->data);
  else if (level > 1)
  {
    printGivenLevel(root->left, level-1);
    printGivenLevel(root->right, level-1);
  }
}
int height( node* node)
{
   if (node==NULL)
       return 0;
   else
   {
     int lheight = height(node->left);
     int rheight = height(node->right);
     if (lheight > rheight)
         return(lheight+1);
     else 
        return(rheight+1);
   }
} 
void printLevelOrder( node* root)
{
  int h = height(root);
  int i;
  for(i=1; i<=h; i++)
    printGivenLevel(root, i);
} 

int main (){   
    int t,i=0;
    scanf("%d", &t);
    int pre[t],post[t];
    for(i=0; i<t; i++)
        scanf("%d", &pre[i]);
    for(i=0; i<t; i++)
        scanf("%d", &post[i]);
    int size = sizeof( pre ) / sizeof( pre[0] ); 
     node *root = conTree(pre, post, size);
    printLevelOrder(root);
    printf("\n");
    return 0;
}
