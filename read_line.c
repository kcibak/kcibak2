/*Name: Kira Cibak
Description: This is the source file that includes the read_line header file; it supplies the function definition*/

#include "read_line.h"
#include <stdio.h>
#include <ctype.h>

int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;

  str[i++] = ch;

  while ((ch = getchar()) != '\n') {

    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';

   return i;
}