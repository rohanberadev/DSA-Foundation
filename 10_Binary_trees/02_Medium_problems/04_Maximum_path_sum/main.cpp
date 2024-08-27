#include <bits/stdc++.h>
using namespace std;

// Time :- O(N)
// Space :- O(1)

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val, TreeNode *left = nullptr, TreeNode *right = nullptr)
      : val(val), left(left), right(right) {}
};

int dfsMaxSum(TreeNode *root, int &sum) {
  if (root == nullptr) {
    return 0;
  }

  int leftSum = max(0, dfsMaxSum(root->left, sum));
  int rightSum = max(0, dfsMaxSum(root->right, sum));
  sum = max(sum, root->val + leftSum + rightSum);

  return root->val + max(leftSum, rightSum);
}

int maxPathSum(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }

  int maxSum = INT_MIN;
  dfsMaxSum(root, maxSum);

  return maxSum;
}

// Link -
// https://leetcode.com/problems/binary-tree-maximum-path-sum/
