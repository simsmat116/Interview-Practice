#include <set>
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

Node * removeDuplicate(Node * n){
  if(n == nullptr){
    return n;
  }

  set<int> seenData;
  seenData.insert(n->data);
  Node * head = n;
  Node * prev = n;
  n = n->next;
  while(n != nullptr){
    if(seenData.find(n->data) != seenData.end()){
      prev->next = n->next;
    }
    else{
      seenData.insert(n->data);
      prev = n;
    }

    n = n->next;

  }

  return head;
}

void TestOne(){
  Node * head = new Node(4);
  head->appendToTail(5);
  head->appendToTail(4);
  head->appendToTail(3);
  head->appendToTail(4);
  head->appendToTail(5);

  Node * correct = new Node(4);
  correct->appendToTail(5);
  correct->appendToTail(3);

  Node * iter = removeDuplicate(head);
  while(iter != nullptr){
    assert(iter->data == correct->data);
    correct = correct->next;
    iter = iter->next;
  }

}

void TestTwo(){
  Node * head = nullptr;
  assert(removeDuplicate(head) == nullptr);
}

int main(){
  TestOne();
  TestTwo();
}
