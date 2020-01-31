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

int listLength(Node * node){
  int length = 0;
  while(node != nullptr){
    ++length;
    node = node->next;
  }
  return length;
}

Node * listIntersection(Node * l1, Node * l2){
  if(l1 == nullptr || l2 == nullptr){
    return nullptr;
  }

  int length1 = listLength(l1);
  int length2 = listLength(l2);
  int diff = length1 - length2;
  Node * large = (diff >= 0) ? l1 : l2;
  Node * small = (diff >= 0) ? l2 : l1;

  for(int i = 0; i < diff; ++i){
    large = large->next;
  }

  while(large != nullptr){
    if(large == small){
      return large;
    }
    large = large->next;
    small = small->next;
  }
  return nullptr;
}

void TestOne(){
  Node * intersection = new Node(4);
  intersection->appendToTail(3);
  intersection->appendToTail(3);

  Node * l1 = new Node(2);
  Node * l2 = new Node(4);
  l1->next = intersection;
  l2->next = intersection;

  assert(intersection == listIntersection(l1, l2));

}


int main(){
  TestOne();
}
