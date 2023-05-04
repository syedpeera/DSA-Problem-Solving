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
    void printRightView(List<TreeNode> ans, TreeNode root, int level){
        if(root==null){
            return;
        }
        if(ans.size()==level){
            ans.add(root);
        }
        printRightView(ans, root.right, level+1);
        printRightView(ans, root.left, level+1);
    }
    public List<Integer> rightSideView(TreeNode root) {
        List<TreeNode> ans = new ArrayList<>();
        printRightView(ans, root, 0);
        List<Integer> result = new ArrayList<>();
        for(TreeNode temp: ans){
            result.add(temp.val);
        }
        return result;
    }
}