#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int age;
    char name[20];
    struct node* next;
}*head;

void create()
{
    char name[20];
    int age;
    struct node *ptr, *temp;
    ptr = head;
    printf("Enter name: ");
    scanf("%s", &name);
    printf("Enter age: ");
    scanf("%d", &age);

    if(head==NULL)
    {
        temp= (struct node*)malloc(sizeof(struct node));

        head = temp;
        temp->age = age;
        strcpy(temp->name, name);
        temp->next = NULL;
    }
}

void insert_end()
{
    char name[20];
    int age;
    struct node *ptr, *temp;
    ptr = head;
    printf("Enter name: ");
    scanf("%s", &name);
    printf("Enter age: ");
    scanf("%d", &age);


    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
        temp= (struct node*)malloc(sizeof(struct node));
        temp->age = age;
        strcpy(temp->name, name);
        temp->next = NULL;
        ptr->next = temp;

}


void display()
{
    struct node *ptr;
    ptr = head;
    if(head==NULL)
        printf("The list is empty");
    else
    {
        while(ptr!=NULL)
        {
            printf("%s ", ptr->name);
            printf("%d\n", ptr->age);
            ptr = ptr->next;
        }
        printf("The end\n");
    }
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
            exit(0);
        //else if(choice==6)
           // delete1();
        else
            exit(0);
    }
    return 0;
}
