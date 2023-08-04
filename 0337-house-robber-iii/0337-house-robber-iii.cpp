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
    unordered_map<TreeNode*, int> map;
    int rob(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        
        if(map.find(root) != map.end()){
            return map[root];
        }
        
        int sum = root->val;
        
        if(root->left != nullptr){
            sum = sum + rob(root->left->left);
            sum = sum + rob(root->left->right);
        }
        
        if(root->right != nullptr){
            sum = sum + rob(root->right->left);
            sum = sum + rob(root->right->right);
        }
        
        int nextSum = rob(root->left) + rob(root->right);
        
        int result = max(sum, nextSum);
        
        map[root] = result;
        
        return result;
    }
};