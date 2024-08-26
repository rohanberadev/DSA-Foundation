#include <bits/stdc++.h>
using namespace std;

// Time :- O(N)
// Space :- O(2 * N)

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val, TreeNode *left = nullptr, TreeNode *right = nullptr)
      : val(val), left(left), right(right) {}
};

vector<int> postorderTraversal(TreeNode *root) {
  vector<int> ans;
  if (root == nullptr) {
    return ans;
  }

  stack<TreeNode *> st1, st2;
  st1.push(root);

  while (!st1.empty()) {
    TreeNode *node = st1.top();
    st1.pop();

    if (node != nullptr) {
      st2.push(node);

      st1.push(node->left);
      st1.push(node->right);
    }
  }

  while (!st2.empty()) {
    ans.push_back(st2.top()->val);
    st2.pop();
  }

  return ans;
}

// Link -
// https://leetcode.com/problems/binary-tree-postorder-traversal/