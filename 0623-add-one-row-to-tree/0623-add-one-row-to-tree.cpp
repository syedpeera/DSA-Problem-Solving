#include <queue>

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        std::queue<TreeNode*> q;
        q.push(root);
        int currentDepth = 1;
        
        while (!q.empty()) {
            int size = q.size();
            if (currentDepth == depth - 1) {
                for (int i = 0; i < size; ++i) {
                    TreeNode* node = q.front();
                    q.pop();
                    TreeNode* leftChild = new TreeNode(val);
                    TreeNode* rightChild = new TreeNode(val);
                    leftChild->left = node->left;
                    rightChild->right = node->right;
                    node->left = leftChild;
                    node->right = rightChild;
                }
                break; // Nodes at depth - 1 are processed, no need to continue
            }
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ++currentDepth;
        }
        
        return root;
    }
};
