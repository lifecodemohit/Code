#include<stdio.h>
#include<stdlib.h>
int fac(int a){
    if(a==1 || a==0){
        return 1;
    }
    else{
        return a*fac(a-1);
    }
}
int main(){
    float j,a[7], sum=1;
    int i,k;

    for(i=0; i<7; i++){
        k = fac(i+1);
        j = (i+1.0)/k;

        a[i] = j;
//        printf("%f %d\n", a[i], k);
    }
    for(i=1; i<8; i++){
        printf("%f ", sum);
        sum+=a[i];
    }
    printf("%f", sum);
}
