#include <stdio.h>

int fact(int n){
	if(n<2){
		return 1;
	}
	else{
		return n*fact(n-1);
	}
}
int comb(int m){
	return 	fact(m)/(6*fact(m-3));
}

int main() {
	// your code goes here
	int t,i;
	scanf("%d", &t);
	for(i=0; i< t; i++){
		int n, k, x;
		scanf("%d %d",&n, &k);
		x = comb(n)- comb(k);
		printf("%d\n", x);
	}
	return 0;
}
