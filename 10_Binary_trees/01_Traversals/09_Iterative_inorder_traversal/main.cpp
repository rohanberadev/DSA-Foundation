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

vector<int> inorderTraversal(TreeNode *root) {
  vector<int> ans;

  if (root == nullptr) {
    return ans;
  }

  stack<TreeNode *> st;

  TreeNode *node = root;

  while (true) {
    if (node != nullptr) {
      st.push(node);
      node = node->left;
    }

    else {
      if (st.empty()) {
        break;
      }

      node = st.top();
      st.pop();
      ans.push_back(node->val);

      node = node->right;
    }
  }

  return ans;
}

// Link -
// https: // leetcode.com/problems/binary-tree-inorder-traversal/