#include <stdio.h>

int main()
{
   int n, x;
   printf("\nEnter the No. of Disks: ");
   scanf("%d",&n);
   for (x=1; x < (1 << n); x++)
   {
     printf("\nMove from Peg %i to Peg %i",(x&x-1)%3+1,((x|x-1)+1)%3+1);
   }
   printf("\n");
   return 0;
}
