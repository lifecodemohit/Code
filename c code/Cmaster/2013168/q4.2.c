#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int vow()
{

}
int main(int argc, char* argv[])
{
    int c;
    char* str;
    FILE *file;
    file = fopen("q1.c", "r");
    if (file) {
        while ((c = getc(file)) != EOF)
        {

        }
        fclose(file);
    }
    else
        printf("Invalid file.\n");
    return 0;
}
