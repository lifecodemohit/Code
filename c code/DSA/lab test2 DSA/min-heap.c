#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct _Element{
	char first_name[100];
	char last_name[100];
	int heap_index;
} Element;
Element arr[1000000]; //declared an array of size required
int n = 0; //number of elements in the array added
int InitHeap(char *first_name, char *last_name);
int Insert(char *first_name, char *last_name);
int FindMin();
int DeleteMin();
int Delete(int index);
int main(){
	int t;//number of heap operations required
	char operation[20];//array for the name of the operation
	char first_name[100];//array for the first name 
	char last_name[100];//array for the last name
	int index;//index number for delete operation
	scanf("%d ", &t);
	while(t>=0){
		scanf("&s", operation);
		if(strcmp(operation, "InitHeap")==0){
			scanf("%s %s ", first_name, last_name);
			InitHeap(first_name, last_name);
			}
		else if(strcmp(operation, "Insert")==0){
			scanf("%s %s ", first_name, last_name);
			Insert(first_name, last_name);
			}
		else if(strcmp(operation, "FindMin")==0){
			FindMin();
			}
		else if(strcmp(operation, "DeleteMin")==0){
			DeleteMin();
			}
		else if(strcmp(operation, "Delete")==0){
			scanf("%d ", &index);
			Delete(index);
			}
		t--;
	}
	return 0;
}


int InitHeap(char *first, char *last){
	Element temp;
	strcpy(temp.first_name,first);
	strcpy(temp.last_name,last);
	temp.heap_index = 1;
	arr[0] = temp;
	printf("%s %s %s ", arr[0].first_name, arr[0].last_name, arr[0].heap_index);
	return;
}
int Insert(char *first_name, char *last_name){
	return;
}
int FindMin(){
	return;
}
int DeleteMin(){
	return;
}
int Delete(int index){
	return;
}

	
		
		
		
		
		
		
	