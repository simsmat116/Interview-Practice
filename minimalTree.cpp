#include <iostream>
#include <vector>

using namespace std;
#define COUNT 10

struct TreeNode{
  int val;
  TreeNode * left;
  TreeNode * right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode * minimalTreeHelper(int start, int end, vector<int> &sortedVec){
  if(start == end){
    TreeNode * newNode = new TreeNode(sortedVec[start]);
    return newNode;
  }
  else if(start > end){
    return nullptr;
  }

  int middle = (start + end) / 2;
  TreeNode * newNode = new TreeNode(sortedVec[middle]);

  newNode->right = minimalTreeHelper(middle + 1, end, sortedVec);
  newNode->left = minimalTreeHelper(start, middle - 1, sortedVec);
  return newNode;
}

TreeNode * minimalTree(vector<int> sortedVec){
  if(sortedVec.size() == 0){
    return nullptr;
  }

  return minimalTreeHelper(0, sortedVec.size() - 1, sortedVec);
}

void print2DUtil(TreeNode *root, int space){
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout <<root->val << "\n";

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(TreeNode * root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

int main(){
  vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  vec.push_back(5);
  vec.push_back(6);
  vec.push_back(7);

  TreeNode * root = minimalTree(vec);
  print2D(root);
}
