#include<stdio.h>
int main(){
	int arr[10][10];
	int i= 0, j=0;
	for(i=0; i<10; i++){
		for(j=0; j<10; j++){
			arr[i][j] = i+j;
		}
	}
	for(i=0; i<10; i++){
		for(j=0; j<10; j++){
			printf("%d %d %d\n", i, j, arr[i][j]);
		}
	}
	return 0;
}