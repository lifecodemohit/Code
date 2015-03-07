#include<stdio.h>
#include<string.h>
void main()
{
char* name[] = {"varun", "Karan"};
char b = name[1][0];
char c = name[0][0];
if(b<c)
    printf("%s", name[1]);
else
printf("%s",name[0]);
return 0;
}
