#include <iostream>
#include <vector>

using namespace std;

class Stack{
public:
  Stack(int cap){
    capacity = cap;
    curr_stack = 0;
    vector< vector<int> > stacks;
    vector<int> stack;
    stacks.push_back(stack);
    setOfStacks = stacks;
  }

  void push(int val){
    if(setOfStacks[curr_stack].size() == capacity){
      vector<int> substack;
      substack.push_back(val);
      setOfStacks.push_back(substack);
      ++curr_stack;
      return;
    }

    setOfStacks[curr_stack].push_back(val);
    return;
  }

  int pop(){
    if(setOfStacks[curr_stack].empty()){
      return -1;
    }

    int back = setOfStacks[curr_stack].back();
    setOfStacks[curr_stack].pop_back();

    if(setOfStacks[curr_stack].empty() && curr_stack != 0){
      --curr_stack;
    }

    return back;
  }

  int top(){
    if(setOfStacks[curr_stack].size() == 0){
      return -1; // Could throw an error if the stacks are empty
    }
    return setOfStacks[curr_stack].back();
  }

  int empty(){
    return setOfStacks[curr_stack].empty();
  }


private:
  int capacity;
  int curr_stack;
  vector< vector<int> > setOfStacks;
};

void test(){
  Stack stack = Stack(3);
  assert(stack.empty());
  stack.push(4);
  stack.push(3);
  stack.push(1);
  assert(stack.top() == 1);
  stack.push(3);
  stack.pop();
  assert(stack.top() == 1);
  stack.pop();
  stack.pop();
  stack.pop();
  assert(stack.empty());
}

int main(){
  test();
}
