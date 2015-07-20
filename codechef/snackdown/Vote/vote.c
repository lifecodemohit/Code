#include<stdio.h>
void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int main(){
	int t;
	// int a, b;
	// a = 1;
	// b = 2;
	// swap(&a, &b);
	// printf("%d %d\n", a, b);
	scanf("%d", &t);
	while(t--){
		int n, i, j, k;
		scanf("%d", &n);
		int a[n+1];
		int flag = 0;
		int sum = 0;
		for(i=1; i<=n; i++){
			scanf("%d", &a[i]);
			if(a[i]>=n)
				flag = 1;
			sum+=a[i];
		}
		if(sum!=n)
			flag = 1;
		if(flag==1){
			printf("-1\n");
			// break;
		}
		else{
			int b[n+1];
			b[0] = -1;
			for(i=0; i<=n; i++)
				b[i]=0;
			j = 1;
			for(i=1; i<=n; i++){
				int count = a[i];
				while(count){
					if(i!=j && b[j]==0){
						count--;
						b[j] = i;
					}
					// int flag2 = 0;
					else if(j==i && b[j]==0){
						k = j;
						int flag2 = 0;
						while(flag2==0){
							j = j%n+1;
							if(j==0)
								j++;
							if(b[j]!=k){
								flag2 = 1;
								// printf("jjjjj%d\n", j);
							}
							// printf("tadaad %d %d\n",i, j);
						}
						swap(&b[j], &b[k]);
						b[j] = i;
						count--;
					}
					else{
						j = (j)%(n) + 1;
						// printf("lalal %d %d\n",i, j);
					}
				}
			}
			for(i=1; i<=n; i++){
				printf("%d ", b[i]);
			}
			printf("\n");
		}
	}
	return 0;
}