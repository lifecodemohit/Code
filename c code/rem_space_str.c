#include<stdio.h>
void main(){
    int i;
    char s[]="asf asf asfa";
    printf("%s\n", s);
    char *p;
    p = s;
    while(*p!='\0'){
        if(*p==' '){
            *p = *(p+1);
            p++;
        }
        else{
            p++;
        }
    }
    printf("%s\n", s);
}