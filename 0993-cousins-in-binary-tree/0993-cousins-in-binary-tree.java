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
    int xDepth;
    int yDepth;
    TreeNode xParent;
    TreeNode yParent;
    public void findDepthAndParent(TreeNode root, TreeNode parent, int x, int y, int depth){
        if(root == null){
            return;
        }
        
        if(root.val == x){
            xDepth = depth;
            xParent = parent;
        }
        else if(root.val == y){
            yDepth = depth;
            yParent = parent;
        }
        findDepthAndParent(root.left, root, x, y, depth+1);
        findDepthAndParent(root.right, root, x, y, depth+1);
    }
    public boolean isCousins(TreeNode root, int x, int y) {
        xDepth = -1;
        yDepth = -1;
        xParent = null;
        yParent = null;
        
        findDepthAndParent(root, null, x, y, 0);
        
        if(xDepth == yDepth && xParent != yParent){
            return true;
        }
        else{
            return false;
        }
    }
}