#include<stdio.h>
int twofactor(int n){
	int count =0;
	while(n%2==0){
		n = n/2;
		count++;
	}
	return count;
}
int fivefactor(int n){
	int count =0;
	while(n%5==0){
		n=n/5;
		count++;
	}
	return count;
}
int main(){
	int i, j,n;
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		int m, t=0, f=0, c=0;
		scanf("%d", &m);
		for(j=1; j<=m; j++){
			t += twofactor(j);
			f += fivefactor(j);
			}
		c+=(((t)<(f))?(t):(f));
		printf("%d\n", c);
	}
	return 0;
}