#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{
    int nam;
    int roll;
    struct student* next;
}*stu;
void create(){
    struct student *temp;
    if(stu==NULL){
        temp = (struct student *)malloc(sizeof(struct student));
        stu = temp;
        printf("Enter the name of the person: ");
        scanf("%d", &temp->nam);
        printf("Enter the roll number: ");
        scanf("%d", &temp->roll);
        temp->next = NULL;
    }
    else{
        printf("Linked list is already created: ");
        printf("\n");
    }
}
void insert(){
    struct student *temp, *ptr;
    ptr = stu;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    temp = (struct student *)malloc(sizeof(struct student));
    printf("Enter the name of the person: ");
    scanf("%d", &temp->nam);
    printf("Enter the roll number: ");
    scanf("%d", &temp->roll);
    temp->next = NULL;
    ptr->next = temp;
}

void display(){
    struct student *ptr;
    ptr = stu;
    printf("Name\tRoll Number\n");
    while(ptr!=NULL){
        printf("%d\t%d\n", ptr->nam, ptr->roll);
        ptr=ptr->next;
    }
    printf("\n\n");
}
    
void delete(){
    struct student *ptr, *ptr2;
    display();
    int d;
    printf("enter the roll number: ");
    scanf("%d", &d);
    ptr = stu;
    ptr2 = stu;
    while((ptr->roll!=d)||(ptr->next!=NULL )){
        ptr2 = ptr;
        ptr=ptr->next;
        
    }
    if(ptr->next==NULL){
        printf("Do not exist in the linked list.\n");
    }
    else{
        
        if(ptr->next!=NULL){
            ptr = ptr->next;
            ptr2->next = ptr;        
        }
        else{
            ptr2->next = NULL;
        }
    }
}
int main(){
    while(1){
    printf("1. create\n 2. insert\n3. delete\n4. display\n5.exit\n enter your choice: ");
    int c;
    scanf("%d", &c);
        switch (c){
            case 1:
                create();
                break;
            case 2:
                insert();
                break;
            case 3:
                delete();
                break;
            case 4: 
                display();
                break;
            case 5:
                return;
                break;
        }
    }
    return 0;
} 
