// 102. Binary Tree Level Order Traversal (Incomplete)

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<vector<int>> LevelOrder(TreeNode* root) {
  vector<vector<int>> res;
  deque<TreeNode> d = { *root };


  while (!d.empty()) {
    vector<int> temp;

    for (TreeNode node: d) {
      temp.push_back(node.val);
    }

    res.push_back(temp);

    TreeNode node = d.front();
    d.pop_front();

    if (node.left != nullptr)
      d.push_back(*node.left);
    if (node.right != null)
  }
}