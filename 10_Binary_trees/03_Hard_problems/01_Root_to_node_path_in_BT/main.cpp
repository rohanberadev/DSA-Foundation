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

vector<int> convertArray2Vector(int arr[], int len) {
  vector<int> path;
  for (int i = 0; i < len; i++) {
    path.push_back(arr[i]);
  }
  return path;
}

void pathsUtil(TreeNode *root, int path[], vector<vector<int>> &ans, int len) {
  if (root == nullptr) {
    return;
  }

  path[len] = root->val;
  len++;

  if (root->left == nullptr && root->right == nullptr) {
    ans.push_back(convertArray2Vector(path, len));
  }

  else {
    pathsUtil(root->left, path, ans, len);
    pathsUtil(root->right, path, ans, len);
  }
}

vector<vector<int>> paths(TreeNode *root) {
  vector<vector<int>> ans;

  if (root == nullptr) {
    return ans;
  }

  int path[INT_MAX];

  return ans;
}

// Link -
// https://bit.ly/3QA600D