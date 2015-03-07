#include<stdio.h>
int main(){
	int i, n, k, x, c=0;
	scanf("%d %d", &n, &k);
	for(i=0; i<n; i++){
		scanf("%d", &x);
		if(x%k==0)
			c++;
	}
	printf("%d\n", c);
	return 0;
}