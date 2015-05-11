#include<stdio.h>
#include<math.h>

int powers[100000];
int countP = 0;
long long int func(long long int a[], long long int n){
	long long int sum = 0, i, j, x, k, y, l;
	for(i=0; i<n-1; i++){
		for(j = i+1; j<n; j++){
			if(a[j]>a[i]){
				// x=1;
				// for(k=0; k<j-i-1; k++)
					// x*=2;
				y = j-i-1;
				if(y<countP){
					x = powers[y];
				}
				else{
					for(l=0; l<j-i-1; l++){
						powers[l] = pow(2,l);
					}
					x = pow(2, j-i-1);
					countP = j-i-1;
				}
				
				sum +=x*(a[j]-a[i]);
			}
			else{
				// x=1;
				// for(k=0; k<j-i-1; k++)
					// x*=2;
				x = pow(2, j-i-1);
				sum +=x*(a[i]-a[j]);
			}
		}
	}
	sum = sum%1000000007;
	return sum;
}


long long int main(){
	int t;
	scanf("%d", &t);
	while(t){
		t--;
		long long int n, i, sum = 0;
		scanf("%lld", &n);
		long long int a[n];
		for(i=0; i<n; i++){
			scanf("%lld", &a[i]);
		}
		long long int d  = func(a, n);
		printf("%lld\n", d);
	}
	return 0;
}