#include<stdio.h>
void swap(int *a, int *b){
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
void main(){
	int a = 6;
	int b = 9;
	swap(&a,&b);
	printf("%d %d\n", a, b);
}