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
    public void solve(List<Integer> inorderList, TreeNode root){
        if(root==null){
            return;
        }
        solve(inorderList, root.left);
        inorderList.add(root.val);
        solve(inorderList, root.right);
    }
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> inorderList = new ArrayList<>();
        solve(inorderList, root);
        return inorderList;        
    }
}