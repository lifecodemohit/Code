#include<stdio.h>
#include<stdlib.h>
void main(){
    int r=2, c=3;
    int *p=(int*)malloc(r*c*sizeof(int));
    int i=0, j=0, a=1;
    for(i=0; i<r; i++){
        for(j=0; j<c;j++){
            *(p+i*c+j) = a++*2;
            }
        }
   
}