#include <bits/stdc++.h>
#include <utility>
using namespace std;

// Time :- O(N)
// Space :- O(1)

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val, TreeNode *left = nullptr, TreeNode *right = nullptr)
      : val(val), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
  vector<vector<int>> ans;

  if (root == nullptr) {
    return ans;
  }

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    int n = q.size();
    vector<int> res;

    for (int i = 0; i < n; i++) {
      TreeNode *node = q.front();
      q.pop();

      res.push_back(node->val);

      if (node->left != nullptr) {
        q.push(node->left);
      }
      if (node->right) {
        q.push(node->right);
      }
    }

    ans.push_back(res);
  }

  for (int i = 0; i < ans.size(); i++) {
    if (i % 2 == 0) {
      continue;
    }
    int l = 0, r = ans[i].size() - 1;

    while (l < r) {
      swap(ans[i][l++], ans[i][r--]);
    }
  }

  return ans;
}