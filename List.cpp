//Dennis Huang
//dlh4fx
//January 25, 2015
//List.cpp


#include "List.h"

using namespace std;

 List :: List() { //constructor
   head = new ListNode();
   tail = new ListNode();
   head -> previous = NULL;
   tail -> next = NULL;
   head -> next = tail;
   tail -> previous = head;
  int count = 0;
}

List :: ~List() { //destructor
  //  delete head;
  //delete tail;
  

}



List::List(const List& source) {      // Copy Constructor
    head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

List& List::operator=(const List& source) { //Equals operator
    if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List :: isEmpty() const { //returns true if list is empty
  if (count == 0) {
    return true;
  }
  else {
    return false; 
  }
}

void List ::  makeEmpty () { //removes all items from the list
  
  ListItr Itr (head); 
 

  for (int i = 0; i < count; i++) {
    if (!Itr.isPastEnd()) {
        Itr.moveForward();
        delete Itr.current;    

    }
  }
  count = 0;
}

ListItr List :: first() { //returns an iterator that points to the first position
  ListItr y (head);
  return y.current -> next;

}

ListItr List :: last() { // returns an iterator that points to the last position

  ListItr y (tail);
  return y.current -> previous;

}

void List :: insertAfter(int x, ListItr position) { //insert x after current position

  ListNode * node = new ListNode();
  node -> value = x;
  node -> previous = position.current;
  node -> next = position.current -> next;
  position.current -> next = node;
  node -> next -> previous = node;
  count++;
}

void List :: insertBefore (int x, ListItr position) { //insert x before current position

  ListNode * node = new ListNode();
  node -> value = x;
  node -> next = position.current;
  node -> previous = position.current -> previous;
  position.current -> previous = node;
  node -> previous -> next = node;
  count++;

}

void List :: insertAtTail(int x) { //insert x at tail of list
  ListNode * node = new ListNode();
  node -> value = x;
  node -> previous = tail -> previous;
  node -> next = tail;
  tail -> previous -> next = node;
  tail -> previous = node;

  count++;

}

void List :: remove(int x) { //remove x from list
  ListItr y = find(x);
  ListNode * pointer = y.current -> previous;
  y.current -> previous -> next = y.current -> next;
  y.moveForward();
  delete y.current -> previous;
  y.current -> previous = pointer;

  count--;
}

ListItr List :: find(int x) { //return iterator that points to the current position of x
  ListItr y (head);
  while(!y.isPastEnd()) {
    if (y.current -> value == x) {
      return y;
    }
    else {
      y.moveForward();
    }
  }
  return NULL;
}

int List :: size() const { //returns number of items in list
  return count;
};

void printList(List& theList, bool forward) {
  if (forward == true) {
    ListItr y = theList.first();
    for (int i = 0; i < theList.size(); i++) {
      cout << y.retrieve() << endl;
      y.moveForward();
    }
  }
  else {
    ListItr x = theList.last();
    for (int i = 0; i < theList.size(); i++) {
      cout << x.retrieve() << endl;
      x.moveBackward();
    }
  }
}
