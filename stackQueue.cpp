#include <stack>
#include <iostream>

using namespace std;

class MyQueue{
public:
  void push(int val){
    s1.push(val);
  }

  void pop(){
    shuffleStacks();
    if(!s2.empty()){
      s2.pop();
    }
  }

  int front(){
    shuffleStacks();
    return (!s2.empty()) ? s2.top() : -1;
  }

  bool empty(){
    return s1.empty() && s2.empty();
  }

  int size(){
    return s1.size() + s2.size();
  }


private:
  stack<int> s1;
  stack<int> s2;

  void shuffleStacks(){
    if(s2.empty()){
      while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
      }
    }
  }

};

int main(){
  MyQueue q1;
  q1.push(4);
  assert(!q1.empty());
  q1.push(5);
  q1.pop();
  assert(q1.front() == 5);
  q1.push(6);
  q1.push(7);
  q1.push(3);
  q1.push(1);
  assert(q1.size() == 5);
  q1.pop();
  q1.pop();
  assert(q1.front() == 7);
  q1.pop();
  q1.pop();
  assert(q1.front() == 1);
  q1.pop();
  assert(q1.empty());
}
