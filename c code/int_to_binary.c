#include <stdio.h>

int main(void) 
{
	int n;
	scanf("%d", &n);
	int bit[32], i = 0, j;
	while(n)
	{
		bit[i] = n % 2;
		n /= 2;
		i++;
	}
	for(j=i - 1; j>=0; --j)
		printf("%d", bit[j]);
	printf("\n");
	return 0;
}
