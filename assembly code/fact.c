#include<stdio.h>
int fact(int n){
	if(n<2){
		return 1;
	}
	else{
		return n*fact(n-1);
	}	
}	
int main(){
	int i, n;
	n=20;
	for(i=1; i<n; i++){
		printf("%d ", fact(i));
	}
	return 0;
}
	