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
    public int solveGoodNodes(TreeNode root, int maxValue){
        if(root == null){
            return 0;
        }
        
        int goodNodeCount = 0;
        if(root.val >= maxValue){
            goodNodeCount++;
            maxValue = root.val;
        }
        
        goodNodeCount = goodNodeCount + solveGoodNodes(root.left, maxValue);
        goodNodeCount = goodNodeCount + solveGoodNodes(root.right, maxValue);
        
        return goodNodeCount;
    }
    public int goodNodes(TreeNode root) {
        return solveGoodNodes(root, Integer.MIN_VALUE);
    }
}