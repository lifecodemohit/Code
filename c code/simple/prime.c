#include <stdio.h>
#include <stdlib.h>

// int arr[100000];
// int sieve = 0;

int isPrime(int n){
	int i, flag = 0;
	for(i=2; i<=n/2; i++){
		if(n%i==0){
			flag = 1;
			break;
		}
	}
	if(flag==1){
		flag = 0;
		return 0;
	}
	return 1;
}


void prime(int n){
	int i;
	for(i=1; i<=n; i++){
		if(isPrime(i)==1)
			printf("%d ", i);
	}
	printf("\n");
}
void main(){
	// printf("%d\n", isPrime(2));
	prime(17);
}