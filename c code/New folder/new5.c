#include<stdio.h>
#include<stdlib.h>
int main(){
    char *str[] = {"A story OF Bird", "Died In A WEII", "With No fear", "Rest IN Peace"};
    int j = 0;
    int count = 0;
    for(j=0; j<4; j++){
        char *s = str[j];
        int i=1;
        int d;
        char *p = s;
        while(*(p+1)!='\0'){
            d = *p;
//            printf("%d %c\n", d, *p);
            if(d >64 && d<92){
                count+=1;
                printf("\t%d %c\n", count, d);
            }
            p=s+i;
            i+=1;
        }
    }
    printf("%d", count);

}
