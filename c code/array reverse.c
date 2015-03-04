#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,i,temp;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    for(i=0; i<n; i++){
        printf("Enter %d element: ", i);
        scanf("%d", &a[i]);
    }
    for(i=0; i<n/2; i++){
        temp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = temp;
    }
    for(i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
