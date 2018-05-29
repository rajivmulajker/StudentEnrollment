#include "tdes.h"

Table_descriptor::Table_descriptor()
 {
   strcpy(tname,"XXXX");
   num_fields=0;
   rec_size=0;
   num_recs=0;
 }

Table_descriptor::~Table_descriptor()
 {
   ;
 }

string& Table_descriptor::get_tablename()
 {
  return tname;
 }

int Table_descriptor::get_numfields()
 {
  return num_fields;
 }

int Table_descriptor::get_recsize()
 {
  return rec_size;
 }

int Table_descriptor::get_numrecs()
 {
  return num_recs;
 }

void Table_descriptor::set_tablename(string aString)
 {
  strcpy(tname,aString);
 }

void Table_descriptor::set_numfields(int aNumfield)
 {
  num_fields = aNumfield;
 }

void Table_descriptor::set_recsize(int aRecsize)
 {
  rec_size = aRecsize;
 }

void Table_descriptor::set_numrecs(int aNumrec)
 {
  num_recs = aNumrec;
 }

int Table_descriptor::read_in1(table_name str)
 {
//  int handle=0;

//  cout << "\nEnter the table name: ";
//  getstring(tname,MAXSTR);

  strcpy(tname,str);

  while(open(tname,O_RDONLY) == -1)
     {
      perror("Error:");
      //cout << "\Enter the table name: ";
      //getstring(tname,MAXSTR);
      return 0;
      }
   return 1;
  }

int Table_descriptor::read_in(table_name str)
 {
  //int handle=0;

//  cout << "\nEnter the table name: ";
//  getstring(tname,MAXSTR);

  strcpy(tname,str);

  while(open(tname,O_RDONLY) != -1)
     {
      cout << "Error: " << tname << " already exists" << endl;
      //cout << "\Enter the table name: ";
      //getstring(tname,MAXSTR);
      return 0;
      }

  cout << "\nEnter the number of fields: ";
  cin >> num_fields;
  //cout << "\nEnter the records size: ";
  //cin >> rec_size;
  //cout << "\nEnter the number of records: ";
  //cin >> num_recs;
  return 1;
  }


void Table_descriptor::display()
 {
  cout << "Table name: "          << tname      << endl;
  cout << "Number of fields: "    << num_fields << endl;
  cout << "Size of the records: " << rec_size   << endl;
  cout << "Number of records: "   << num_recs   << endl;
 }

/*void main()
 {
  Table_descriptor tdes;
  char ch;
  //ofstream file;
  cout << "\nEnter data (y/n): ";
  cin >> ch;

  //if(file.is_open(tdes->get_table()) == 0)
  //	cout << "Error!! File is open.";

  while(ch == 'y')
  {
   cin.get();
   tdes.read_in();
   cout << "\nEnter data (y/n): ";
   cin >> ch;
  }
  tdes.display();
 }*/
