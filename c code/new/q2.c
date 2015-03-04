#include<stdio.h>
#include<string.h>
void main(){
    char *s[] = {"Shakespeare produced most of his known", "he wrote tragicomedies", "His plays remain highly popular today"};
    int i;
    for(i=0; i<3; i++){
        int l = strlen(s[i]);
        int j;
        char *p = s[i] + l;
        for(j=l; j>=0;j--){
            printf("%c", *p);
            p--;
        }
        
    }
    printf("\n");
}