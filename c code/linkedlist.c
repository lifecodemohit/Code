#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	char name[20];
	int age;
	struct node *next;
}*head=NULL;

void create(){
	struct node *temp;
	if(head==NULL){
		temp = (struct node*)malloc(sizeof(struct node));
		head = temp;
//		head->next = temp;
		temp->next= NULL;
	}
}
void insert_end(){
	struct node *temp, *ptr;
	ptr = head;
	while(ptr->next!=NULL){
		ptr = ptr->next;
	}
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter name: ");
	scanf("%s", &temp->name);
	printf("Enter age: ");
	scanf("%d", &temp->age);
	temp->next = NULL;
	ptr->next = temp;
}
void insert_start(){
	struct node *temp, *temp2;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->next = head->next;
	printf("Enter name: ");
	scanf("%s", &temp->name);
	printf("enter age: ");
	scanf("%d", &temp->age);
	temp2 = head;
	temp2->next = temp;
}
void display(){
	struct node *ptr;
	ptr = head->next;
	printf("Name	Age\n");
	while(ptr!=NULL){
		printf("%s	%d\n", ptr->name, ptr->age);
		ptr=ptr->next;
	}
}
//h 1 2 3 4 5 6
void delete(){
	struct node *ptr, *temp;
	char xyz[20];
	int count = 0;
	printf("Enter the name of the person you want to delete: ");
	scanf("%s", &xyz);
	ptr = head->next;
	temp = head;
	while(ptr->next != NULL){
		if(strcmp(ptr->name,xyz)==0){
			temp->next = ptr->next;
			
			break;
		}
		temp= ptr;
		ptr = ptr->next;
		count++;
		printf("\n%d\n\n", count);
	}

}
int main()
{
    int choice;
    create();
    while(1)
    {
        printf("1. Create\n2. Display\n3. Insert at end\n4. Exit\n5. insert start\n6. Delete\n");
        scanf("%d", &choice);
        if(choice==1){
            insert_end();
			display();
		}
        else if(choice == 2)
            display();
        else if(choice == 3){
            insert_end();
			display();
        }
		else if(choice == 4)
            exit(0);
        else if(choice==5){
            insert_start();
			display();
			}
        else if(choice==6)
            {
			delete();
			display();
			}
        else
            exit(0);
    }
    return 0;
}
