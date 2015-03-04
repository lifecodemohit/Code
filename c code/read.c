#include <stdio.h>
#include <stdlib.h>

int main (void)
{
   static const char filename[] = "file.txt";
   FILE *file = fopen(filename, "r");
   if ( file != NULL )
   {
      int ch, word = 0;
      while ( (ch = fgetc(file)) != EOF )
      {
         if ( isspace(ch) || ispunct(ch) )
         {
            if ( word )
            {
               word = 0;
               putchar('\n');
            }
         }
         else
         {
            word = 1;
            putchar(ch);
         }
      }
      fclose(file);
   }
   return 0;
}
