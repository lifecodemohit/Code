#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void rightrot(int a, int m){
	int length = (int)floor(log10((float)a)) + 1;
	char * arr = malloc(length*sizeof(char));
	int i = length-1;
	do{
		arr[i]=a%10;
		a/=10;
		i--;
	}while(a!=0);
	char *arr2 = malloc(length*sizeof(char));
	int n = length;		
	for(i=0; i<n; i++){
		arr2[(i+m)%n] = arr[i];
	}
	for(i=0; i<n; i++){
		printf("%d", arr2[i]);
	}
	printf("\n");
}

int main(){
	int a = 123456;
	int b = 3;
	rightrot(a, b);
	return 0;
}