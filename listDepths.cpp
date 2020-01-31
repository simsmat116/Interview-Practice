#include <iostream>
#include <queue>

using namespace std;

struct TreeNode{
  int val;
  TreeNode * left;
  TreeNode * right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<TreeNode *> listOfDepths(TreeNode * root){
  vector<TreeNode *> lists;
  if(!root){
    return lists;
  }

  queue<TreeNode *> nodeQueue;
  nodeQueue.push(root);

  while(!nodeQueue.empty()){
    int currSize = nodeQueue.size();
    lists.push_back(nodeQueue.front());
    TreeNode * tracker = nullptr;

    for(int i = 0; i < currSize; ++i){
      TreeNode * currNode = nodeQueue.front();
      nodeQueue.pop();

      if(currNode->left){
        nodeQueue.push(currNode->left);
        currNode->left = nullptr;
      }

      if(currNode->right){
        nodeQueue.push(currNode->right);
      }

      if(tracker == nullptr){
        tracker = currNode;
      }
      else{
        tracker->right = currNode;
        tracker = currNode;
      }

    }

    tracker->right = nullptr;
  }

  return lists;
}

int main(){
  TreeNode * root = new TreeNode(6);
  root->right = new TreeNode(5);
  root->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(1);

  vector<TreeNode *> list = listOfDepths(root);
  for(int i = 0; i < list.size(); ++i){
    TreeNode * currNode = list[i];
    while(currNode != nullptr){
      cout << currNode->val << " ";
      currNode = currNode->right;
    }
    cout << endl;
  }
}
