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
    private TreeNode prev;
    private TreeNode first;
    private TreeNode middle;
    private TreeNode last;
    public void inorder(TreeNode root){
        if(root==null){
            return;
        }
        inorder(root.left);
        if(prev!=null && prev.val > root.val){
            if(first==null){
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }
        prev = root;
        inorder(root.right);
    }
    public void recoverTree(TreeNode root) {
        if(root==null){
            return;
        }
        prev = new TreeNode(Integer.MIN_VALUE);
        first = null;
        middle = null;
        last = null;
        inorder(root);
        if(first!=null && last!=null){
            int temp = first.val;
            first.val = last.val;
            last.val = temp;
        }
        else if(first!=null && middle!=null){
            int temp = first.val;
            first.val = middle.val;
            middle.val = temp;
        }
    }
}