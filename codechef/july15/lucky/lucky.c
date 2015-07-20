#include <stdio.h>
#include <math.h>
int main(){
	long long int N;
	scanf("%lld", &N);
	long long int A[N];
	long long int i;
	for(i=0; i<N; i++)
		scanf("%lld", &A[i]);
	for(i=0; i<N; i++){
		long long int x = A[i];
		long long int factor5 = 0;
		long long int factor2 = 0;
		while(x%5==0){
			x/=5;
			factor5++;
		}
		x = A[i];
		while(x%2==0){
			x/=2;
			factor2++;
		}
		if(factor2>=factor5){
			printf("%lld\n", A[i]);
		}
		else{
			long long int num_of_2_req = factor5 - factor2;
			long long int num_of_4_req;
			if(num_of_2_req % 2 ==0)
				num_of_4_req = num_of_2_req/2;
			else
				num_of_4_req = num_of_2_req/2 + 1;
			x = A[i]*(pow(4,num_of_4_req));
			printf("%lld\n", x);
		}
	}
	return 0;
}