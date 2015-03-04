#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct students{
    int rollnum;
    char name[20];
    char dep[20];
    char course[20];
    int year;
};
void disp(struct students *student){
    printf("Name of the student: %c\n", student->name);
    printf("Roll Number of the student: %d\n", student->rollnum);
    printf("Department of the student: %c\n", student->dep);
    printf("course of the student: %c\n", student->course);
    printf("Year in which the student joined: %d\n", student->year);
    printf("\n");
    }
void main(){
    int n = 1, i =0;
    struct students student[5];
    for(i=0; i<n; i++){
        printf("Enter rollnumber of %d student: \n", i);
        scanf("%d", &student[i].rollnum);
        printf("Enter name of %d student: \n", i);
        scanf("%s",&student[i].name);
        printf("Enter department of %d student: \n", i);
        scanf("%s", &student[i].dep);
        printf("Enter course of %d student: \n", i);
        scanf("%s", &student[i].course);
        printf("Enter year of %d student: \n", i);
        scanf("%d", &student[i].year);
    }
    int yea;
    int roll;
    printf("Enter the year to look for: ");
    scanf("%d", &yea);
    for(i=0; i<5; i++){
        if(student[i].year==yea){
            disp(&student[i]);
        }
    }
    printf("Enter the roll number to look for: ");
    scanf("%d", &roll);
    for(i=0; i<5; i++){
        if(student[i].rollnum==roll){
            disp(&student[i]);
        }
    }
}