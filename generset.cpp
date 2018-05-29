#include "generset.h"





GenericSet::GenericSet()

{

 size = 0;

 size1= 0;

 error = false;

 current = -1;

}



GenericSet::~GenericSet()

{

/*for(int i = 0; i < size; i++)

   delete s[i]*/

   ;

}



boolean GenericSet::is_member_of(ElementPtr eptr)

{

boolean found = false;

int i=0;

while(!found && (i < size))

 {

  if(eptr == s[i])

   {

   found = true;

   }

  i++;

 }

return found;

}



boolean GenericSet::in_error_state()

{

 return(error);

}



int GenericSet::cardinality()

{

 return(size);

}



boolean GenericSet::is_full()

{

return(boolean(size == CAPACITY));

}



boolean GenericSet::is_empty()

{

 return(boolean(size == 0));

}



ElementPtr GenericSet::get_first()

{

 if(size > 0)

  {

   current = 0;

   return(s[0]);

  }

else

  return(NULL);

}



ElementPtr GenericSet::operator ++()

{

 if(current < 0 || current == size-1)

  return(NULL);

 else

  return(s[++current]);

 }



void GenericSet::add(ElementPtr eptr)

 {

   boolean duplicate = false,

           full = false;

   int i = 0;

   if(this -> is_full())

    {

     error = true;

     full = true;

    }

   while(!duplicate && (i < size))

   {

    if(s[i] == eptr)

     {

      error = true;

      full = true;

     }

    i++;

   } 

 }



void GenericSet::del(ElementPtr eptr,char key)

 {

  boolean duplicate = false, 

          full = false;



  int i = 0;

  while(!duplicate && (i < size))

   {

    if(s[i] == eptr)

     {

      error = true;

      full = true;

     }

    i++;

   } 

 }



  

void GenericSet::reset_error()

 {

  error = false;

 }



void GenericSet::clear()

 {

  for(int i = 0; i < size; i++)

  {

   delete s[i];

  }

 size = 0;

 current = -1;

 error = false;

 }



void GenericSet::display()

 {

  for(int i = 0; i < size; i++)

     s[i] -> display();

 }



void GenericSet::file_out()

{

   ofstream outFile(fname, ios::out);

//   outFile << size << endl;

   for (int i = 0; i < size; i++)

   {

     //while(s[i] == NULL)

      s[i] -> file_out(outFile);

   }

   outFile.close();

 //cout << "Filing Completed";

}





void GenericSet::file_out(file_name aFileName)

 {

  ofstream outFile(aFileName, ios::out);

  for(int i =0; i < size; i++)

    s[i] -> file_out(outFile);

  outFile.close();

 }























