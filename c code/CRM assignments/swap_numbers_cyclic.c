#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int n, i=0;
    printf("Enter number of pointer: ");
    scanf("%d", &n);
    int a[n];
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    for(i=0; i<n-1; i++){
        swap(&a[i], &a[i+1]);
    }
    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }
}
    