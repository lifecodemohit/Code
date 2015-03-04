/*
Write a program to print a rhombus made of asterix where side is of length n, where n is the 
input. 
 
Sample Input 1: 
Enter n: 
3 
 
Sample Output 1: 
     * 
   *  * 
  *    * 
   *  * 
    * 

*/
#include<stdio.h>
#include<stdlib.h>
void lnp(int n, int ln)
{
    int i;
    if(ln == 1)
    {
        for(i = 0; i< n-ln; i++)
            printf(" ");
        printf("*");
        for(i = 0; i< n-ln; i++)
            printf(" ");
        printf("\n");
    }
    else if(n-ln>0)
    {
        for(i = 0; i< n-ln; i++)
            printf(" ");
        printf("*");
        for(i=0; i<((2*ln)-3); i++)
            printf(" ");
        printf("*");
        for(i = 0; i< n-ln; i++)
            printf(" ");
        printf("\n");
    }
    else if(ln==n)
    {
        printf("*");
        for(i =0; i<2*n-3; i++)
            printf(" ");
        printf("*\n");
    }
}
void main()
{
    printf("Enter n:\n");
    int n;
    scanf("%d", &n);
    int i = 0;
    int ln = 1;
    while(ln!=n+1)
    {
        lnp(n, ln);
        ln++;
    }
    ln--;
    while(ln!=1)
    {
        ln--;
        lnp(n,ln);

    }
}
