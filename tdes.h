#include <iostream.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include "strinp.h"

typedef char table_name[30];

class Table_descriptor
 {
  private:
  table_name tname;
  int num_fields;
  int rec_size;
  int num_recs;

  public:
  Table_descriptor();
  ~Table_descriptor();

  string& get_tablename();
  int get_numfields();
  int get_recsize();
  int get_numrecs();
  void set_tablename(string);
  void set_numfields(int);
  void set_recsize(int);
  void set_numrecs(int);
  int read_in(table_name);
  int read_in1(table_name);
  void display();
  };

