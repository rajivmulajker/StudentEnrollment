
#include "elements.cpp"
typedef char file_name[30];
const int CAPACITY = 100;

class GenericSet
{
 protected:
 ElementPtr s[CAPACITY];
 ElementPtr s2[CAPACITY];
 int size, size1,current;
 boolean error;
 file_name fname;

 public:
 GenericSet();
 ~GenericSet();

 boolean is_member_of(ElementPtr);
 boolean in_error_state();
 int cardinality();
 boolean is_full();
 boolean is_empty();

 ElementPtr get_first();
 ElementPtr operator ++();

 virtual void add(ElementPtr);
 virtual void del(ElementPtr,char);

 void reset_error();
 void clear();

 virtual void display();
 virtual void file_out();
 virtual void file_out(file_name);
};

















