#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>

#define mod 1000000007

using namespace std;

unsigned long long modExp(long long b, long long e)
{
	unsigned long long res=1;
	while(e>0)
	{
		if(e%2==1)
		{
			res=(res*b)%mod;
		}
		// printf("%llu\n", e);
		e=e>>1;
		// printf("%llu\n", e);
		b=(b*b)%mod;
	}
	return res;
}

int main()
{
	int t,i,n;
	unsigned long long j;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		unsigned long long A[n],S[n];
		for(j=0;j<n;j++)
		{
			A[j]=( ((modExp(2,j))) -(1%mod) )%mod;
		}
		for(j=0;j<n;j++)
		{
			scanf("%llu",&S[j]);
		}
		sort(S,S+n);
		unsigned long long sum=0,max,min;
		for(j=0;j<n;j++)
		{
			if(j==0)
			{
				max=0;
				min=( (S[j]%mod) * (A[n-1]) )%mod;
				//printf("%llu: min=%llu, max=%llu \n",j,min,max );
				
			}
			else if(j==n-1)
			{
				min=0;
				max=( (S[j]%mod) * (A[j]) )%mod;
				//printf("%llu: min=%llu, max=%llu \n",j,min,max );
			}
			else
			{
				min=( (S[j]%mod) * (A[n-j-1]) )%mod;
				max=( (S[j]%mod) * (A[j]) )%mod;
				//printf("%llu: min=%llu, max=%llu \n",j,min,max );
			}
			sum = (((sum%mod + max%mod)%mod - min%mod +mod)%mod)%mod;
			//printf("%llu\n",sum);
		}
		printf("%llu\n",sum);
	}

	return 0;
	
}