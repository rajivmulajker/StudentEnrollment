#include <stdlib.h>
#include "fdes.cpp"
#include "generset.cpp"
#include "tdes.cpp"
//#include "link.h"

class FieldDesSet:public GenericSet
{
 private:
 string str1;

 public:
 FieldDesSet(file_name);
 FieldDesSet();
 ~FieldDesSet();
 void get_set();
 void get_data(file_name,string*, string*);
 void read_in();
 void structure(file_name);
 void check(string,string,string);
 void add_size(file_name,int,file_name);
 int get_offset(int*,file_name);
 int list(file_name,int);
 int check_fldsize(file_name,int*);
 void del(file_name,string,int);
 void undel(file_name,string,int);
 virtual void add(FldPtr);
 int dump_data(int*,int,string*,file_name);
 void dir_list(file_name);
 void help_note();
 void display(char**,int);
 void file_out1(ofstream&);
 void file_in1(ifstream&);
};
typedef FieldDesSet* FDSptr;

