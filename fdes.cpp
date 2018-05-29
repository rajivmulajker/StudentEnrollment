#include "fdes.h"
#include <ctype.h>

Field_descriptor::Field_descriptor()
 {
  Node node;
  //strcpy(myclass,"FIELD_DESCRIPTROR ");
  this -> read_in();
  //this -> read_in1();
 }

Field_descriptor::~Field_descriptor()
 {
  ;
 }

string& Field_descriptor::get_tname()
 {
  return tname;
 }

string& Field_descriptor::get_fldname()
 {
  return fldname;
 }

char Field_descriptor::get_fldtype()
 {
  return fldtype;
 }

int Field_descriptor::get_offset()
 {
  return offset;
 }

int Field_descriptor::get_fldsize()
 {
  return fldsize;
 }

void Field_descriptor::set_tname(string aTname)
 {
  strcpy(tname,aTname);
 }

void Field_descriptor::set_fldname(string aFldname)
 {
  strcpy(fldname,aFldname);
 }

void Field_descriptor::set_fldtype(char aFldtype)
 {
  fldtype = aFldtype;
 }

void Field_descriptor::set_offset(int aOffset)
 {
  offset = aOffset;
 }

void Field_descriptor::set_fldsize(int aFldsize)
 {
  fldsize = aFldsize;
 }

void Field_descriptor::read_in()
 {
  //Node node;
  //Node* nptr;
  //cin.get();
  //cout << "Table name ";
  //getstring(tname,MAXSTR);

  cout << endl << "Field name       ";
  getstring(fldname,MAXSTR);
  check_fldname(fldname);
  //node.insert(ptr,fldname);
  //ptr=ptr->next;

  cout << endl << "Field type       ";
  cin >> fldtype;
  fldtype=toupper(fldtype);
  while(fldtype != 'C' && fldtype != 'N')
   {
    cout << "\nWrong Choice!!! Enter either c or n)";
    cin >> fldtype;
    fldtype=toupper(fldtype);
   }

  //cout << endl << "Offset ";
  //cin >> offset;

  cout << endl << "Field size       ";
  cin >> fldsize;
  }

void Field_descriptor::read_in1()
 {
  Node node;
  Node* p=NULL;
  Node* temp=NULL;
  node.read_reverse(p);
  temp=p;
  node.data(p);
  node.display(temp);
 }

void Field_descriptor::check_fldname(string fld)
 {
   int length=0;
   string str;
   length=strlen(fld);
   for(int i=0; i<=16; i++)
    {
     str[i]=fld[i];
     if(i==15)
      {
       cout << "\nError!!String is of length 16 only.Enter the string again "<< endl;
       getstring(fld,MAXSTR);
       length=strlen(fld);
       i=-1;
       }
     if(i==length)
      {
       str[i]='\0';
       break;
      }
    }
  strcpy(get_fldname(),str);
 }

void Field_descriptor::file_in(ifstream& inFile)
 {
  //inFile.getline(tname,MAXSTR);
  //strip(tname);
  inFile.getline(fldname,MAXSTR);
  strip(fldname);
  inFile >> fldtype;
  inFile.get();   // new line char
  //inFile >> offset;
  //inFile.get();
  inFile >> fldsize;
  inFile.get();
 }

void Field_descriptor::file_out(ofstream& outFile)
 {
  //outFile << myclass << endl;
  //outFile << tname   << endl;
  outFile << "FieldName ";
  outFile << fldname << endl;
  outFile << "FieldType ";
  outFile << fldtype << endl;
  //outFile << offset  << endl;
  outFile << "FieldSize ";
  outFile << fldsize << endl;
 }

/*void Field_descriptor::file_out1(file_name aFilename)
 {
  FldPtr fptr;
  fstream file;
  file.open(aFilename,ios::app | ios::out | ios::in);
  file.write(myclass,sizeof(myclass));
  for(int i=0; i<=size; i++)
  {
  fptr = FldPtr(s[i]);
  file.write(fptr->get_tname(),sizeof(fptr->get_tname()));
  file.write(fptr->get_fldname(),sizeof(fptr->get_fldname()));
  //file.write(fldtype,sizeof(fldtype));
  //file.write(offset,sizeof(offset));
  //file.write(fldsize,sizeof(fldsize));
  }
  file.seekg(0);
  file.read(aFilename,sizeof aFilename);
 }*/

void Field_descriptor::key_file_out(ofstream& outFile)
 {
  outFile << tname << endl;
 }


/*void main()
 {
//  Node* temp=NULL;
//  Node* present=NULL;
  Field_descriptor f;
  char choice;

  present=temp;
  cout << "\nDo you wanna read in ";
  cin >> choice;

  while(choice != 'n')
  {
    cout << endl;
    f.read_in();
    cout << "\nDo you wanna read in ";
    cin >> choice;
  }
 }*/















