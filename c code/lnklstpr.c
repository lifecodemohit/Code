#include<stdlib.h>
#include<stdio.h>

struct node
{
    int info;
    struct node *link;//address will be of type node
}*start;
// start is a variable (null pointer)


void create()
{
    int data;
    printf("enter data: ");
    scanf("%d", &data);
    struct node *tempnode;
    if(start==NULL)
    {
        tempnode = (struct node *)malloc(sizeof(struct node));
        start = tempnode;
        tempnode->info = data;
        tempnode->link = NULL;
    }
}
void insert_end()
{
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    struct node *tempnode, *ptr;
    ptr = start;
    while(ptr->link!=NULL)
    {
        ptr = ptr->link;
    }
    tempnode = (struct node *)malloc(sizeof(struct node));
    tempnode->info = data;
    tempnode->link = NULL;
    ptr->link = tempnode;
}

void insert_start()
{
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    struct node *tempnode, *tempnode2;
    tempnode = (struct node *)malloc(sizeof(struct node));
    tempnode2 = (struct node *)malloc(sizeof(struct node));
    tempnode->info = start->info;
    tempnode->link = start->link;
    start->info = data;
    start->link = tempnode;    
}


void display()
{
    struct node *ptr;
    ptr = start;
    if(start==NULL)
        printf("The list is Empty\n");
    else
    {

        while(ptr!=NULL)
        {
            printf("%d ", ptr->info);
            ptr = ptr->link;
        }
        printf("The end of list\n");
    }
}

void delete1()
{
    display();
    int d;
    struct node *ptr, *temp, *temp2;
    ptr = start;
    printf("%d\n", ptr->info);
    printf("Enter the number you want to delete: ");
    scanf("%d", &d);
    if(ptr->info==d)
    {
        temp = ptr->link;
        start = temp;
        ptr = NULL;
    }

    while(ptr!=NULL)
    {
        if(ptr->info==d)
        {

            temp->link = temp2;
            ptr=NULL;

        }
        else
        {
                temp = ptr;
                ptr = ptr->link;
                temp2 = ptr->link;
        }
    }

    display();

}
int main()
{
    int choice;
    
    while(1)
    {
        printf("1. Create\n2. Display\n3. Insert at end\n4. Exit\n5. insert start\n6. Delete\n");
        scanf("%d", &choice);
        if(choice==1)
            create();
        else if(choice == 2)
            display();
        else if(choice == 3)
            insert_end();
        else if(choice == 4)
            exit(0);
        else if(choice==5)
            insert_start();
        else if(choice==6)
            delete1();
        else
            exit(0);
    }
    return 0;
}

