#include<stdio.h>
#include<stdlib.h>
typedef struct{
    char* name;
    int roll;
}info;
void main(){
    info varun;
    varun.name="Happy Singh";
    varun.roll = 18;
    printf("%s\n", varun.name);
    printf("%d\n", varun.roll);
}