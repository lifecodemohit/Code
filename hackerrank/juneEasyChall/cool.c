#include <stdio.h>
void binary(int number) {
	int remainder;

	if(number <= 1) {
		cout << number;
		return;
	}

	remainder = number%2;
	binary(number >> 1);    
	cout << remainder;
}
int main(){
	int test;
	while(test--){
		long long int i;
		int K;
		long long int R;
		scanf("%lld", &R);
		scanf("%d", &K);
		for(i=0; i<R, i++){
			long long int decimalNumber;
			long long int rem, quo;
		    int binaryNumber[100],i=1,j;
		    quo = decimalNumber;
		    while(quo!=0){
		         binaryNumber[i++]= quo % 2;
		         quo /= 2;
		    }
		}
	}
    return 0;
}