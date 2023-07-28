class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int xDepth = -1, yDepth = -1;
        TreeNode* xParent = nullptr, *yParent = nullptr;
        findDepthAndParent(root, nullptr, x, y, 0, xDepth, yDepth, xParent, yParent);
        return xDepth == yDepth && xParent != yParent;
    }
    void findDepthAndParent(TreeNode* node, TreeNode* parent, int x, int y, int depth,
                            int& xDepth, int& yDepth, TreeNode*& xParent, TreeNode*& yParent) {
        if (node == nullptr) return;

        if (node->val == x) {
            xDepth = depth;
            xParent = parent;
        } else if (node->val == y) {
            yDepth = depth;
            yParent = parent;
        }

        findDepthAndParent(node->left, node, x, y, depth + 1, xDepth, yDepth, xParent, yParent);
        findDepthAndParent(node->right, node, x, y, depth + 1, xDepth, yDepth, xParent, yParent);
    }
};
