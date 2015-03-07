#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num, ch, top, n, gmin;

    printf("Enter the size of array: \n");
    scanf("%i", &n);
    int array[n] ;
    for(int i =0; i<n; i++)
        array[i] = NULL;
    printf("1 - Push\n");
    printf("2 - Pop\n");
    printf("3 - Top\n");
    printf("4 - IsEmpty\n");
    printf("5 - Exit\n");
    printf("6 - Dipslay\n");
    printf("7 - GetMin\n");
    printf("8 - Empty stack\n");



    while (1)
    {
        printf("Enter choice : \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &num);
            for(int i=n; i>0; i--)
            {
                array[i] = array[i-1];
            }
            array[0] = num;
            break;
        case 2:
            for(int i=0; i<n; i++)
            {
                array[i] = array[i+1];
            }
            break;
        case 3:
            if (array[0] == NULL)
                printf("No elements in stack\n");
            else
            {
                top = array[0];
                printf("Top element : %d\n", top);
            }
            break;
        case 4:
            if (array[0] == NULL)
                printf("No elements in stack\n");
            else
            {
                printf("It is not empty.\n");
            }
            break;
        case 5:
            exit(0);
        case 6:
            printf("The array is: \n");
            for(int i=0; i<n; i++)
            {
                printf("%i ",array[i]);
            }
            printf("\n");
            break;

        case 7:
            printf("The smallest element of the array: \n");
            gmin = array[0];
            for(int i = 0; i<n; i++)
            {
                if (array[i]<gmin)
                    gmin = array[i];
            }
            printf("%i\n", gmin);
            break;
        case 8:
            for(int i=0; i<n; i++)
            {
                array[i] = NULL;
            }
            break;
        default :
            printf(" Wrong choice, Please enter correct choice  \n");
            break;
        }
    }
}










