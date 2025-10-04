// 92. Validate Binary Search Tree

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {};
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
  ~TreeNode() {};
};
void inorder(TreeNode *node, vector<int> &arr) {
  if (node->left != nullptr)
    inorder(node->left, arr);
  arr.push_back(node->val);
  if (node->right != nullptr)
    inorder(node->right, arr);
}

bool isValidBST(TreeNode* node) {
  vector<int> nums;
  inorder(node, nums);

  for (size_t i = 0; i < nums.size() - 1; i++) {
    if (nums[i] >= nums[i + 1]) return false;
  }
  return true;
}

int main() {
  TreeNode root1(
    45,
    new TreeNode(
      42,
      nullptr,
      new TreeNode(
        44,
        new TreeNode(
          43,
          new TreeNode(41),
          nullptr
        ),
        nullptr
      )
    ),
    new TreeNode(46)
  );

  bool isValidBST1 = isValidBST(&root1);

  cout << "IsValid1: " << boolalpha << (isValidBST1 == false ? "Correct" : "Incorrect") << endl;
  cout << "expected: " << false  << "  | actual: " << isValidBST1 << boolalpha << endl;

  return 0;
}