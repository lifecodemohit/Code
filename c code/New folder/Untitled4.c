#include<stdio.h>
#include<stdlib.h>
void main(){
    int i, j,k;
    int a[4][4];
    for(i=0; i<4; i++){
        for(j=0; j<4;j++){
            scanf("%d", &k);
            a[i][j] = k;
        }
        printf("\n");
    }
    for(i=0; i<4; i++){
        for(j=0; j<4;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

}
