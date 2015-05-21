#include<stdio.h>
#include<string.h>
void main(){
	char s[100];
	scanf("%s", s);
	int a[1000];
	int l = strlen(s), i = 0;
	for(i=0; i<l; i++){
		a[i] = (int)s[i]-48;
	}
	for (i = 0; i < l; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}