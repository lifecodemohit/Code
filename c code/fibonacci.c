#include<stdio.h>
int main()
{
    int firstnum = 1;
    int secondnum = 1;
    int i, n;
    printf("Enter an integer for fibonacci: ");
    scanf("%d", &n);
    printf("%i\n%i\n",firstnum,secondnum);
    for(i=1; i<n; i++)
    {
        int temp = secondnum;
        secondnum += firstnum;
        firstnum = temp;
        printf("%i\n", secondnum);
    }
    return 0;
}
