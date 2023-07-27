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
    int solveGoodNodes(TreeNode* root, int maxValue){
        if(root == nullptr){
            return 0;
        }
        
        int goodNodeCount = 0;
        if(root->val >= maxValue){
            goodNodeCount++;
            maxValue = root->val;
        }
        
        goodNodeCount = goodNodeCount + solveGoodNodes(root->left, maxValue);
        goodNodeCount = goodNodeCount + solveGoodNodes(root->right, maxValue);
        
        return goodNodeCount;
    }
    int goodNodes(TreeNode* root) {
        return solveGoodNodes(root, INT_MIN);
    }
};