#include <string.h>
#ifndef STRINP_H
#define STRINP_H

const int MAXSTR = 30;
typedef char string[MAXSTR];
void getstring(char*,int);
void strip(char*);

void getstring(string s,int limit)
{
 char ch;
 int where = 0;

 while((ch = std::cin.get()) != '\n')
  {
   if(where < limit-1)
       s[where++] = ch;
   else
    ;  //ignore
   }
 s[where] = '\0';
 }

void strip(string s)
 {
  string temp;
  int t = 0;
 for(int i = 0; s[i] != '\0'; i++)
  {
   if(s[i] != '\r' && s[i] != '\n')
         temp[t++] = s[i];
  }
 temp[t] = '\0';
 strcpy(s,temp);
}

#endif
