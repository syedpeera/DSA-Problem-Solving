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
    void inorder(TreeNode* root, TreeNode** prev, TreeNode** first, TreeNode** middle, TreeNode** last){
        if(root==NULL){
            return;
        }
        inorder(root->left, prev, first, middle, last);
        if(*prev!=NULL && (*prev)->val > root->val){
            if(*first==NULL){
                *first = *prev;
                *middle = root;
            }
            else{
                *last = root;
            }
        }
        *prev = root;
        inorder(root->right, prev, first, middle, last);
    }
    void recoverTree(TreeNode* root) {
        if(root==NULL){
            return;
        }
        TreeNode* prev = new TreeNode(INT_MIN);
        TreeNode* first = NULL;
        TreeNode* middle = NULL;
        TreeNode* last = NULL;
        inorder(root, &prev, &first, &middle, &last);
        if(first!=NULL && last!=NULL){
            int temp = first->val;
            first->val = last->val;
            last->val = temp;
        }
        else if(first!=NULL && middle!=NULL){
            int temp = first->val;
            first->val = middle->val;
            middle->val = temp;
        }
    }
};