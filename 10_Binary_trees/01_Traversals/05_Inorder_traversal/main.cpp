#include <bits/stdc++.h>
using namespace std;

// Time :- O(N)
// Space :- O(N)

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val, TreeNode *left = nullptr, TreeNode *right = nullptr)
      : val(val), left(left), right(right) {}
};

void func(TreeNode *root, vector<int> &ans) {
  if (root == nullptr) {
    return;
  }

  func(root->left, ans);
  ans.push_back(root->val);
  func(root->right, ans);
}

vector<int> inorderTraversal(TreeNode *root) {
  vector<int> ans;
  func(root, ans);

  return ans;
}

// Link -
// https://leetcode.com/problems/binary-tree-inorder-traversal/