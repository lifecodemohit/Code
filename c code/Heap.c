#include<stdio.h>
#include<stdlib.h>
int parent(int i){
	return i/2;
}
int left(int i){
	return 2*i;
}
int right(int i){
	return 2*i + 1;
}
void swap(int *a, int *b){
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
void minHeapify(int A[], int i){
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if(l<=A[0] && A[l]<A[i])
		smallest = l;
	if(r<=A[0]&& A[r]<A[smallest])
		smallest = r;
	if(smallest!=i){
		swap(&A[smallest], &A[i]);
		minHeapify(A, smallest);
	}
}
void buildMinHeap(int A[]){
	int len = A[0];
	int i;
	for(i=len/2; i>0; i--){
		minHeapify(A, i);
	}
}
void maxHeapify(int A[], int i){
	int l = left(i);
	int r = right(i);
	int largest;
	if(l<=A[0] && A[l]>A[i])
		largest = l;
	else
		largest = i;
	if(r<=A[0] && A[r]>A[largest])
		largest = r;
	if(largest!=i){
		swap(&A[largest], &A[i]);
		maxHeapify(A, largest);
	}
}
void buildMaxHeap(int A[]){
	int len = A[0];
	int i;
	for(i=len/2; i>0; i--){
		maxHeapify(A, i);
	}
}
void heapSort(int A[]){
	buildMaxHeap(A);
	int i,n;
	n = A[0];
	for(i=n; i>1; i--){
		swap(&A[1], &A[i]);
		A[0]--;
		maxHeapify(A, 1);
	}
}
int main(){
	int i,n;
	printf("Enter the size of heap array\n");
	scanf("%d", &n);
	int A[n+1];
	A[0] = n;
	for(i=1; i<=n; i++){
		scanf("%d", &A[i]);
	}
	for(i=1; i<=n; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
	buildMaxHeap(A);
	printf("MAX Heap: ");
	for(i=1; i<=n; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
	buildMinHeap(A);
	printf("MIN Heap: ");
	for(i=1; i<=n; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
	heapSort(A);
	for(i=1; i<=n; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
}