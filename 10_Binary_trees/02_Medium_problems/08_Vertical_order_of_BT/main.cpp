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

vector<vector<int>> verticalTraversal(TreeNode *root) {
  vector<vector<int>> ans;
  if (root == nullptr) {
    return ans;
  }

  map<int, map<int, multiset<int>>> nodes;
  queue<pair<TreeNode *, pair<int, int>>> q;
  q.push({root, {0, 0}});

  while (!q.empty()) {
    int n = q.size();

    for (int i = 0; i < n; i++) {
      pair<TreeNode *, pair<int, int>> it = q.front();
      q.pop();

      int vertical = it.second.first;
      int level = it.second.second;

      nodes[vertical][level].insert(it.first->val);

      if (it.first->left != nullptr) {
        q.push({it.first->left, {vertical - 1, level + 1}});
      }

      if (it.first->right) {
        q.push({it.first->right, {vertical + 1, level + 1}});
      }
    }
  }

  for (auto p : nodes) {
    vector<int> col;
    for (pair<int, multiset<int>> q : p.second) {
      col.insert(col.end(), q.second.begin(), q.second.end());
    }
    ans.push_back(col);
  }

  return ans;
}

// Link -
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/