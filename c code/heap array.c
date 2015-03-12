#include<stdio.h>
#include<stdin.h>
//for i childs are y = 2*i +1 and 2*i + 2
// i = 0,1,2,3,4,5,6,7,8,9,10.....
int find_parent(int arr[], int i){
	if(i>1){
		return (i-1)/2;
	}
	else
		return 0;
}
void swap(int *a, int *b){
	int *temp;
	temp = a;
	a = b;
	b = temp;
}
int max(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}
void max_heapify(int arr[], int i){
	int l = arr[2*i + 1];
	int r = arr[2*i + 2];
}
int build_heap(int arr[], int n){
	//for a size of n, number of leaves =
	for(i =  n/2 -1; i>0; i++){
		max_heapify(arr, i);
	}
}
void main(){
	int arr[] = {4,5,6,1,2,9,8,1};
	int n = 8;

}