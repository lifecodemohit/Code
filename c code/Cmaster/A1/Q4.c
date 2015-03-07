#include<stdio.h>
int search(int* arr[6][5], int n)
{
    int i, j;
    for(i=0; i<6; i++)
    {
        for(j=0; j<5;j++)
        {
            if(arr[i][j] == n)
            {
                printf("Row: %d,Col: %d\n", i, j);
                break;
            }
        }
    }
    return -1;
}
