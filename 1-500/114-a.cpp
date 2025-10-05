// 114. Binary Tree Preorder Traversal

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

vector<int> preorderTraversal(TreeNode* root) {

  // stack<TreeNode*, vector<TreeNode*>> tNodes({root}); // this also works
  vector<int> res;
  stack<TreeNode *> tNodes; // use a stack
  tNodes.push(root);

  while (!tNodes.empty()) {
    TreeNode *node = tNodes.top();
    tNodes.pop();

    if (node) {
      res.push_back(node->val);
      tNodes.push(node->right);
      tNodes.push(node->left);
    }
  }

  return res;
}

int main() {
  return 0;
}