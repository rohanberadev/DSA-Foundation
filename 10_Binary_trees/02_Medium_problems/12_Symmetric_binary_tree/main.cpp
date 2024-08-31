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

bool isSymmetricUtil(TreeNode *root1, TreeNode *root2) {
  if (root1 == nullptr && root2 == nullptr) {
    return true;
  }

  if (root1 == nullptr) {
    return false;
  }

  if (root2 == nullptr) {
    return false;
  }

  if (root1->val != root2->val) {
    return false;
  }

  bool isSymmetric1 = isSymmetricUtil(root1->left, root2->right);
  bool isSymmetric2 = isSymmetricUtil(root1->right, root2->left);

  return isSymmetric1 && isSymmetric2;
}

bool isSymmetric(TreeNode *root) {
  return isSymmetricUtil(root->left, root->right);
}

// Link -
// https://leetcode.com/problems/symmetric-tree/