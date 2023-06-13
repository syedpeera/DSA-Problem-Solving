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
    int count=0;
    int result=0;
    void inorderTraversal(TreeNode* root, int k){
        if(root==NULL){
            return;
        }
        inorderTraversal(root->left, k);
        count++;
        if(count==k){
            result=root->val;
            return;
        }
        inorderTraversal(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorderTraversal(root, k);
        return result;
    }
};