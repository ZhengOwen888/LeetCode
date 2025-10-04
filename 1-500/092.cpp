#include <iostream>
#include <utility>
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

// pair<isValid, pair<min, max>
pair<bool, pair<int,int>> dfsBST(TreeNode * node) {
  if (node == nullptr) // node is null
      return make_pair(true, make_pair(-1, -1));
  if (node->left == nullptr && node->right == nullptr) // leaf node
      return make_pair(true, make_pair(node->val, node->val));

  // Check left and right validity and find min max of left and right tree
  auto [isLeftValid, lMinMax] = dfsBST(node->left);
  auto [isRightValid, rMinMax] = dfsBST(node->right);

  if (isLeftValid) {
    // Compare current value with max value left tree
    if (node->left != nullptr && node->val <= lMinMax.second) {
      return make_pair(false, make_pair(-1, -1)); // since it is not valid anyways we don't need to keep track of the min and max of the tree anymore
    }
  } else return make_pair(false, make_pair(-1, -1));

  if (isRightValid) {
    // Compare current value with min value right tree
    if(node->right != nullptr && node->val >= rMinMax.first) {
      return make_pair(false, make_pair(-1, -1));
    }
  } else return make_pair(false, make_pair(-1, -1));

  // Valid tree
  // compare current val with min val on the left tree
  auto minVal = node->left == nullptr ? node->val : min(node->val, lMinMax.first);
  // compare current val with max val on the right tree
  auto maxVal = node->right == nullptr ? node->val : max(node->val, rMinMax.second);
  return make_pair(true, make_pair(minVal, maxVal));
}

bool isValidBST(TreeNode* node) {
  auto [isValid, minMax] = dfsBST(node);
  return isValid;
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