#include<stdio.h>
#include<stdlib.h>


typedef struct
{
    int id_number;
    int age;
    float salary;
} database;

int main()
{
    database employee1;
    employee1.id_number = 1;
    employee1.age = 24;
    employee1.salary = 18.69;

    database employee2;
    employee2.id_number = 2;
    employee2.age = 25;
    employee2.salary = 15.66;


    float details1[]= {employee1.id_number, employee1.age, employee1.salary};
    for(int i=0; i<3; i++)
    {
        printf("%.2f, ", details1[i]);
    }


    return 0;
}
