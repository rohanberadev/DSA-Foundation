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

int isSumProperty(TreeNode *root) {
  if (root == nullptr) {
    return 1;
  }

  if (root->left == nullptr && root->right == nullptr) {
    return 1;
  }

  int leftVal = 0, rightVal = 0;

  if (root->left != nullptr) {
    leftVal = root->left->val;
  }

  if (root->right != nullptr) {
    rightVal = root->right->val;
  }

  int left = isSumProperty(root->left);
  int right = isSumProperty(root->right);

  if ((root->val == leftVal + rightVal) && left == 1 && right == 1) {
    return 1;
  } else {
    return 0;
  }
}

// Link -
// https://bit.ly/3dEr73g