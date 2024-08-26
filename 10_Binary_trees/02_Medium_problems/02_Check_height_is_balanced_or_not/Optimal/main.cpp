#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val, TreeNode *left = nullptr, TreeNode *right = nullptr)
      : val(val), left(left), right(right) {}
};

int dfsHeight(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }

  int lh = dfsHeight(root->left);

  if (lh == -1) {
    return -1;
  }

  int rh = dfsHeight(root->right);

  if (rh == -1) {
    return -1;
  }

  if (abs(lh - rh) > 1) {
    return -1;
  }

  return max(lh, rh) + 1;
}

bool isBalanced(TreeNode *root) { return dfsHeight(root); }

// Link -
// https://leetcode.com/problems/balanced-binary-tree/