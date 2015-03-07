//all even numbers b/w 2 and 50
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i = 2;
    do
    {
        printf("%i\n",i);
        i+=2;
    }
    while(i < 50);
    return 0;
}
