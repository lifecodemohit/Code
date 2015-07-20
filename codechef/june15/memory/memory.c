#include <stdio.h>
int main(){
	int test;
	scanf("%d", &test);
	while(test--){
		int i,n;
		scanf("%d", &n);
		int M[n];
		for(i=0; i<n; i++){
			scanf("%d", &M[i]);
		}
		long long int allocated = 0;
		long long int current = 0;
		for(i=0; i<n; i++){
			if(M[i]>current)
			// {
				allocated += M[i]-current;
				// current = M[i];
			// }
			// else if(M[i]<current){
			current = M[i];
			// }
			// else if(M[i]<=)
		}
		printf("%lld\n", allocated);
	}
	return 0;
}