/*
Write a program to input a floating number. Store the number in an integer variable. If the input is 
exactly 12.11, then print the square of the int variable. Otherwise simply print the integer variable. 
 
Sample Input 1: 
<on console> 
Enter a float number: 
12.11 
<end> 
 
Sample Output 1: 
<on console> 
144 
<end> 

*/

#include<stdio.h>
#include<stdlib.h>
void main()
{
	printf("Enter a float number:\n");
	float num;
	scanf("%f", &num);
	float num2 = num*100;
	int num3 = num2;
	int integer = num;
	if (num3 == 1211)
	{
		int sqint = pow(integer,2);
		printf("%d", sqint);
	}
	else
	{
		printf("%d", integer);
	}
	return 0;
}
