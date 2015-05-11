#include<stdio.h>
int func(){
		int flag = 0,n,i;
		scanf("%d", &n);
		if(n>100000){
			return 0;
		}
//		int A[n];
		int sum =0, x, max = 0, d, min = 10001;
		for(i=0; i<n; i++){
//			scanf("%d", &A[i]);

			scanf("%d", &d);
			sum = sum+d;
			if(d<2){
				flag = 1;
//				printf("flag %d\n", flag);
			}
/*			
			if(max<d){
				max = d;
			}
*/
			if(min>d){
				min = d;
			}

		}
		if(flag==1){
			printf("%d\n", -1);
		}
		else{
			printf("%d\n", sum-min+2);
		}

	
	return 0;
}
int main(){
	int t;
	scanf("%d", &t);
	if(t>10){
		return;
	}
	while(t){
		t--;
		func();
	}
	return;
}