#include<stdio.h>
struct node
{
	char name[100];
};
void main(){
	struct node hah;
	scanf("%s", hah.name);
	printf("%s\n", hah.name);
}