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
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(height(root->left), height(root->right));
    }

    void printCurrentLevel(vector<int>& ans,TreeNode* root, int level){
        if(root==NULL){
            return;
        }
        if(level==1){
            ans.push_back(root->val);
        }
        else if(level>1){
            printCurrentLevel(ans, root->left, level-1);
            printCurrentLevel(ans, root->right, level-1);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int h = height(root);
        vector<vector<int>> result;
        for(int i=1;i<=h;i++){
            vector<int> ans;
            printCurrentLevel(ans, root, i);
            result.push_back(ans);
        }
        return result;
    }
};