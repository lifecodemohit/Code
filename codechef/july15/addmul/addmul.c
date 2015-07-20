#include <stdio.h>
int main(){
	long long int N, Q, i, j;
	long long int M = 1000000007;
	scanf("%lld %lld", &N, &Q);
	long long int A[N];
	for(i=0; i<N; i++){
		scanf("%lld", &A[i]);
	}
	for(i=0; i<Q; i++){
		long long int n, x, y, v;
		scanf("%lld", &n);
		if(n==1){
			scanf("%lld %lld %lld", &x, &y, &v);
			x--;
			y--;

			for(j=x; j<=y; j++){
				A[j]+=v;
				A[j]%=M;
			}
		}
		else if(n==2){
			scanf("%lld %lld %lld", &x, &y, &v);
			x--;
			y--;

			for(j=x; j<=y; j++){
				A[j]*=v;
				A[j]%=M;
			}			
		}
		else if(n==3){
			scanf("%lld %lld %lld", &x, &y, &v);
			x--;
			y--;

			for(j=x; j<=y; j++){
				A[j]=v;
			}			
		}
		else{
			long long int sum = 0;
			scanf("%lld %lld", &x, &y);
			x--;
			y--;
			for(j=x; j<=y; j++){
				// printf("\n%lld\n", sum);
				sum+=A[j];
				// sum%=M;
				// printf("\n%lld\n", sum);
			}
			printf("%lld\n", sum);
		}
	}
	return 0;
}