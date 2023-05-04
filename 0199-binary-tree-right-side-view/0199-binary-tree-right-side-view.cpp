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
    void printRightView(vector<TreeNode*>& ans, TreeNode* root, int level){
        if(root==NULL){
            return;
        }
        if(ans.size()==level){
            ans.push_back(root);
        }
        printRightView(ans, root->right, level+1);
        printRightView(ans, root->left, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<TreeNode*> ans;
        printRightView(ans, root, 0);
        vector<int> result;
        for(TreeNode* temp: ans){
            result.push_back(temp->val);
        }
        return result;
    }
};