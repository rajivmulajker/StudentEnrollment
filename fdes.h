#include <iomanip>
//#include <conio>
#include "elements.cpp"
#include "strinp.h"
#include "link.h"

typedef char table_name[30];
typedef char field_name[30];

class Field_descriptor:public Element
 {
  private:
  table_name tname;
  field_name fldname;
  string str1;
  char fldtype;
  int offset;
  int fldsize;

  public:
  Node* ptr;
  Node* present;
  Node node;
  Field_descriptor();
  ~Field_descriptor();

  string& get_tname();
  string& get_fldname();
  string& get_str1();
  char get_fldtype();
  int get_offset();
  int get_fldsize();

  void set_tname(string);
  void set_fldname(string);
  void set_str1(string);
  void set_fldtype(char);
  void set_offset(int);
  void set_fldsize(int);
  void read_in();
  void read_in1();
  void check_fldname(string);
  virtual void file_in(ifstream&);
  virtual void file_out(ofstream&);
  virtual void key_file_out(ofstream&);
  //void file_out1(file_name);
  };
typedef Field_descriptor* FldPtr;
