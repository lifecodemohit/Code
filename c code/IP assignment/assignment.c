// Initial File Name: frecord.txt
// Output File NameL finalfrecord.txt 
//ajksfn alkdfn as fn
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct record{
    int roll_no;
    char name[50];
    int marks;
};
void swap(struct record *one, struct record *two){
    struct record temp;
    temp = *one;
    *one = *two;
    *two = temp;
}
int comproll(int one, int two){
    int c=0;
    if(one > two){
        c = 1;
    }
    return c;
}
int compname(char one[50], char two[50]){
    int c, i=0;
    int flag=0;
    int z = strcmp(one, two);
    if(z==0){
        flag = 1;
        c = 2;
        }
    while(flag==0){
        int a = one[i];
        int b = two[i];
        if(a>65&&a<90){
            a+=32;}
        if(b>65&&b<90){
            b+=32;}
        if( (a>=97&&a<=122)&&(b>=97 && b<=122)){
            if(a==b){
                i++;
                flag = 0;}
            else if(a<b){
                c = 0;
                flag=1;
            }
            else if(a>b){
                c = 1;
                flag=1;
            }
        }
    }
    return c;
}
void main(){
    FILE *fp;
    fp = fopen( "frecord.txt", "r");
    int i,n;//number of records in the file
    char c;
    fscanf(fp, "%d", &n);
    struct record recordof[n];
    printf("\n\nNumber of records: %d\n\n", n);
    for(i=0; i<n; i++){
        fscanf(fp, "%d, %[^,], %d", &recordof[i].roll_no ,&recordof[i].name, &recordof[i].marks);
    }
    fclose(fp);
    printf("Initial records in 'frecord.txt'\n");
    for(i=0; i<n; i++){
        printf("%d %s %d\n", recordof[i].roll_no, recordof[i].name, recordof[i].marks);
    }
    int j;
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            int x,y;
            x = compname(recordof[i].name, recordof[j].name);
            if(x==1){
                swap(&recordof[i], &recordof[j]);
            }
            else if(x==2){
                y=comproll(recordof[i].roll_no, recordof[j].roll_no);
                if(y==1){
                    swap(&recordof[i], &recordof[j]);
                }
            }
        }
    }    
    printf("\n\n");
/*
    for(i=0; i<n; i++){
        char *abc;
        abc = strtok(recordof[i].name, ",");
        strcpy(recordof[i].name, abc);
    }
*/    
    FILE *fpp;
    fpp = fopen("finalfrecord.txt", "w");
    for(i=0; i<n; i++){
        fprintf(fpp, "%d %s %d\n", recordof[i].roll_no, recordof[i].name, recordof[i].marks);
    }
    fclose(fpp);
    printf("Final Records in file 'finalfrecord.txt' \n\n");
    for(i=0; i<n; i++){
        printf("%d %s %d\n", recordof[i].roll_no, recordof[i].name, recordof[i].marks);
    }
    printf("\n\n");
}
    