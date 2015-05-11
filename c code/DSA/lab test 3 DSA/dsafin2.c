#include<stdio.h>
#include<stdlib.h>
int c = 0;
int k = 0;
int n = 0;
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
int buildMinHeap(int A[]){
	int len = A[0];
	int i;
	for(i=len/2; i>0; i--){
		minHeapify(A, i);
	}
	return;
}

int insert(int A[], int w){
	if(w<=A[1]){
		if(A[1]==k)
			c++;
		A[1] -= w;
	}
	else if(w>A[1]){
		insert(A+1, w);
	}
	return;
}

int main(){
	int i,j, t;
	scanf("%d", &t);
	while(t>0){
		t--;
		scanf("%d %d", &n, &k);
		int bin[n+1];
		bin[0] = c;
		for(i=0; i<n+1; i++){
			bin[i] = k;
		}
		int x;
		for(i=0; i<n; i++){
			bin[0] = c;
			scanf("%d", &x);
			insert(bin, x);
			buildMinHeap(bin);
		}
		printf("%d\n", c);
		c = 0;
	}
	return 0;
}