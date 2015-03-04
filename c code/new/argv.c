#include<stdio.h>
#include<stdlib.h>
void disp(int *x){
    *x +=100;
}
void main(){
    int a = 100;
    int *p;
    p = &a;
    disp(p);
    printf("%d\n", a);
    
}