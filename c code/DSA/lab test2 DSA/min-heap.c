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
int findParent(Element a); // returns the index of the element a;
int swap(int *a, int *b);
int swapElements(Element *a, Element *b);
int percolateUp(int i);
int Insert(char *first_name, char *last_name);
int Print();
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
	while(t>0){
		scanf("%s", operation);
		if(strcmp(operation, "InitHeap")==0){
			scanf("%s %s", first_name, last_name);
			getchar();
			InitHeap(first_name, last_name);
			}
		else if(strcmp(operation, "Insert")==0){
			scanf("%s %s", first_name, last_name);
			getchar();
			Insert(first_name, last_name);
			}
		else if(strcmp(operation, "FindMin")==0){
			FindMin();
			}
		else if(strcmp(operation, "Print")==0){
			Print();
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
	n++;
	return;
}
int findParent(Element a){
	return (a.heap_index/2) -1;
}
int swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}
int swapElements(Element *a, Element *b){
	Element temp;
	temp = *a;
	*a = *b;
	*b = temp;
	swap(&a->heap_index, &b->heap_index);
	return;
}
int percolateUp(int i){
	if(arr[i].heap_index>1){
		Element parent;
		parent = arr[findParent(arr[i])];

		char parent_first[100];;
		strcpy(parent_first,parent.first_name);
		char parent_last[100];
		strcpy(parent_last,parent.last_name);
		char child_first[100];
		strcpy(child_first,arr[i].first_name);
		char child_last[100];
		strcpy(child_last,arr[i].last_name);
		int x = strcmp(parent_first, child_first);
		
		if(x<-1){
			return arr[i].heap_index;
		}
		else if(x>0){
			swapElements(&arr[findParent(arr[i])], &arr[i]);
			percolateUp(i/2 -1);
		}

		else if(x==0){
			int y = strcmp(parent_last, child_last);
			if(y<=0){
				return a.heap_index;
			}
			else if(y==1){
				swapElements(&parent, &a);
				percolateUp(i/2 -1);
			}
		}

	}
	else{
		return arr[i].heap_index;
	}

}
int smallerChild(int i){
	if(2*i +2 <n){
		Element left = arr[2*i +1];
		Element right = arr[2*i + 2];
		char left_first[100];
		char left_last[100];
		char right_first[100];
		char right_last[100];
		strcpy(left_first, left.first_name);
		strcpy(left_last, left.last_name);
		strcpy(right_first, right.first_name);
		strcpy(right_last, right.last_name);
		int x = strcmp(left_first, right_first);
		if(x==0){
			int y = strcmp(left_last, right_last);
			if(y<=0){
				return 2*i +1;
			}
			else 
				return 2*i +2;
		}
		else if(x<0){
			return 2*i +1;
		}
		else{
			return 2*i + 2;
		}
	}
	else{
		return 2*i + 1;
	}
}
int percolateDown(int i){
	while(2*i + 2 <n){
		int j = smallerChild(i);
		int t = arr[i].heap_index;
		arr[i] = arr[j];
		arr[i].heap_index = t;
		percolateDown(j);
	}

	return;
}
int Insert(char *first, char *last){
	n++;
	Element temp;
	strcpy(temp.first_name,first);
	strcpy(temp.last_name,last);
	temp.heap_index = n;
	arr[n-1] = temp;
	printf("%d\n", percolateUp(n-1));
	return;
}
int Print(){
	Element temp;
	int i =0;
	for(i=0; i<n; i++){
		printf("%s %s %d\n", arr[i].first_name, arr[i].last_name, arr[i].heap_index);
	}
	return;
}
int FindMin(){
	if(n>0)
		printf("%s %s\n", arr[0].first_name, arr[0].last_name);
	else
		printf("-1\n");//check the output
	return;
}
int DeleteMin(){
	percolateDown(0);
	n--;	
	return;
}
int Delete(int index){
	
	return;
}

	
		
		
		
		
		
		
	