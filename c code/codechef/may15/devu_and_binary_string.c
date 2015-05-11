#include<stdio.h>
int func(int a[], int n, int k){
	int i, t, c = 0, count = 0;

	for(i=1; i<n; i++){
		if(a[i]==a[i-1]){
			c++;
		}
		else{
			c=0;
		}
		// printf("lalala %d %d %d\n", c, k, a[i]);
		if(c==k){
			a[i] = !a[i];
			c = 0;
			count++;
		}
	}
	printf("%d\n", count);
	for(i=0; i<n; i++){
		printf("%d", a[i]);
	}
	printf("\n");
	return;
}



int main(){
	int test;
	int n, k;
	scanf("%d", &test);
	while(test--){
		scanf("%d %d", &n, &k);
		int arr[n], i=0;
		long long unsigned int s, t, factor = 1;
		scanf("%lld", &s);
		t = s;
		while(t){
			t/=10;
			factor = factor*10;
		}
		while(factor>1){
			factor/=10;
			arr[i] = s/factor;
			s = s%factor;
			i++;
		}
		// printf("vllaslf %d\n", i);
		int cx = i;
		int j;
		if(i<n){
			for(j=n-1;i>=0;j--){
				// printf("iiii%d\n", i);
				i--;
				arr[j] = arr[i];
			}
			// printf("asfasf%d\n", j);
			while(j>=0){
				arr[j] = 0;
				j--;
			}
		}

		// for(i=0; i<n; i++)
			// printf("%d ", arr[i]);
		// printf("\n");
		func(arr, n, k);
	}
	return 0;
}