#include "elements.h"

#ifndef ELEMENTS_CPP
#define ELEMENTS_CPP

Element::Element()
{

 strcpy(myclass,"ELEMENT");

}

Element::~Element()
{

 ;

}

class_name& Element::name_of_class()
{

 return(myclass);

}

void Element::display()
{

 ;

}

void Element::file_out(std::ofstream& outfile)
{

 outfile << "Element " << std::endl;

}

void Element::key_file_out(std::ofstream& outFile)
{

   outFile.close();

   std::cout    << "**** Element::key_file_out() error ***** " << std::endl;

   std::cout    << "**** key_file_out() is subclass responsibility **** "

	   << std::endl;

}



#endif


