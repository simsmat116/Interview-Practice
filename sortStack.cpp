#include <stack>
#include <iostream>

using namespace std;

stack<int> sortStack(stack<int> &sortedStack){
  if(sortedStack.size() == 0){
    return sortedStack;
  }
  stack<int> bufferStack;
  // Push top element of stack to be sorted into temp stack
  bufferStack.push(sortedStack.top());
  sortedStack.pop();

  // Continue until the stack has been sorted
  while(!sortedStack.empty()){
    int currElem = sortedStack.top();
    sortedStack.pop();
    while(!bufferStack.empty() && currElem < bufferStack.top()){
      sortedStack.push(bufferStack.top());
      bufferStack.pop();
    }

    bufferStack.push(currElem);

  }

  while(!bufferStack.empty()){
    sortedStack.push(bufferStack.top());
    bufferStack.pop();
  }

  return sortedStack;
}

int main(){
  stack<int> s1;
  s1.push(23);
  s1.push(34);
  s1.push(10);
  s1.push(2);
  s1.push(45);
  s1.push(27);
  sortStack(s1);
  while(!s1.empty()){
    cout << s1.top() << endl;
    s1.pop();
  }
}
