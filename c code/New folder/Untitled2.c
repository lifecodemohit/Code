#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,a[3];
    for(i=0; i<3;i++){
        printf("enter %d side of triangle: ", i+1);
        scanf("%d", &a[i]);
    }

    if(a[0]==a[1] && a[1]==a[2] && a[0]==a[2]){
        printf("%d %d %d ", a[0], a[1], a[2]);
        printf("Equilateral");
    }
    else if(a[0]==a[1] || a[1]==a[2]|| a[0] == a[2]){
        printf("%d %d %d ", a[0], a[1], a[2]);
        printf("isocellos");
    }
    else{
        printf("%d %d %d ", a[0], a[1], a[2]);
        printf("scalene");
    }
    if(a[0]^2==a[1]^2 + a[2]^2 || a[1]^2==a[2]^2 + a[0]^2 || a[2]^2==a[0]^2 + a[1]^2){
        printf(", right angled");
    }
    return 0;
}
