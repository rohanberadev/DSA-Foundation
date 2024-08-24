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

void func(vector<vector<int>> &ans, queue<TreeNode *> &q) {
  if (q.empty() || q.front() == nullptr) {
    return;
  }

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

  func(ans, q);
}

vector<vector<int>> levelOrder(TreeNode *root) {
  vector<vector<int>> ans;
  queue<TreeNode *> q;
  q.push(root);

  func(ans, q);

  return ans;
}

// Link -
// https://leetcode.com/problems/binary-tree-level-order-traversal/