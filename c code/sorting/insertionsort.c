#include<stdio.h>
#include<string.h>
void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void main(){
	int i,n;
	printf("Enter the number of elements to sort: ");
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for(i=0; i<n; i++){
		int j = i;
		while(j>0 && a[j]< a[j-1]){
			swap(&a[j-1], & a[j]);
			j--;
		}
	}
	for(i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}