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

vector<int> topView(TreeNode *root) {
  vector<int> ans;
  if (root == nullptr) {
    return ans;
  }

  map<int, int> nodes;
  queue<pair<TreeNode *, int>> q;
  q.push({root, 0});

  while (!q.empty()) {
    int n = q.size();

    for (int i = 0; i < n; i++) {
      pair<TreeNode *, int> it = q.front();
      q.pop();

      int vertical = it.second;

      if (nodes.find(vertical) == nodes.end()) {
        nodes[vertical] = it.first->val;
      }

      if (it.first->left) {
        q.push({it.first->left, vertical - 1});
      }

      if (it.first->right) {
        q.push({it.first->right, vertical + 1});
      }
    }
  }

  for (pair<int, int> it : nodes) {
    ans.push_back(it.second);
  }

  return ans;
}

// Link -
// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1