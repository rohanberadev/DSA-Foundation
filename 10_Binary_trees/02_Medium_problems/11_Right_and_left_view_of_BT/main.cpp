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

void reversePreorder(TreeNode *root, int level, vector<int> &ans) {
  if (root == nullptr) {
    return;
  }

  if (level == ans.size()) {
    ans.push_back(root->val);
  }

  reversePreorder(root->right, level + 1, ans);
  reversePreorder(root->left, level + 1, ans);
}

vector<int> rightSideView(TreeNode *root) {
  vector<int> ans;
  if (root == nullptr) {
    return ans;
  }

  reversePreorder(root, 0, ans);

  return ans;
}

// Link -
// https://leetcode.com/problems/binary-tree-right-side-view/