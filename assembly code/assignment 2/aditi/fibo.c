#include<stdio.h>
int main()
{
    int first=0,second=1,next,c=0;
    printf("%d\n%d\n",first,second);
    for(c=2;c<20;c++)
    {
        next=first+second;
        first=second;
        second=next;

        printf("%d\n",next);
    }
    return 0;
}
