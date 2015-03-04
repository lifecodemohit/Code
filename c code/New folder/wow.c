#include<stdio.h>
#include<stdlib.h>
int main(){
    char *s = "Hello how are you ee ao okjio";
    int i=0;
    int count = 0;
    char*p = s;
    while(*(p+1)!='\0'){

        printf("%c", *p);
        p=s+i;
        i+=1;
    }
}
