#include <iostream>

using namespace std;

class Node {
public:
  Node(int d){
    next = nullptr;
    data = d;
  }

  void appendToTail(int d){
    Node * end = new Node(d);
    Node * n = this;
    while(n->next != nullptr){
      n = n->next;
    }
    n->next = end;
  }

  Node * next;
  int data;
};

void deleteMiddle(Node * n){
  if(n == nullptr){
    return;
  }

  while(n->next != nullptr){
    // Shift the data value to the left
    n->data = n->next->data;
    // Set node next to nullptr for second to last element
    if(n->next->next == nullptr){
      n->next = nullptr;
    }
  }
}

void TestOne(){
  Node * list = new Node(4);
  list->appendToTail(2);
  list->appendToTail(3);
  list->appendToTail(2);
  list->appendToTail(5);
  Node * temp = list;

  for(int i = 0; i < 3; ++i){
    temp = temp->next;
  }

  deleteMiddle(temp);

  Node * correct = new Node(4);
  correct->appendToTail(2);
  correct->appendToTail(3);
  correct->appendToTail(5);

  while(correct != nullptr){
    assert(correct->data == list->data);
    correct = correct->next;
    list = list->next;
  }

}

int main(){
  TestOne();
}
