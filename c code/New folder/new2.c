#include<stdio.h>
#include<stdlib.h>
void update(int *a){
    int i =0;
    for(i=0; i<10;i++){
        *(a+i) = *(a+i) *5;
    }
}
void main(){
    int a[10] = {3,5,6,1,2,8,9,7,4,0};
    int i = 0;
    for(i=0; i<10;i++){
        printf("%d ", *(a+i));
    }
    printf("\n");
    update(a);
    for(i=0; i<10;i++){
        printf("%d ", *(a+i));
    }
}
