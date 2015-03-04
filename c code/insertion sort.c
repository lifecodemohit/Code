#include <stdio.h>

int main()
{
    int i, n, t, c, array[100];
    printf("Number of digits: \n");
    scanf("%i", &n);
    printf("Enter %i digits: \n", n);
    for(i=0; i<n; i++)
    {
        scanf("%i", &array[i]);
    }
    for (i = 1; i<n; i++)
    {
        c = i ;
        while(c>0 && array[c]<array[c-1])
        {
            t = array[c];
            array[c] = array[c-1];
            array[c-1] = t;
            c--;
        }
    }

    printf("The sorted array is: \n");
    for(i = 0; i<n; i++)
    {
        printf("%i\n", array[i]);
    }
    return 0;
}
