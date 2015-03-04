#include<stdio.h>
#include<stdlib.h>
void merge(int a[], int min, int mid, int max);
void div(int a[], int min, int max);
int main()
{
    int a[30];
    int i,n;

    printf("Enter the number of elements: \n");
    scanf("%d",&n);
    for( i = 0; i<n; i++)
        scanf("%d",&a[i]);
    div(a,0,n-1);
    printf("Sorted elments: \n");
    for(i = 0; i<n; i++)
        printf("%d",a[i]);

    return 0;
}

void div(int a[], int min, int max)
{
    int mid;
    if(min<max)
    {
        mid = (min+max)/2;
        div(a, min, mid);
        div(a, mid+1, max);
        merge(a, min, mid, max);
    }
}
void merge(int a[], int min, int mid, int max)
{
    int temp[30];
    int i, j, k, m;
    j = min;
    m = mid+1;
    for(i = min; j<mid && m<=max; i++)
    {
        if(a[j]<=a[m])
        {
            temp[i] = a[j];
            j++;
        }
        else
        {
            temp[i] = a[m];
            m++;
        }
        if(j>mid)
        {
            for(k=m; k<=max; k++)
            {
                temp[i] = a[k];
                i++;
            }
        }
        else
        {
            for(k =j; k<mid; k++)
            {
                temp[i] = a[k];
                i++;
            }
        }
        for(k = min; k<=max; k++)
            a[k] = temp[k];
   }
}
