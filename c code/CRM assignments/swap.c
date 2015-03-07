#include<stdio.h>
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	}
int swapi(int a, int b){
	int temp = a;
	a = b;
	b = temp;
	return 
void main(){
	int a = 2, b = 3;
	swap(&a,&b);
	printf("%d %d\n", a, b);
}