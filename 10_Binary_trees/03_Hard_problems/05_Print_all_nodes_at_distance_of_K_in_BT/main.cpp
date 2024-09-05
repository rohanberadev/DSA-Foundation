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

vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
  vector<int> ans;
  if (root == nullptr) {
    return ans;
  }

  queue<pair<TreeNode *, int>> q;
  q.push({root, 0});

  int targetInd = -1;

  while (!q.empty()) {
    int n = q.size();
    int mini = q.back().second;

    for (int i = 0; i < n; i++) {
      TreeNode *node = q.front().first;
      int ind = q.front().second - mini;
      q.pop();

      if (node == target) {
        targetInd = ind;
      }

      if (targetInd - ind + 1 == k) {
        ans.push_back(node->val);
      }

      if (node->left) {
        q.push({node->left, 2 * ind + 1});
      }

      if (node->right) {
        q.push({node->right, 2 * ind + 2});
      }
    }
  }

  return ans;
}