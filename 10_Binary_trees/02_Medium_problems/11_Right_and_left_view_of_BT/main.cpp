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

vector<int> rightSideView(TreeNode *root) {
  vector<int> ans;
  if (root == nullptr) {
    return ans;
  }

  TreeNode *node = root;

  return ans;
}

// Link -
// https://leetcode.com/problems/binary-tree-right-side-view/