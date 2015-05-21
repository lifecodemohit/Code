#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int mod = 1000000007;
int cmpfunc (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}

unsigned long long int modExp(long long int a, long long int b){
	unsigned long long int result = 1;
	while(b>0){
		if(b%2==1){
			result = (result*a)%mod;
		}
		b >>= 1;
		a = (a*a)%mod;
	}
	return result;
}


int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n,i,j;
		scanf("%d", &n);
		unsigned long long int arr[n], powOf2[n];
		for(i=0; i<n; i++){
			scanf("%llu", &arr[i]);
		}
		qsort(arr, n, sizeof(arr[0]), cmpfunc);
		// printf("asakakaf\n");
		unsigned long long int mySum = 0, min, max;

		for(i=0; i<n; i++){
			powOf2[i] = ( ((modExp(2,i))) -(1%mod) )%mod;
		}

		for(i=0; i<n; i++){
			// long long int a,b,c,d,e,f;
			// a = ((powersOf2[i])-1+ mod)%mod;
			// b = arr[i];
			// c = arr[n-i-1];
			// d = (b - c + mod)%mod; //d = (b-c)%mod
			// e = (( a%mod )*( d%mod ))%mod; // e = a*d
			// mySum= ((mySum%mod)+(e%mod))%mod; //mysum + e			
			// mySum = mySum + (a * (b-c));
			// mySum+= ((pow(2,i)-1) *(arr[i]-arr[n-i-1]));
			if(i==0){
				max = 0;
				min = ((arr[i]%mod)*(powOf2[n-1]))%mod;
			}
			else if(i==n-1){
				min = 0;
				max = ((arr[i]%mod)*(powOf2[i]))%mod;
			}
			else{
				min=((arr[i]%mod)*(powOf2[n-i-1]) )%mod;
				max=((arr[i]%mod)*(powOf2[i]) )%mod;
			}
			// printf("%llu %llu\n", min, max);
			mySum = ((mySum + max)%mod - min +mod)%mod;
		}
		printf("%llu\n", mySum);

	}
	return 0;
}