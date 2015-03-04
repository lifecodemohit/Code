#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int x = 0;
void swap(char *a, char *b){
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
	}
void cycle(char a[100]){
	int i = 0;
	int n = strlen(a);
	for(i=0; i<n-1; i++){
		swap(&a[i], &a[i+1]);
	}
}
int comp(char a[], char b[]){
	int n= strlen(a);
	if(strcmp(a,b)==0){
		printf("TRUE\n");
		return 1;
	}
	else if(x==n){
		printf("False\n");
		return -1;
	}
	else{
		cycle(a);
		x++;
		comp(a,b);	
	}
}
int main(){
	char a[100];
	char b[100];
	scanf("%s", &a);
	scanf("%s", &b);
	int n = strlen(a);
	int m = strlen(b);
	if(n!=m){
		return -1;
	}
	comp(a,b);
}