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
Element percolateUp(int i);
int smallerChild(int i);
int percolateDown(int i);
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
	scanf("%d", &t);
	while(t>0){
		scanf("%s", operation);
		if(strcmp(operation, "InitHeap")==0){
			scanf("%s %s", first_name, last_name);
			InitHeap(first_name, last_name);
			}
		else if(strcmp(operation, "Insert")==0){
			scanf("%s %s", first_name, last_name);
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
			scanf("%d", &index);
			Delete(index-1);
			}
		t--;
	}
	return 0;
}

int InitHeap(char *first, char *last){
	n = 0;
	Element temp;
	strcpy(temp.first_name,first);
	strcpy(temp.last_name,last);
	temp.heap_index = 1;
	arr[0] = temp;
	n++;
	return;
}
int findParent(Element a){
	return (a.heap_index/2) -1;//returns the index of the parent of ele a
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
Element percolateUp(int i){
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
		
		if(x<0){
			return arr[i];
		}
		else if(x>0){
			swapElements(&arr[findParent(arr[i])], &arr[i]);
			percolateUp((i-1)/2 );
		}

		else if(x==0){
			int y = strcmp(parent_last, child_last);
			if(y<=0){
				return arr[i];
			}
			else if(y>0){
				swapElements(&arr[findParent(arr[i])], &arr[i]);
				percolateUp((i-1)/2 );
			}
		}

	}
	else{
		return arr[i];
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
	else if(n<= (2*i) + 2){
		return 2*i + 1;
	}
}
int percolateDown(int i){
	if(2*i + 1 <= n){
		int j = smallerChild(i);
		int x = strcmp(arr[i].first_name, arr[j].first_name);
		if(x>0){
			swapElements(&arr[i], &arr[j]);
			percolateDown(j);
		}
		else if(x<0){
			return;
		}
		else{
			int y = strcmp(arr[i].last_name, arr[j].last_name);
			if(y<=0){
				return;
			}
			else{
				swapElements(&arr[i], &arr[j]);				
				percolateDown(j);
			}
		}
	}
	else{
		arr[i].heap_index = i+1;
	}
	return;
}
int Insert(char *first, char *last){
	n++;
	Element temp, temp2;
	strcpy(temp.first_name,first);
	strcpy(temp.last_name,last);
	temp.heap_index = n;
	arr[n-1] = temp;
	temp2 = percolateUp(n-1);
	printf("%d\n", temp2.heap_index);
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
	if(n>0){
		printf("%s %s\n", arr[0].first_name, arr[0].last_name);
		arr[0] = arr[n-1];
		arr[0].heap_index = 1;
		n--;
		percolateDown(0);
	}
	else
		printf("-1\n");	
	return;
}
int Delete(int i){
	if(n>i){
		printf("%s %s\n", arr[i].first_name, arr[i].last_name);
		arr[i] = arr[n-1];
		arr[i].heap_index = i+1;
		n--;
		percolateDown(i);
	}
	else
		printf("-1\n");	
	return;
}

	
		
		
		
		
		
		
	