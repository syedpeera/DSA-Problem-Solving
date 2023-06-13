/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inorderMap){
        if(preStart > preEnd || inStart > inEnd){
            return NULL;
        }
        int rootVal = preorder[preStart];
        TreeNode * root = new TreeNode(rootVal);
        int inRootIndex = inorderMap[rootVal];
        int leftSubtreeSize = inRootIndex - inStart;
        
        root->left = buildTree(preorder, preStart+1, preStart+leftSubtreeSize, inorder, inStart, inRootIndex-1, inorderMap);
        root->right = buildTree(preorder, preStart+leftSubtreeSize+1, preEnd, inorder, inRootIndex+1, inEnd, inorderMap);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //Inorder Traversal Elements and their corresponding index
        unordered_map<int, int> inorderMap;
        for(int i=0;i<inorder.size();i++){
            inorderMap[inorder[i]]=i;
        }
        TreeNode* root = buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inorderMap);
        return root;
    }
};