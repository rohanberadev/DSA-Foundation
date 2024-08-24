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

vector<int> preorderTraversal(TreeNode *root) {
  vector<int> ans;

  if (root == nullptr) {
    return ans;
  }

  stack<TreeNode *> st;
  st.push(root);

  while (!st.empty()) {
    TreeNode *node = st.top();
    st.pop();

    if (node != nullptr) {
      ans.push_back(node->val);
      st.push(node->right);
      st.push(node->left);
    }
  }

  return ans;
}

// Link -
// https://leetcode.com/problems/binary-tree-preorder-traversal/