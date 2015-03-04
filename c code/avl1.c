#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node * left;
    struct node * right;
    int height;
};

int height(struct node *N)
{
    if(N==NULL)
        return 0;
    return n->height;
}

int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

struct node *RightRotate(struct node *y)
{
    struct node*x = y->left;
    struct node*y = z->right;
    
    x->right = y;
    y->left = z;
    y->height= max(height(y->left), height(y->right))+1;
    x->height= max(height(x->left), height(x->right))+1;
    
    return x;
}

struct node* LeftRotate(struct node*x)
{
    struct node *y = x->right;
    struct node *z = y->left;
    
    y->left = x;
    x->right = z;
    x->height = max(height(x->left), height(x->right))+1;
    x->height = max(height(y->left), height(y->right))+1;
    
    return y;
}

int getBalance(struct node*N)
{
    if(N==NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct node* insert(struct node* node, int key)
{
    if(node ==NULL)
    {
        struct node* node = (struct node*)malloc(sizeof(struct node));
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        node->height = 1;
        return(node);
    }
    if(ey< node->key)
        node->left = insert(node->left, key);
    else
        node
