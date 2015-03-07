#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(char *a, char *b){
    char *temp=(char *)malloc(1*sizeof(char));
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
    free(temp);
    }
int comp(char *a, char *b){
    return strcmp(a,b);
    }
int main(){
    char s[4][50];
    int a;
    strcpy(s[0], "This is string 1");
    strcpy(s[1], "This is string 2");
    strcpy(s[2], "This is string 3");
    strcpy(s[3], "This is string 4");
    qsort(s, 4, sizeof(char), comp);
    printf("%s\n", s[1]);
    printf("%s\n", s[2]);
    printf("%s\n", s[3]);
    printf("%s\n", s[4]);
    printf("%d\n", a);
//    printf("%d %d %d %d\n", sizeof(str1), sizeof(str2), sizeof(str3), sizeof(str4));
//    free(str1);
    return 0;
  }