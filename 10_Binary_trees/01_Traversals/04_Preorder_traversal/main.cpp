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

  ans.push_back(root->val);
  func(root->left, ans);
  func(root->right, ans);
}

vector<int> preorderTraversal(TreeNode *root) {
  vector<int> ans;
  func(root, ans);

  return ans;
}

// Link -
// https://leetcode.com/problems/binary-tree-preorder-traversal/