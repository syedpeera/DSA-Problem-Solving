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
    int diameterOfBinaryTree(TreeNode root) {
        if(root==null){
            return 0;
        }   
        int dl = diameterOfBinaryTree(root.left);
        int dr = diameterOfBinaryTree(root.right);
        int curr = heightOfTree(root.left) + heightOfTree(root.right);
        return Math.max(curr, Math.max(dl, dr));
    }
    int heightOfTree(TreeNode root){
        if(root==null){
            return 0;
        }
        return 1+Math.max(heightOfTree(root.left), heightOfTree(root.right));
    }
}