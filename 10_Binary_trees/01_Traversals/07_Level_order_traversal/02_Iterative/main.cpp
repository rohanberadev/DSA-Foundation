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

vector<vector<int>> levelOrder(TreeNode *root) {
  vector<vector<int>> ans;
  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty() && q.front() != nullptr) {
    int n = q.size();
    vector<int> res;

    for (int i = 0; i < n; i++) {
      TreeNode *node = q.front();
      q.pop();

      if (node->left != nullptr) {
        q.push(node->left);
      }

      if (node->right != nullptr) {
        q.push(node->right);
      }

      res.push_back(node->val);
    }
    ans.push_back(res);
  }

  return ans;
}

// Link -
// https://leetcode.com/problems/binary-tree-level-order-traversal/