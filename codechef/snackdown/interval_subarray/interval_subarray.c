#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


int main(){
	int test;
	scanf("%d", &test);
	while(test--){
		int n, w, i=0, j, mainCount = 0, count = 0, flag = 0;
		scanf("%d %d", &n, &w);
		int arr[n];
		for(i=0; i<n; i++)
			scanf("%d", &arr[i]);
		qsort(arr, n, sizeof(int), cmpfunc);
		// for(i=0; i<n; i++){
		// 	printf("%d ", arr[i]);
		// }
		// printf("\n");
		i =0;
		while(i<n){
			for(j=i+1; j<w && j<n; j++){
				if(arr[j]-arr[j-1]!=1){	
					flag = 1;
					break;
				}
				else{
					count++;
					printf("%d\n", count);
				}
			}
			if(flag==0)
				mainCount+=count;
			flag = 0;
			count = 0;
			i++;
		}
		printf("%d\n", mainCount);
	}
	return 0;
}