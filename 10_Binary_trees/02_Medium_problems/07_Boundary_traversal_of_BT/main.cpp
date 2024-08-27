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

bool isLeaf(TreeNode *node) {
  return node->left == nullptr && node->right == nullptr;
}

void addLeftBoundary(TreeNode *root, vector<int> &ans) {
  TreeNode *node = root;
  while (node != nullptr) {
    if (!isLeaf(node)) {
      ans.push_back(node->val);
    }

    if (node->left != nullptr) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
}

void addRightBoundary(TreeNode *root, vector<int> &ans) {
  TreeNode *node = root;

  vector<int> temp;

  while (node != nullptr) {
    if (!isLeaf(node)) {
      temp.push_back(node->val);
    }

    if (node->right != nullptr) {
      node = node->right;
    } else {
      node = node->left;
    }
  }

  for (int i = temp.size() - 1; i >= 0; i--) {
    ans.push_back(temp[i]);
  }
}

void addLeaves(TreeNode *node, vector<int> &ans) {
  if (node == nullptr) {
    return;
  }

  if (isLeaf(node)) {
    ans.push_back(node->val);
    return;
  }

  if (node->left != nullptr) {
    addLeaves(node->left, ans);
  }

  if (node->right != nullptr) {
    addLeaves(node->right, ans);
  }
}

vector<int> printBoundary(TreeNode *root) {
  vector<int> ans;
  if (root == nullptr) {
    return ans;
  }

  ans.push_back(root->val);

  addLeftBoundary(root->left, ans);

  addLeaves(root->left, ans);
  addLeaves(root->right, ans);

  addRightBoundary(root->right, ans);

  return ans;
}

// Link -
// https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/