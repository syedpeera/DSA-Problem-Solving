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
    int height(TreeNode root){
        if(root==null){
            return 0;
        }
        return 1+Math.max(height(root.left), height(root.right));
    }

    void printCurrentLevel(List<Integer> ans,TreeNode root, int level){
        if(root==null){
            return;
        }
        if(level==1){
            ans.add(root.val);
        }
        else if(level>1){
            printCurrentLevel(ans, root.left, level-1);
            printCurrentLevel(ans, root.right, level-1);
        }
    }

    List<List<Integer>> levelOrder(TreeNode root) {
        int h = height(root);
        List<List<Integer>> result = new ArrayList<>();
        for(int i=1;i<=h;i++){
            List<Integer> ans = new ArrayList<>();
            printCurrentLevel(ans, root, i);
            result.add(ans);
        }
        return result;
    }
}