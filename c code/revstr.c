#include<stdio.h>
#include<string.h>
void main(){
    char s[] = "Hello how are you?";
    printf("%s\n", s);
    char *p;
    p = s;
    int n = strlen(s);
    int i=0, j = n-1;
    while(i<j){
        char temp;
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    printf("%s\n", s);
}
