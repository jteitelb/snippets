#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 1023

int main()
{
   char str[LEN + 1];
   printf("enter sentence:\n");
   fgets(str, LEN, stdin);
    
   for (int i= 0 ; i < strlen(str) ; i++)
   {
        char c = toupper(str[i]); 
        if (isalpha(c))
        {
            c = c - 'A';
            printf("%d ", c); 
        }
        else if (c == ' ')
        {
            printf("\n");
        }
   }
   printf("\n");
}
