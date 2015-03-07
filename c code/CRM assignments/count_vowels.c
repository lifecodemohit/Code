#include<stdio.h>
int main(){
    char* str[]={"Friends is an American television sitcom","created by David Crane and Marta Kauffman","which originally aired on NBC"};
    int count = 0;
    int i = 0;
	int n;
	n=  sizeof(str)/sizeof(str[0]);
	printf("%p\n", &str[3]);
    for(i=0; i<n; i++){
        char *c = str[i];
        while(*c){
            if(*c== 'a' || *c=='e' || *c=='i' ||*c == 'o' || *c =='u'||*c== 'A' || *c=='E' || *c=='I' ||*c == 'O' || *c =='U'){
                printf("%c ", *c);
                count++;
            }
            c++;
        }
        printf("\n");
    }
    printf("%d\n", count);
    return 0;
}    