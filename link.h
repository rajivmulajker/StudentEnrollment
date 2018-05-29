
//                   ----- File Link_List.h-----

#include <iostream>
#include <string.h>
#include <stdio.h>
#include "strinp.h"

//typedef long item_t;


class Node
{
private:
  //item_t item;
  string tname;
  string fldname;
  char fldtype;
  string str1;
  int offset;
  int fldsize;
  Node* next;

public:
  Node() {};
  ~Node() {};
  void set_tname(string&);
  void set_fldname(string&);
  void set_fldtype(char);
  void set_str1(string&);
  void set_offset(int);
  void set_fldsize(int);
  void set_Node(Node*);
  Node* cons(string,string,char,int,int,Node*);
  void insert(Node *&,string,string,char,int,int);
  void insert_reverse(Node *&,string,string,char,int,int);
  void data(Node*&);
  string& get_tname();
  string& get_fldname();
  char get_fldtype();
  string& get_str1();
  int get_offset();
  int get_fldsize();
  Node* get_Node();
  void read(Node *&);
  void read_reverse(Node *&);
  void display(Node*&);
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

void Node::set_str1(string& aString)
 {
  strcpy(str1,aString);
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

void Node::insert(Node *& p, string tname,string fldname,char fldtype,
                  int offset,int fldsize)
{
  if (p == NULL)
  {
    Node *temp = new Node;
    strcpy(temp->tname,tname);
    strcpy(temp->fldname,fldname);
    temp->fldtype = fldtype;
    temp->offset=offset;
    temp->fldsize=fldsize;
    temp->next = p;
    p = temp;
  }
  else
    {
    Node *temp = new Node;
    strcpy(temp->tname,tname);
    strcpy(temp->fldname,fldname);
    temp->fldtype = fldtype;
    temp->offset = offset;
    temp->fldsize = fldsize;
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
  string str,str1,str2;
  char ch;
  int offset,fldsize;

  std::cin.get();
  std::cout << "\nDO YOU WANNA READ IN ";
  getstring(str,MAXSTR);

  std::cout << "\nTABLE NAME ";
  getstring(str1,MAXSTR);
  std::cout << "\nFIELD NAME ";
  getstring(str2,MAXSTR);
  std::cout << "\nFIELD TYPE ";
  std::cin >> ch;
  std::cout << "\nOFFSET ";
  std::cin >> offset;
  std::cout << "\nFIELD SIZE ";
  std::cin >> fldsize;


  if (strcmp(str,"@@@"))
   {
     insert(p,str1,str2,ch,offset,fldsize);
     read(p);
   }
 }

void Node::read_reverse(Node *& p)
 {
  string str,str1,str2;
  char ch;
  int offset=0,fldsize=0;

  std::cin.get();
  std::cout << "\nDO YOU WANNA READ IN ";
  getstring(str,MAXSTR);

  std::cout << "\nTABLE NAME ";
  getstring(str1,MAXSTR);
  std::cout << "\nFIELD NAME ";
  getstring(str2,MAXSTR);
  std::cout << "\nFIELD TYPE ";
  std::cin >> ch;
  std::cout << "\nOFFSET ";
  std::cin >> offset;
  std::cout << "\nFIELD SIZE ";
  std::cin >> fldsize;

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

string& Node::get_str1()
 {
  return str1;
 }

int Node::get_fldsize()
 {
  return fldsize;
 }

Node* Node::get_Node()
 {
  return next;
 }

void Node::display(Node*& p)
 {
  if (p != NULL)
  {
    std::cout <<  p->tname << " ";
    std::cout <<  p->fldname << " ";
    std::cout <<  p->str1 << endl;
    display(p->next);
  }
  else
   std::cout << endl;
 }

void Node::data(Node*& p)
 {
    string str1;
    std::cin.get();

    while(p != NULL)
    {
     std::cout << p->get_fldname() << " ";
     getstring(str1,MAXSTR);
     strcpy(p->get_str1(),str1);
     p=p->get_Node();
    }
  }

/*void main()
 {
  //char choice;
  Node node;
  Node* p=NULL;
  Node* temp=NULL;
  node.read_reverse(p);
  temp=p;
  node.data(p);
  node.display(temp);
} */
