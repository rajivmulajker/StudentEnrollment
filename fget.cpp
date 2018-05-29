#include <iostream.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include "strinp.h"

int main(void)
{
   FILE *stream;
   //char string[]  = "book no\n";
   //char string1[] = "book name\n";
   //char string2[] = "author\n";
   int i = 0;
   string str1;
   string str2;
   string str3;
   string str4;
   char ch;

   /* open a file for update */
   stream = fopen("student", "r+");
   /*cout << "\nEnter the string: ";
   getstring(str1,MAXSTR);
   cout << "\n> ";
   cin >> choice;

   while(choice == 'y')
   {
   /* write a string into the file */
   /*fwrite(string, strlen(string), 1, stream);
   fwrite("\n",1,1,stream);
   fwrite(string1,strlen(string1),1,stream);
   fwrite("\n",1,1,stream);
   fwrite(string2,strlen(string2),1,stream);
   /* seek to the beginning of the file */
   //cout << "\n> ";
   //getstring(str1,MAXSTR);
   //cin >> choice;
   //}

   fseek(stream, 0, SEEK_SET);

  // do
  // {
      /* read a char from the file */
    while(ch != EOF)
      {
      ch = fgetc(stream);
      str1[i] = ch;
      i++;
      /* display the character */
      putch(ch);
      if(ch == '\n')
	{
	  getstring(str2,MAXSTR);
	  continue;
	}
     } //while (ch != EOF);

   fclose(stream);
   cout << str1;
   int j=0;
   for(i=0; i< strlen(str1); i++)
    {
     str2[j] = str1[i];
     if(str1[i] == '\n')
       if(str1[i+1] == '\n')
	{
	 j=j+2;
	 break;
	}
      j++;
    }
    int k=j;
    j=0;
   for(i=k; i<strlen(str1); i++)
     {
       str3[j] = str1[i];
       if(str1[i] == '\n')
	if(str1[i+1] == '\n')
	 {
	  j=j+2;
	  break;
	 }
     j++;
    }
    k=j;
    j=0;
   for(i=k; i<strlen(str1); i++)
     {
       str4[j] = str1[i];
       if(str1[i] == '\n')
	if(str1[i+1] == '\n')
	 {
	  j=j+2;
	  break;
	 }
     j++;
    }
   return 0;
}



