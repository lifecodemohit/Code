#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int a,i;
    scanf("%d", &a);
    int arr[4];
    for(i=0; i<4;i++){
        if(a%10!=9){arr[i] = a%10 + 1;}
        else{arr[i] = 0;}
        a = a/10;
    }
    for(i=3; i>=0;i--){
        printf("%d", arr[i]);
    }
    return 0;
}
