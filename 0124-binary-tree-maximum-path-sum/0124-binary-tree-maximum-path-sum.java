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
    private int maxSum;
    public int solve(TreeNode root){
        if(root==null){
            return 0;
        }
        int left = solve(root.left);
        left = (left<0)?0:left;
        int right = solve(root.right);
        right = (right<0)?0:right;
        
        maxSum = Math.max(maxSum, left+right+root.val);
        
        return Math.max(left,right)+root.val;
    }
    public int maxPathSum(TreeNode root) {
        maxSum=Integer.MIN_VALUE;
        solve(root);
        return maxSum;
    }
}