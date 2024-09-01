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

void leftPath(TreeNode *root, vector<int> &ds) {
  if (root == nullptr) {
    return;
  }

  ds.push_back(root->val);

  if (root->left) {
    leftPath(root->left, ds);
  } else {
    leftPath(root->right, ds);
  }
}

void rightPath(TreeNode *root, vector<int> &ds) {
  if (root == nullptr) {
    return;
  }

  ds.push_back(root->val);

  if (root->right) {
    leftPath(root->right, ds);
  } else {
    leftPath(root->left, ds);
  }
}

vector<vector<int>> paths(TreeNode *root) {}