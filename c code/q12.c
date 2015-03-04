#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    char name[20];
    int marks;
    int roll;

}stud;

int main()
{
    int n;
    printf("number of students: \n");
    scanf("%i", &n);
    stud abc[n+1];
    for (int i = 0; i<n; i++)
    {

        printf("name of student %i: ", i+1);
        scanf("%s", &abc[i].name);
        printf("Marks: ");
        scanf("%i", &abc[i].marks);
        printf("roll number: ");
        scanf("%i", &abc[i].roll);
        //printf("name: %s\nmarks: %i\nroll no.: %i\n", abc[i].name, abc[i].marks, abc[i].roll);
    }
    int high = abc[0].marks;
    for (int i = 0; i<n; i++)
    {
        if (abc[i].marks > high)
        {
            high = abc[i].marks;
        }
    }
    for (int i = 0; i<n; i++)
    {
        if (abc[i].marks == high)
        {
            printf("The student having highest marks is %s with %i marks.\n", abc[i].name, high);
        }
    }
    return 0;
}
