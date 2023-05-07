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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }   
        int dl = diameterOfBinaryTree(root->left);
        int dr = diameterOfBinaryTree(root->right);
        int curr = heightOfTree(root->left) + heightOfTree(root->right);
        return max(curr, max(dl, dr));
    }
    int heightOfTree(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(heightOfTree(root->left), heightOfTree(root->right));
    }
};