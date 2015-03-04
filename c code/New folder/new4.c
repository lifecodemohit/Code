#include<stdio.h>
#include<stdlib.h>
int main(){
    char *s = "Hello how are you ee ao okjio";
    int i=0;
    int count = 0;
    char*p = s;
    while(*(p+1)!='\0'){
        char c = *p;
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            char d = *(p+1);
            if(d=='a' || d=='e' || d=='i' || d=='o' || d=='u' ){
                count+=1;
            }
        }
        p=s+i;
        i+=1;
    }
    printf("%d", count);
}
