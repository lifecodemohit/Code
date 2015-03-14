#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int pos=1,flag=0;
struct btnode
{
    char data[100];
    struct btnode* left;
    struct btnode* right;
    struct btnode* parent;
};
struct btnode* create(char* x)
{
    struct btnode* temp1;
    temp1 = (struct btnode*)malloc(sizeof(struct btnode));
    strcpy(temp1->data,x);
    temp1->right = NULL;
    temp1->left = NULL;
    temp1->parent = NULL;
    return temp1;
}
struct btnode* insert(struct btnode* root,char* str)
{
    if(root == NULL)
    {
        root = create(str);
    }
    else if (strcmp(root->data,str)>0)
    {
        root->left = insert(root->left,str);
    }
    else
    {
        root->right = insert(root->right,str);
    }
    return root;
}
void Inorderindex(struct btnode* c,char* u)
{
    if(c== NULL)
    {
        return;
    }


    Inorderindex(c->left,u);
    if(strcmp(c->data,u)==0)
    {
        if(flag==0)
        {
            printf("%d\n",pos);
            flag++;
        }
    }
    pos++;
    Inorderindex(c->right,u);
}
void Inorder(struct btnode* c)
{
    if(c== NULL)
    {
        return;
    }
    Inorder(c->left);
    printf("%s ",c->data);
    Inorder(c->right);
}
void Preorder(struct btnode* c)
{
    if(c == NULL)
    {
        return;
    }
    printf("%s ",c->data);
    Preorder(c->left);
    Preorder(c->right);
}
void Postorder(struct btnode* c)
{
    if(c == NULL)
    {
        return;
    }
    Postorder(c->left);
    Postorder(c->right);
    printf("%s ",c->data);
}
int height(struct btnode* c)
{
   if (c==NULL)
       return 0;
   else
   {
     int ldepth = height(c->left);
     int rdepth = height(c->right);
     if (ldepth > rdepth)
         return(ldepth+1);
     else return(rdepth+1);
   }
}
struct btnode* FindMin(struct btnode* c)
{
    struct btnode* pointer = c;
    while (pointer->left != NULL)
        pointer = pointer->left;

    return pointer;
}
struct btnode* deleteNode(struct btnode* root,char* data)
{
    if(root==NULL)
    {
        printf("Not Found\n");
    }
    else if(strcmp(data,root->data)<0)
        root->left=deleteNode(root->left,data);
    else if(strcmp(data,root->data)>0)
        root->right=deleteNode(root->right,data);
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            root= NULL;
        }
        else if(root->left == NULL)
        {
            struct btnode *temp = root;
            root=root->right;
            free(temp);
        }
        else if(root->right == NULL)
        {
            struct btnode *temp = root;
            root=root->left;
            free(temp);
        }
        else
        {
            struct btnode *temp = FindMin(root->right);
            strcpy(root->data,temp->data);
            root->right = deleteNode(root->right,temp->data);
        }
    }
    return root;
}
void Find(struct btnode* root,char* data)
{
        Inorderindex(root,data);
}


void main()
{
    struct btnode* root,*temp;
    root = NULL;
    char option[100];
    char str[100];
    char deletestring[100];
    char findstring[100];
    int i=0,number=0,n;
    scanf("%d",&n);
    while(n!=0)
    {
        scanf("%s",option);
        if(strcmp(option,"InitTree")==0)
        {
            scanf("%s",str);
            root = insert(root,str);
        }
        else if(strcmp(option,"Insert")==0)
        {
            pos=1;
            scanf("%s",str);
            temp = insert(root,str);
            flag=0;
            Inorderindex(root,str);
        }
        else if(strcmp(option,"PrintTree")==0)
        {
            scanf("%d",&i);
            if(i==-1)
            {
                Preorder(root);
                printf("\n");
            }
            else if(i==0)
            {
                Inorder(root);
                printf("\n");
            }
            else if(i==1)
            {
                Postorder(root);
                printf("\n");
            }
        }
        else if(strcmp(option,"Height")==0)
        {
            number = height(root);
            printf("%d\n",number);
        }
        else if(strcmp(option,"Delete")==0)
        {
            pos=1;
            scanf("%s",deletestring);
            Find(root,deletestring);
            flag=0;
            root = deleteNode(root,deletestring);
        }
        else if(strcmp(option,"Find")==0)
        {
            scanf("%s",findstring);
            pos = 1;
            Find(root,findstring);
            if(flag==0)
                printf("Not Found\n");
            flag=0;
        }
        n=n-1;
    }
}
