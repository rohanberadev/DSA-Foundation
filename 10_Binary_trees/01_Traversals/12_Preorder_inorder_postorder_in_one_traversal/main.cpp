#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val, TreeNode *left = nullptr, TreeNode *right = nullptr)
      : val(val), left(left), right(right) {}
};

vector<vector<int>> preInPostTraversal(TreeNode *root) {
  vector<int> preorder;
  vector<int> inorder;
  vector<int> postorder;

  stack<pair<TreeNode *, int>> st;
  st.push({root, 1});

  while (!st.empty()) {
    pair<TreeNode *, int> it = st.top();
    st.pop();

    if (it.second == 1) {
      preorder.push_back(it.first->val);
      it.second++;
      st.push(it);

      if (it.first->left != nullptr) {
        st.push({it.first->left, 1});
      }
    }

    else if (it.second == 2) {
      inorder.push_back(it.first->val);
      it.second++;
      st.push(it);

      if (it.first->left != nullptr) {
        st.push({it.first->right, 1});
      }
    }

    else {
      postorder.push_back(it.first->val);
    }
  }

  return {preorder, inorder, postorder};
}

// Link -
// https://bit.ly/3T3oW9M