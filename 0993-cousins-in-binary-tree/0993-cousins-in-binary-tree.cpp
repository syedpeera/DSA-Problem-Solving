class Solution {
public:
    void findDepthAndParent(TreeNode* root, TreeNode* parent, int x, int y, int depth, int &xDepth, int &yDepth, TreeNode* &xParent, TreeNode* &yParent){
        if(root == nullptr){
            return;
        }
        
        if(root->val == x){
            xDepth = depth;
            xParent = parent;
        }
        else if(root->val == y){
            yDepth = depth;
            yParent = parent;
        }
        
        findDepthAndParent(root->left, root, x, y, depth+1, xDepth, yDepth, xParent, yParent);
        findDepthAndParent(root->right, root, x, y, depth+1, xDepth, yDepth, xParent, yParent);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int xDepth = -1;
        int yDepth = -1;
        TreeNode* xParent = nullptr;
        TreeNode* yParent = nullptr;
        findDepthAndParent(root, nullptr, x, y, 0, xDepth, yDepth, xParent, yParent);
        if(xDepth == yDepth && xParent != yParent){
            return true;
        }
        else{
            return false;
        }
    }
};
