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

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
  if (root == nullptr || root == p || root == q) {
    return root;
  }

  TreeNode *left = lowestCommonAncestor(root->left, p, q);
  TreeNode *right = lowestCommonAncestor(root->right, p, q);

  if (left != nullptr && right != nullptr) {
    return root;
  }

  if (left != nullptr) {
    return left;
  } else {
    return right;
  }
}

// Link -
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/