#include<stdio.h>
#include<stdlib.h>
int main()
{
    float myFloats[5];
    for (int i=0; i<5; i++)
    {
        printf("Enter a float: ");
        scanf("%f", &myFloats[i]);
    }
    for(int i = 0; i<5; i++)
    {
        printf("%f\n", myFloats[i]);
    }
        return 0;
}
