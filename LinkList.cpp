#include <iostream>
#include <stdio.h>

typedef int item_t;

class LinkList
 {
  private:
  item_t item;
  LinkList *next;
  public:
  void set_item(item_t);
  item_t get_item();
  void insert(LinkList *&, item_t);
  void display(LinkList*);
 };

void LinkList::set_item(item_t aItem)
  {
   item = aItem;
  }

item_t LinkList::get_item()
  {
   return item;
  }

/*Node* cons(item_t item, Node* p)
 {
  Node* temp = new Node;
  temp->next = p;
  temp
*/

void LinkList::insert(LinkList *& p, item_t item)
 {
  if(p == NULL)
   {
    LinkList* temp = new LinkList;
    temp->item = item;
    temp->next = p;
    p = temp;
   }
  else
    insert(p->next,item);
 }

/*void read(Node *& p)
 {
  item_t item;
  cin >> item;
  if(item != 0)
   {
    insert(p,item);
    read(p);
   }
 }*/

void LinkList::display(LinkList* p)
 {
  if(p != NULL)
   {
    std::cout << p-> item << " ";
    display(p->next);
   }
 }

int main()
 {
  LinkList ll;
  LinkList* p1 = NULL;
  item_t item;
  //read(p1);
  std::cout << "\n> ";
  std::cin >> item;

  while(item != 0)
  {
   ll.insert(p1,item);
   std::cout << "\n> ";
   std::cin >> item;
  }

  std::cout << "The numbers are ";
  ll.display(p1);

  return 0;
 }
