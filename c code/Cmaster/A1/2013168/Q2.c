#include<stdio.h>
#include<string.h>
int correctName(char *names[]);
void printSortedNames(char *names[]);
void main()
{
    char *names[4] = {"Nistha","Anilshar","Priyanka","Nidhi"};
    correctName(names);
    printSortedNames(names);
}
int correctName(char *names[])
{ // insert your code here
    names[1] = "Anil";
}
void printSortedNames(char* names[])
{
    //insert your code here
    int j=0;
    while(j<4)
    {
        char* min = "z";
        int m;
        int i;
        for(i=0;i<4;i++)
            {
                char a = names[i][0];
                char b = min[0];
                if(a<b)
                {
                    min = names[i];
                    m = i;
                }
            }
        printf("%s ", min);
        names[m] = "z";
        j++;
    }
}
