#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

int height(struct node *N)
{
    if(N==NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}


struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *z = x->right;

    x->right = y;
    y->left = z;

    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    return x;
}

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *z = y->left;

    y->left = x;
    x->right = z;
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    return y;
}

int getBalance(struct node *N)
{
    if(N==NULL)
        return 0;
    return height(N->left) - height(N->right);
}


struct node* insert(struct node* node, int key)
{
    if (node == NULL)
    {
        struct node* node = (struct node*)malloc(sizeof(struct node));
        node->key = key;
        node->left=NULL;
        node->right=NULL;
        node->height=1;
        return(node);
    }
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    node->height = max(height(node->left), height(node->right)) + 1;

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
void print(struct node *root)
{
    if(root != NULL)
    {
        print(root->left);
        printf("%d ", root->key);
        print(root->right);
    }

}

int main()
{
    int choice;
    int key;
    struct node *root=NULL;
    while(1)
    {
        printf("\n1. Insert \n2. Print\n3. exit\nchoice>>");
        scanf("%d", &choice);
        if(choice==1)
        {
            printf("Enter a value to add to the tree: ");
            scanf("%d", &key);
            root = insert(root, key);
        }
        else if(choice==2)
            print(root);
        else if(choice ==3)
            exit(0);
        else
            printf("Invalid Entry, try again\n");
    }

    return 0;
}




















