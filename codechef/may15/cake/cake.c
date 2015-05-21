#include<stdio.h>
#include<limits.h>
#include<math.h>
int mod = 1000000007;
int main(){
	int test;
	scanf("%d", &test);
	while(test--){
		int n, k, q;
		scanf("%d %d %d", &n,&k,&q);
		long long int Array[n+1];
		int a,b,c,d,e,f,r,s,t,m;
	
		scanf("%d %d %d %d %d %d %d %d %d %d %d", &a,&b,&c,&d,&e,&f,&r,&s,&t,&m,&Array[1]);
		int x, i, j, min = INT_MAX;
		for(x = 2; x<=n; x++){
			if((int)pow(t,x)%s<=r)
				Array[x] = ((long long int)((a*pow(Array[x-1],2)) + b*Array[x-1] + c))%m;
			else
				Array[x] = ((int)((d*pow(Array[x-1],2)) + e*Array[x-1] + f))%m;
		}
		int L1, La, Lc, Lm, D1, Da, Dc, Dm, L, R;
		scanf("%d %d %d %d %d %d %d %d", &L1, &La, &Lc, &Lm, &D1, &Da,&Dc, &Dm);
		
		int qualityOfDish[q];
		for(i = 0; i<q; i++){
			L1 = (La*L1 + Lc)%Lm;
			D1 = (Da * D1 + Dc)%Dm;
			L = L1 + 1;
			R =((L+k-1+D1)<n)?(L+k-1+D1):n;
			// printf("L: %d, R: %d\n", L, R);
			for(j=L; j<=R; j++){
				// printf("j %d ", j);
				// printf("%d\n", Array[j]);
				if(Array[j]<min)
					min = Array[j];
			}
			qualityOfDish[i] = min;
			min = INT_MAX;
			// printf("blah %d %d ", qualityOfDish[i], i);
		}
		// printf("\n");
		int sum = 0;
		int product = 1;
		for(i=0; i<q; i++){
			sum+=qualityOfDish[i];
			sum %=mod;
			product*=qualityOfDish[i];
			product%=mod;
		}	
	/*	
		for (i = 1; i <= n; i++)
		{
			printf("%d ", Array[i]);
		}
		printf("\n");
	*/
		printf("%d %d\n", sum, product);
	}
	return 0;
}