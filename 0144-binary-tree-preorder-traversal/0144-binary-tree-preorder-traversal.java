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
    public void solve(List<Integer> preorderList, TreeNode root){
        if(root==null){
            return;
        }
        preorderList.add(root.val);
        solve(preorderList, root.left);
        solve(preorderList, root.right);
    }
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> preorderList = new ArrayList<>();
        solve(preorderList, root);
        return preorderList;
    }
}