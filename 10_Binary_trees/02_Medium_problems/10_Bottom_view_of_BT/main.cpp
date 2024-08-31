#include <bits/stdc++.h>
using namespace std;

// Time :- O(2 * N)
// Space :- O(N)

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val, TreeNode *left = nullptr, TreeNode *right = nullptr)
      : val(val), left(left), right(right) {}
};

vector<int> bottomView(TreeNode *root) {
  vector<int> ans;
  if (root == nullptr) {
    return ans;
  }

  map<int, int> mpp;
  queue<pair<TreeNode *, int>> q;
  q.push({root, 0});

  while (!q.empty()) {
    int n = q.size();

    for (int i = 0; i < n; i++) {
      pair<TreeNode *, int> it = q.front();
      q.pop();

      int vertical = it.second;
      TreeNode *node = it.first;

      mpp[vertical] = node->val;

      if (node->left) {
        q.push({node->left, vertical - 1});
      }

      if (node->right) {
        q.push({node->right, vertical + 1});
      }
    }
  }

  for (pair<int, int> it : mpp) {
    ans.push_back(it.second);
  }

  return ans;
}

// Link -
// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1