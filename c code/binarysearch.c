#include<stdio.h>
#include<stdlib.h>
 
struct bin_tree {
int data;
struct bin_tree * right, * left;
};
typedef struct bin_tree node;
   
void insert(node ** tree, int val)
{
    node *temp = NULL;
    if(*tree==NULL)
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

node* depth(node ** tree, int val, int count)
{
    
    
    if(val == (*tree)->data)
    
    {
        printf("%d",count) ;
    }
    else if(val > (*tree)->data)
    {
        count+=1;
        depth(&((*tree)->right), val, count);
    }
    else if(val < (*tree)->data) 
    {
        count+=1;
        depth(&((*tree)->left), val, count);
    }
}


void print_inorder(node * tree)
{
    
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d ",tree->data);
        print_inorder(tree->right);
        
    }
}

void print_postorder(node * tree)
{
    if (tree)
    {
        
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d ",tree->data);
        
    }
}
void print_preorder(node * tree)
{
    
    if (tree)
    {
        printf("%d ",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
        
        
    }
}
int nullcount(node *tree)
{
    int c = 0;
    if(tree) 
    {
        c += nullcount(tree->left) + nullcount(tree->right);
    }
    else 
    {
        return 1;
    }
    return c;
    
}

int main()
{
    int choice;
    int val;
    node *root;
    
    int count;
    //int i;

    root = NULL;
    
    while(1)
    {    
        printf("1. Insert 2. print 3. #null pointers 4. Exit 5.depth\n");
        scanf("%d", &choice);
        if(choice==1)
        {
            printf("Enter a value to add in tree: ");
            scanf("%d", &val);
            insert(&root, val);
        }
        else if(choice == 2)
        {
            printf("Indorder: ");
            print_inorder(root);
            printf("\n");
            printf("Postorder: ");
            print_postorder(root);
            printf("\n");
            printf("Preorder: ");
            print_preorder(root);
            printf("\n");
            
        }
        else if(choice == 3)
        {
            printf("Nullcounts: %d\n",nullcount(root));
         }   
        else if(choice == 4)    
            exit(0);
        else if(choice == 5)
        {
            printf("Enter the int to find depth\n");
            scanf("%d", &val);
            depth(&root, val, 0);
            
            printf("\n");
        }
        else
            printf("invalid entry\n");
    }
    return ;
}

