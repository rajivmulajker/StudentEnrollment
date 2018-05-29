
//                   ----- File Link_List.h-----  

#include <iostream.h>
#include <string.h>
#include <stdio.h>
#include "strinp.h"

class Node
{
private:
  //item_t item;
  string tname;
  string fldname;
  char fldtype;
  int offset;
  int fldsize;

  Node* next;
public:
  Node() {};
  ~Node() {};
  void set_tname(string&);
  void set_fldname(string&);
  void set_fldtype(char);
  void set_offset(int);
  void set_fldsize(int);
  void set_Node(Node*);
  Node* cons(string,string,char,int,int,Node*);
  void insert(Node *&,string);
  void insert_reverse(Node *&,string,string,char,int,int);
  string& get_tname();
  string& get_fldname();
  char get_fldtype();
  int get_offset();
  int get_fldsize();
  Node* get_Node();
  void read(Node *&);
  void read_reverse(Node *&);
  void display(Node*);
};

void Node::set_tname(string& aTable)
  {
   strcpy(tname,aTable);
  }

void Node::set_fldname(string& aFldname)
  {
   strcpy(fldname,aFldname);
  }

void Node::set_fldtype(char aFldtype)
  {
   fldtype = aFldtype;
  }

void Node::set_offset(int aOffset)
  {
   offset = aOffset;
  }

void Node::set_fldsize(int aFldsize)
  {
   fldsize = aFldsize;
  }

void Node::set_Node(Node* aNode)
  {
   next = aNode;
  }

Node* Node::cons(string tname,string fldname,char fldtype,int offset,
		 int fldsize,Node *p)
{
  Node *temp = new Node;
  strcpy(temp->tname,tname);
  strcpy(temp->fldname,fldname);
  temp->fldtype=fldtype;
  temp->offset=offset;
  temp->fldsize=fldsize; 
  temp->next = p;
  return temp;
}

void Node::insert(Node *& p,string fldname)
{
  if (p == NULL)
  {
    Node *temp = new Node;
    strcpy(temp->fldname,fldname);
    temp->next = p;
    p = temp;
  }
  else
    {
    Node *temp = new Node;
    strcpy(temp->fldname,fldname);
    temp->next = p;
    p = temp;
   } 
 }


void Node::insert_reverse(Node *& p, string tname,string fldname, char fldtype,
			  int offset,int fldsize)
{
 if(p == NULL)
   {
    Node *temp = new Node;
    strcpy(temp->tname,tname);
    strcpy(temp->fldname,fldname);
    temp->fldtype=fldtype;
    temp->offset=offset;
    temp->fldsize=fldsize;
    temp->next = p;
    p = temp;
   }
 else
   insert_reverse(p->next,tname,fldname,fldtype,offset,fldsize);
}

void Node::read(Node *& p)
 {
  char ch;
  int offset,fldsize;

  cin.get();
  cout << "\nDO YOU WANNA READ IN ";
  getstring(str,MAXSTR);

  cout << "\nTABLE NAME ";
  getstring(str1,MAXSTR);
  cout << "\nFIELD NAME ";
  getstring(str2,MAXSTR);
  cout << "\nFIELD TYPE ";
  cin >> ch;
  cout << "\nOFFSET ";
  cin >> offset;
  cout << "\nFIELD SIZE ";
  cin >> fldsize;


  if (strcmp(str,"@@@"))
   {
     insert(p,str2);
     read(p);
   }
 }

void Node::read_reverse(Node *& p)
 {
  string str,str1,str2;
  char ch;
  int offset=0,fldsize=0;

  cin.get();
  cout << "\nDO YOU WANNA READ IN ";
  getstring(str,MAXSTR);

  cout << "\nTABLE NAME ";
  getstring(str1,MAXSTR);
  cout << "\nFIELD NAME ";
  getstring(str2,MAXSTR);
  cout << "\nFIELD TYPE ";
  cin >> ch;
  cout << "\nOFFSET ";
  cin >> offset;
  cout << "\nFIELD SIZE ";
  cin >> fldsize;

 if (strcmp(str,"@@@"))
  {
    insert_reverse(p, str1,str2,ch,offset,fldsize);
    read_reverse(p);
  }
 }

string& Node::get_tname()
 {
  return tname;
 }

string& Node::get_fldname()
 {
  return fldname;
 }

char Node::get_fldtype()
 {
  return fldtype;
 }

int Node::get_offset()
 {
  return offset;
 }

int Node::get_fldsize()
 {
  return fldsize;
 }

Node* Node::get_Node()
 {
  return next;
 }

void Node::display(Node *p)
 {
  if (p != NULL)
  {
    cout <<  p->tname << " ";
    cout <<  p->fldname << " ";
    cout <<  p->fldtype << " ";
    cout <<  p->offset  << " ";
    cout <<  p->fldsize << endl;
    display(p->next);
  }
  else
   cout << endl;
 }

/*void main()
 {
  char choice;

  cout << "Do you wanna enter reverse or at head (r/h) ";
  cin >> choice;

while (choice == 'h' || choice == 'r')
 {
  if(choice == 'h')
   {
   Node node;
   Node* p = NULL;
   node.read(p);
   node.display(p);
   }

  else if(choice == 'r')
   {
    Node node;
    Node* p = NULL;
    node.read_reverse(p);
    node.display(p);
  }
  cout << "Do you wanna insert reverse or at head (r/h) ";
  cin >> choice;
 }
}
  */













