#include<stdio.h>
int main()
{
    int arr[6][5]= {{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7},{4,5,6,7,8},{5,6,7,8,9},{6,7,8,9,0}};
    int sum = 0;
    int n;
    printf("Enter the column number: ");
    scanf("%d", &n);
    int i;
    for(i =0; i< 5; i++)
    {
        sum+= arr[n][i];
    }
    printf("%d", sum);
    return 0;
}
