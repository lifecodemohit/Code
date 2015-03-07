/*
Write a program to print the ASCII equivalent of a number. 
 
Sample Input 1: 
<on console> 
Enter a number: 
97 
<end> 
 
Sample Output 1: 
<on console> 
a 
<end>
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num;
	printf("Enter a number:\n");
	scanf("%d", &num);
	char ascii = num;
	printf("%c\n", ascii);
	return 0;
}
