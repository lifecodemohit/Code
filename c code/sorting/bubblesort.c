#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	}
void main(){
	int i,j,n;
	printf("Enter teh number of elements to sort: ");
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for(i=0; i<n; i++){
		for(j=i; j<n; j++){
			if(a[j]<a[i]){
				swap(&a[j], &a[i]);
			}
		}
	}
	for(i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}