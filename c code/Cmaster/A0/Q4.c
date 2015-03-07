/*
Write a program to check if an integer number is a palindrome or not. 
 
Sample Input 1: 
Enter a number: 
1234321 
 
Sample Output 1: 
Yes, it is a palindrome 
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("Enter a number:\n");
    int num;
    scanf("%d", &num);
    int temp = num;
	int rev = 0;
	while(temp!=0)
	{
		rev *=10;
		rev +=temp%10;
		temp /= 10;
	}
	if(num==rev)
	{
	    printf("Yes, It is a palindrome");
	}
	else
	{
	    printf("No, It is not a palindrome");
	}
	return 0;
}

