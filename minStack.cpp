#include <iostream>

using namespace std;

class MinStack{
public:
  class StackNode{
  public:
    StackNode(int value, StackNode * min){
      val = value;
      prevMin = min;
      next = nullptr;
    }

    int val;
    StackNode * next;
    StackNode * prevMin;
  };

  MinStack(){
    head = nullptr;
    currMin = nullptr;
  }

  void push(int value){
    StackNode * newVal = new StackNode(value, currMin);
    newVal->next = head;
    head = newVal;
    currMin = (currMin == nullptr || value < currMin->val) ? newVal : currMin;
  }

  int pop(){
    if(head == nullptr){
      return -1;
    }
    if(head == currMin){
      currMin = head->prevMin;
    }
    StackNode * oldTop = head;
    head = oldTop->next;
    return oldTop->val;
  }

  int top(){
    if(head == nullptr){
      return -1;
    }
    return head->val;
  }

  int min(){
    if(currMin == nullptr){
      return -1;
    }
    return currMin->val;
  }


  bool empty(){
    return head == nullptr;
  }

private:
  StackNode * head;
  StackNode * currMin;
};

void testOne(){
  MinStack * stack = new MinStack();
  stack->push(3);
  assert(stack->min() == 3);
  stack->push(1);
  stack->push(0);
  assert(stack->min() == 0);
  stack->pop();
  assert(stack->min() == 1);

}


int main(){
  testOne();
}
