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

int main()
{
    printf("Enter a number:\n");
    int num;
    scanf("%d", &num);
    int temp = num;
	int sum = 0;
	while(temp!=0)
	{
		sum +=pow(temp%10, 3);
		temp /= 10;
	}
	if(num==sum)
	{
	    printf("Yes, %d is an Armstrong number", num);
	}
	else
	{
	    printf("No, %d is not an armstrong number", num);
	}
	return 0;
}
