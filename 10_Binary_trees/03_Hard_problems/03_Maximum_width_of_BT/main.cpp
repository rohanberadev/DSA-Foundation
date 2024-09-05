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

int widthOfBinaryTree(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }

  long long maxWidth = 0;
  queue<pair<TreeNode *, long long>> q;
  q.push({root, 0});

  while (!q.empty()) {
    int n = q.size();
    long long mini = q.front().second;
    long long first, last;

    for (int i = 0; i < n; i++) {
      TreeNode *node = q.front().first;
      long long currId = q.front().second - mini;
      q.pop();

      if (node->left != nullptr) {
        q.push({node->left, 2 * currId + 1});
      }

      if (node->right != nullptr) {
        q.push({node->right, 2 * currId + 2});
      }

      first = i == 0 ? currId : first;
      last = i == n - 1 ? currId : last;
    }

    maxWidth = max(maxWidth, last - first + 1);
  }

  return maxWidth;
}

// Link -
// https://leetcode.com/problems/maximum-width-of-binary-tree/