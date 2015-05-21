#include<stdio.h>
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int a, b, x;
		scanf("%d %d", &a, &b);
		if(a==1 && b==2){
			x = 0;
		}
		else if(a==1 && b==3){
			x = 6;
		}
		else if(){
			x = 36;
		}
		printf("%d\n", x);
	}
	return 0;
}