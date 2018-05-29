#include "string.h"
#include "var_cons.h"
#include "boolean.h"
#ifndef filedes_h
#define filedes_h

class file_descriptor
 {
 protected :
   file_name fname;
   int num_fields;
   int lrec_size;
   int num_lrecs;
 public:
   file_descriptor();
   file_descriptor(string s);
   ~file_descriptor();
   boolean is_equal(string s);
   char* get_file_name();
   int get_num_fields();
   int get_lrec_size();
   int get_num_lrecs();
   void set_file_name(char* str);
   void set_num_fields(int size);
   void set_lrec_size(int size);
   void set_num_lrecs(int size);
   void file_in(FILE* fp);
   };
#endif