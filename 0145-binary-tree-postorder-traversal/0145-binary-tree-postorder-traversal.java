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
    
    public void solve(List<Integer> postorderList, TreeNode root){
        if(root==null){
            return;
        }
        solve(postorderList, root.left);
        solve(postorderList, root.right);
        postorderList.add(root.val);
    }
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> postorderList = new ArrayList<>();
        solve(postorderList, root);
        return postorderList;    
    }
}