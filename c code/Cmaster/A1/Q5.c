#include<stdio.h>
int count(double arr[], int val, double dval);
void main()
{
    int val;
    double dval;
    scanf("%i", &val);
    scanf("%lf", &dval);
    double arr[val];
    int i;
    for(i = 0; i< val; i++)
        scanf("%lf", &arr[i]);
    int x;
    x = count(arr, val, dval);
    printf("%d", x);
}
int count(double arr[], int val, double dval)
{
    int c = 0;
    int i;
    for(i=0; i<val; i++)
    {
        if(arr[i]>dval)
            c++;
    }
    return c;
}
