#include <string.h>
#include <stdio.h>
#include <iostream.h>
#include <stdlib.h>
#include "var_cons.h"
#include "filedes.h"
#include "string.h"

#ifndef filedes_cpp
#define filedes_cpp

char* file_descriptor::get_file_name()
  {
  return fname;
  }

file_descriptor::file_descriptor(string s)
 {
 num_fields=0;
 lrec_size=0;
 num_lrecs=0;
 strcpy(fname,s.get_str());
 }
file_descriptor::file_descriptor()
 {
 num_fields=0;
 lrec_size=0;
 num_lrecs=0;
 }
file_descriptor:: ~file_descriptor()
 {
 }


boolean file_descriptor::is_equal(string s)
 {
 if (s==fname)
    return true;
 else
    return false;
 }
void file_descriptor::set_file_name(char* str)
 {
 strcpy(fname,str);
 }
int file_descriptor::get_num_fields()
   {
   return num_fields;
   }


int file_descriptor::get_lrec_size()
   {
   return lrec_size;
   }

int file_descriptor::get_num_lrecs()
  {
  return num_lrecs;
  }


void file_descriptor::set_lrec_size(int size)
  {
  lrec_size=size;
  }


void file_descriptor::set_num_lrecs(int num)
  {
  num_lrecs=num;
  }
void file_descriptor::set_num_fields(int num)
 {
 num_fields=num;
 }
void file_descriptor::file_in(FILE* fp)
 {
 fread(this,sizeof(*this),1,fp);
 }
#endif
