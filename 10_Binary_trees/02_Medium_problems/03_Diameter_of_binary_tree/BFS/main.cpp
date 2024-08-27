#include <bits/stdc++.h>
using namespace std;

// Time :- O(N ^ 2)
// Space :- O(N)

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val, TreeNode *left = nullptr, TreeNode *right = nullptr)
      : val(val), left(left), right(right) {}
};

int maxDepth(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }

  int lh = maxDepth(root->left);
  int rh = maxDepth(root->right);

  return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode *root) {
  int diameter = 0;
  if (root == nullptr) {
    return diameter;
  }

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    int n = q.size();

    for (int i = 0; i < n; i++) {
      TreeNode *node = q.front();
      q.pop();

      if (node != nullptr) {
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        diameter = max(diameter, lh + rh);

        q.push(root->left);
        q.push(root->right);
      }
    }
  }

  return diameter;
}

// Link -
// https://leetcode.com/problems/diameter-of-binary-tree/