#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name;
    printf("Enter a character: ");
    scanf("%c", &name);
    switch (name)
    {
        case 'V' :
        printf("Permission granted");
        break;
    default:
        printf("invalid user");
        break;
}
    return 0;
}
