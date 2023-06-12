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
    int solve(TreeNode* root, int& maxSum){
        if(root==NULL){
            return 0;
        }
        int left = solve(root->left, maxSum);
        left = (left<0)?0:left;
        int right = solve(root->right, maxSum);
        right = (right<0)?0:right;
        
        maxSum = max(maxSum, left+right+root->val);
        
        return max(left, right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        solve(root, maxSum);
        return maxSum;
    }
};