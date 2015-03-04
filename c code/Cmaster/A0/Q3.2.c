/*
Write a program to check if a number is Armstrong or not. (Explanation: Armstrong number is a
number such that, the sum of cube of each digit is equal to the number itself. Example: 153 = 
cube(1) + cube(5) + cube(3)= 1 + 125 + 27 = 153) 
 
Sample Input 1: 
Enter a number: 
153 
 
Sample Output 1: 
153 is an armstrong numbe
*/

#include<stdio.h>
#include<stdlib.h>

void main()
{
    printf("Enter a number:\n");
    int num;
    char string[11];
    scanf("%d", &num);
    sprintf(string, "%d", num);
    //snprintf(string, 20, "%d", num);
    int n = strlen(string);
    int i;
    int nstring[n];
    for(i=0; i<n; i ++)
	{
		nstring[i] = string[i];
	}
	int sum=0;
	for(i=0; i<n; i ++)
	{
		nstring[i] -=48;
		sum += pow(nstring[i], 3);
	}
    if(sum==num)
    {
        printf("%d is an armstrong number", num);
    }
    else
    {
        printf("%d is not an armstrong number", num);
    }
    return 0;

}

