#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i = 0;
    int arr[3];
    for(i=0; i<3; i++){
        scanf("%d", &arr[i]);
    }
    int flag = 0;
    for(i=0; i<3;i++){
        int a,b,c,j;
        a = arr[i];
        if(i+1>3){
            j = 3-i-1;
            b = arr[j];
        }
        else{
            b = arr[i+1];
        }

        if(i+2>3){
            j = 3-i-2;
            c = arr[j];
        }
        else{
            c = arr[i+2];
        }
        printf("%d %d %d\n", a, b, c);
        if(a*a < b*b + c*c){
            flag = 1;
            break;
        }
    }
    if(flag==0){
        printf("Valid");
    }
    else{
        printf("Not Valid");
    }


    return 0;
}
