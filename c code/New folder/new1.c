#include<stdio.h>
#include<stdlib.h>
int main(){
    printf("Enter the number of elements for the array: ");
    int i,n;
    scanf("%d", &n);
    int arr[n];
    for(i=0; i<n; i++){
        printf("Enter %d element: ", i);
        scanf("%d", &arr[i]);
    }
    int arra[n];
    for(i=0; i<n;i++){
        arra[i] = arr[n-i-1];
    }
    for(i=0; i<n;i++){
        printf("%d ", arra[i]);
    }

    int a[n];
    for(i=0; i<n; i++){
        a[n-i-1] = *arr+i;
    }
    printf("\n");
    for(i=0; i<n;i++){
        printf("%d ", a[i]);
    }

}
