#include<stdio.h>
#include<string.h>
void main(){
    char str[100] = "Hello how are you?";
    char str2[100];
    char *p = str;
//    printf("%c", *p);
    while(*p!='\0'){
        if(*p!=' '){
//            printf("%c", *p);
            char c = *p;
            str2[strlen(str2) + 1] = '\0';
            str2[strlen(str2)] = c;
            p++;
        }
        else{
            p++;
        }
    }
    printf("\n");
    printf("%s\n", str2);
}
