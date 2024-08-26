#include <bits/stdc++.h>
using namespace std;

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

  stack<TreeNode *> st;

  TreeNode *node = root;

  while (node != nullptr || !st.empty()) {
    if (node != nullptr) {
      st.push(node);
      node = node->left;
    }

    else {
      TreeNode *temp = st.top()->right;

      if (temp == nullptr) {
        temp = st.top();
        st.pop();

        ans.push_back(temp->val);

        while (!st.empty() && temp == st.top()->right) {
          temp = st.top();
          st.pop();
          ans.push_back(temp->val);
        }
      }

      else {
        node = temp;
      }
    }
  }

  return ans;
}

// Link -
// https://leetcode.com/problems/binary-tree-postorder-traversal/