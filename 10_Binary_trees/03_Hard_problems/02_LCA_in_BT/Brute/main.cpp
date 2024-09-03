#include <bits/stdc++.h>
using namespace std;

// Time :- O((2 * N) + N)
// Space :- O(3 * height of tree)

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val, TreeNode *left = nullptr, TreeNode *right = nullptr)
      : val(val), left(left), right(right) {}
};

bool getPath(TreeNode *root, vector<TreeNode *> &ds, TreeNode *x) {
  if (root == nullptr) {
    return false;
  }

  ds.push_back(root);

  if (root == x) {
    return true;
  }

  bool left = getPath(root->left, ds, x);
  bool right = getPath(root->right, ds, x);

  if (left || right) {
    return true;
  }

  ds.pop_back();
  return false;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
  vector<TreeNode *> path1;
  vector<TreeNode *> path2;

  getPath(root, path1, p);
  getPath(root, path2, q);

  TreeNode *node = root;
  int i = 0, j = 0;

  while (i < path1.size() && j < path2.size()) {
    if (path1[i] == path2[j]) {
      node = path1[i];
    }
    i++;
    j++;
  }

  return node;
}

// Link -
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/