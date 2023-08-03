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
    bool solveFindTarget(TreeNode* root, int k, set<int> &set){
        if(root == nullptr){
            return false;
        }
        if(set.find(k - root->val) != set.end()){
            return true;
        }
        set.insert(root->val);
        return solveFindTarget(root->left, k, set) || solveFindTarget(root->right, k, set);
    }
    bool findTarget(TreeNode* root, int k) {
        set<int> set;
        return solveFindTarget(root, k, set);
    }
};