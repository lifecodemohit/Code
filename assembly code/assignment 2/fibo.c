#include<stdio.h>
int fibo(int n){
	if(n<2){
		return 1;
	}
	else{
		return fibo(n-1) + fibo(n-2);
	}
}
int main(){
	int i =0,n;
	for(i=0; i<20; i++){
		n = fibo(i);
		printf("%i\n", n);
	}
	return 0;
}