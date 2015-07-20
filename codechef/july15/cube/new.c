#include <stdio.h>
#include <string.h>
int main(){
	char a[10], b[10], c[10];
	scanf("%s", a);
	scanf("%s", b);
	scanf("%s", c);
	printf("%d\n", strcmp(a,b) && strcmp(a,c));
	// printf("%s\n", a);
	return 0;
}