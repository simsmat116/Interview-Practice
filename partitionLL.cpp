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

Node * partitionLL(Node * head, int partVal){
  if(head == nullptr){
    return nullptr;
  }

  Node * beforePart = head;
  Node * afterPart = head;

  while(head != nullptr){
    Node * nextNode = head->next;
    if(head->data < partVal){
      head->next = beforePart;
      beforePart = head;
    }
    else{
      afterPart->next = head;
      afterPart = head;
    }
    head = nextNode;
  }
  afterPart->next = nullptr;

  return beforePart;
}

void TestOne(){
  Node * list = new Node(3);
  list->appendToTail(5);
  list->appendToTail(8);
  list->appendToTail(5);
  list->appendToTail(10);
  list->appendToTail(2);
  list->appendToTail(1);
  list = partitionLL(list, 5);

  while(list != nullptr){
    cout << list->data << " -> ";
    list = list->next;
  }
}



int main(){
  TestOne();
}
