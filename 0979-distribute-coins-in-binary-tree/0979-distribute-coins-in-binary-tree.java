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
    private int moves;
    public int solveDistributeCoins(TreeNode root){
        if(root == null){
            return 0;
        }
        
        int left = solveDistributeCoins(root.left);
        int right = solveDistributeCoins(root.right);
        
        moves = moves + (Math.abs(left) + Math.abs(right));
        
        return (left + right + root.val- 1);
    }
    public int distributeCoins(TreeNode root) {
        moves = 0;
        solveDistributeCoins(root);
        return moves;
    }
}