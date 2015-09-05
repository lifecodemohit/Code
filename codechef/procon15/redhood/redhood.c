#include <stdio.h>
#include <math.h>
int flip(int x){
	if(x==1)
		return -1;
	else
		return 1;
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int i,j,n;
		scanf("%d", &n);
		int a[n], b[n];
		for(i=0; i<n; i++){
			scanf("%d", &a[i]);
		}
		// int sum = 0, product = 1;
		// for(i=0; i<n; i++){
		// 	product = 1;
		// 	int count = 0;
		// 	j = i;
		// 	while(count<4){
		// 		int x= (j+count)%n;
		// 		// printf("%d ", x);
		// 		product*= a[x];
		// 		count+=1;
		// 	}
		// 	// printf("\n");
		// 	sum+=product;
		// }
		// // printf("%d\n", sum);
		for(i=0; i<n;i++){
			if(pow(2,i)>n)
				break;
			else{
				int val, ind;
				ind = pow(2,i);
				val = flip(a[ind]);
				a[ind-1] = val;
			}
		}
		for(i=0; i<n; i++){
			printf("%d ", a[i]);
			// product = 1;
			// int count = 0;
			// j = i;
			// while(count<4){
			// 	int x= (j+count)%n;
			// 	// printf("%d ", x);
			// 	product*= a[x];
			// 	count+=1;
			// }
			// // printf("\n");
			// sum+=product;
		}
		printf("\n");
		// printf("\n%d\n", sum);

	}
	return 0;
}