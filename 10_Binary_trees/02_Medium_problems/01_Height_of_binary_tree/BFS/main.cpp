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

int maxDepth(TreeNode *root) {
  int depth = 0;
  if (root == nullptr) {
    return depth;
  }

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    int n = q.size();

    for (int i = 0; i < n; i++) {
      TreeNode *node = q.front();
      q.pop();

      if (node->left != nullptr) {
        q.push(node->left);
      }

      if (node->right != nullptr) {
        q.push(node->right);
      }
    }

    depth++;
  }

  return depth;
}

// Link -
// https://leetcode.com/problems/maximum-depth-of-binary-tree/