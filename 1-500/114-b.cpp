// 144. Binary Tree Preorder Traversal (Elegant recursive solution)

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void preorderTree(TreeNode* node, vector<int> &arr) {
  if (node) {
    arr.push_back(node->val);
    preorderTree(node->left, arr);
    preorderTree(node->right, arr);
  }
}

vector<int> preorderTraversal(TreeNode* root) {
  vector<int> res;
  preorderTree(root, res);
  return res;
}

int main() {
  return 0;
}