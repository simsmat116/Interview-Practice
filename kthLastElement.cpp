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

Node * kthLastElement(Node * head, int k){
  if(head == nullptr){
    return head;
  }
  Node * runner1 = head;
  Node * runner2 = head;

  // This makes the assumption that k is less than the size of LL
  for(int i = 0; i < k; ++i){
    runner2 = runner2->next;
  }

  while(runner2 != nullptr){
    runner1 = runner1->next;
    runner2 = runner2->next;
  }

  return runner1;
}

void TestOne(){
  Node * head = new Node(4);
  head->appendToTail(10);
  head->appendToTail(3);
  head->appendToTail(2);
  head->appendToTail(9);
  head->appendToTail(5);

  assert(kthLastElement(head, 6)->data == 4);
  assert(kthLastElement(head, 1)->data == 5);
  assert(kthLastElement(head, 3)->data == 2);

  head = nullptr;
  assert(kthLastElement(head, 1) == nullptr);
}

int main(){
  TestOne();
}
