//Dennis Huang
//dlh4fx
//January 25, 2015
//ListItr.cpp



#include "ListItr.h"

using namespace std;

ListItr :: ListItr() {
  current = NULL;
}

ListItr :: ListItr(ListNode* theNode) {
  current = theNode;
}

bool ListItr :: isPastEnd() const { //return true if iterator is pointing past end position

  
  if (current->next == NULL) {
    return true;
  }
  else {
    return false;
  }

}

bool ListItr :: isPastBeginning() const { //return true if iterator is pointing before first position in list

 
  if (current->previous == NULL) {
    return true;
  }
  else {
    return false;
  }
}

void ListItr :: moveForward() { //moves pointer to next position in the list
 
  if (!isPastEnd()) {
    current = current -> next;
  }
}

void ListItr :: moveBackward() { //moves pointer to previous position in the list
 
  if (!isPastBeginning()) {
    current = current -> previous;
  }

}

int ListItr :: retrieve() const { //returns value of item in current pointer of the list
  int x = current -> value;
  return x;

}

