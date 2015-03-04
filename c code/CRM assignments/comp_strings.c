#include<stdio.h>
#include<stdlib.h>
int main(){
    char *a= malloc(100), *b = malloc(100);
    scanf("%s", a);
    scanf("%s", b);
    char *c, *d;
    c = a;
    d = b;
    while(*c!='\0' || *d!='\0'){
        if(*c<*d){
            printf("-1\n");
            return -1;
            }
        else if(*c>*d){
            printf("1\n");
            return 1;
            }
        c++, d++;
    }
    printf("0\n");
    return 0;
}