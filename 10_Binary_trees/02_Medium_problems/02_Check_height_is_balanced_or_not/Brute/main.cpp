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

bool isBalanced(TreeNode *root) {
  if (root == nullptr) {
    return true;
  }

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    int n = q.size();

    for (int i = 0; i < n; i++) {
      TreeNode *node = q.front();
      q.pop();

      if (node != nullptr) {
        int lh = maxDepth(node->left);
        int rh = maxDepth(node->right);

        if (abs(lh - rh) > 1) {
          return false;
        }

        q.push(node->left);
        q.push(node->right);
      }
    }
  }

  return true;
}

// Link -
// https://leetcode.com/problems/balanced-binary-tree/