#include<stdio.h>
#include<string.h>
void func(int a[], int n, int k){
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
			// a[i] = !a[i];
			if(k>1){
				if(i<n){
					if(a[i]!=a[i+1]){
						a[i-1]  = !a[i-1];
					}
					else{
						a[i] = !a[i];
					}
				}
				else{
					a[i] = !a[i];
				}
			}
			else{
				a[i] = !a[i];
			}
			c = 0;
			count++;
		}
	}
	if(k==1){
		if(count>n/2){
			count = n - count;
			for(i=0; i<n; i++){
				a[i]=!a[i];
			}
		}
	}
	printf("%d ", k);
	printf("%d\n", count);
	for(i=0; i<n; i++){
		printf("%d", a[i]);
	}
	printf("\n");
}



int main(){
	int test;
	int n, k;
	scanf("%d", &test);
	while(test--){
		scanf("%d %d", &n, &k);
		int arr[n], i=0;
		char s[n];
		scanf("%s", s);
		int l = strlen(s);
		for(i=0; i<l; i++){
			arr[i] = (int)s[i]-48;
		}
		func(arr, n, k);
	}
	return 0;
}