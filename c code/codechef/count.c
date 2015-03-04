#include<stdio.h>
#include<string.h>
int main(){
    int t, x;
    scanf("%d", &t);
    for(x=0; x<t; x++){
        int i,n,j;
        char s[100];
        scanf("%s", &s);
        n = strlen(s);
        char *c = s;
        int arr[26];
        for(i=0; i<26; i++){
            arr[i]=0;
        }
        for(i=0; i<n; i++){
            int a;
            a = *c;
            a = a-97;
            arr[a] +=1;
            *c++;        
        }
        int max=0;
        j=0;
        for(i=0; i<26; i++){
            if(arr[i]>max){
                max = arr[i];
                j = i;
            }
        }
        char *e=s;
        j+=97;
        char d; 
        d = j;
        for(i=0; i<n; i++){
            if(*e!=j){
                printf("%c", *e);
            }
            else{
                printf("?");
            }
            *e++;
        }
        printf("\n");
    }
    return 0;
}
