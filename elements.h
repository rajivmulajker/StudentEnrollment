
#include<iostream>
#include<fstream>
#include<string.h>

#ifndef ELEMENT_H
#define ELEMENT_H

//typedef
enum boolean { false , true };
typedef char class_name[30];

class Element
{
 protected:
class_name myclass;

public:
Element();
~Element();

virtual class_name& name_of_class();

virtual void display();
virtual void key_file_out(std::ofstream&);
virtual void file_out(std::ofstream&);

};
typedef Element* ElementPtr;

#endif




