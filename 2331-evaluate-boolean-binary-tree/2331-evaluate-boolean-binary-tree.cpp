class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);
        unordered_map<TreeNode*, bool> evaluated;

        while (!st.empty()) {
            TreeNode* topNode = st.top();

            if (!topNode->left and !topNode->right) {
                st.pop();
                evaluated[topNode] = topNode->val;
                continue;
            }

            if (evaluated.find(topNode->left) != evaluated.end() and
                evaluated.find(topNode->right) != evaluated.end()) {
                st.pop();
                if (topNode->val == 2) {
                    evaluated[topNode] =
                        evaluated[topNode->left] || evaluated[topNode->right];
                } else {
                    evaluated[topNode] =
                        evaluated[topNode->left] && evaluated[topNode->right];
                }
            } else {
                st.push(topNode->right);
                st.push(topNode->left);
            }
        }

        return evaluated[root] == 1;
    }
};