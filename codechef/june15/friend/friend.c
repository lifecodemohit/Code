#include <stdio.h>
int main(){
	int test, i;
	scanf("%d", &test);
	while(test--){
		long long int T1, T2, t1, t2;
		scanf("%lld %lld %lld %lld", &T1, &T2, &t1, &t2);
		if(t1==0 && t2 ==0){
			if(T1>T2)
				printf("%f\n", 1.0/T2);
			else
				printf("%f\n", 1.0/T1);
		}

	}
	return 0;
}