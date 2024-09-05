#include <bits/stdc++.h>
using namespace std;

// Time :- O(N)
// Space :- O(height of tree)

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val, TreeNode *left = nullptr, TreeNode *right = nullptr)
      : val(val), left(left), right(right) {}
};

int countNodes(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }

  int left = countNodes(root->left);
  int right = countNodes(root->right);

  return 1 + left + right;
}

// Link -
// https://leetcode.com/problems/count-complete-tree-nodes/