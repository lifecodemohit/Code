#include<stdio.h>
#include<stdlib.h>
int main(){
    int arr[3][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
//    int arr[3][5]={{11,21,31,41,51},{16,71,81,19,110},{101,12,13,14,15}};
    printf("%d\n", *(*(arr+2)+1));
    printf("%d\n", *(*(arr+1)+2));
    printf("%d\n", *(*(arr+1)));
    printf("%d\n", *(*(arr)+3));
}
