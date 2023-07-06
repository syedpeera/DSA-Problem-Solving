/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int checkHeight(TreeNode root){
        if(root==null){
            return 0;
        }
        int leftHeight = checkHeight(root.left);
        if(leftHeight==-1){
            return -1;
        }
        int rightHeight = checkHeight(root.right);
        if(rightHeight==-1){
            return -1;
        }
        if(Math.abs(leftHeight-rightHeight)>1){
            return -1;
        }
        return 1+Math.max(leftHeight, rightHeight);
    }
    public boolean isBalanced(TreeNode root) {
        if(root==null){
            return true;
        }
        if(checkHeight(root)==-1){
            return false;
        }
        else{
            return true;
        }
    }
}