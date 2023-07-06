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
    public void inorder(TreeNode root, TreeNode[] prev, TreeNode[] first, TreeNode[] middle, TreeNode[] last) {
        if (root == null) {
            return;
        }
        inorder(root.left, prev, first, middle, last);
        if (prev[0] != null && prev[0].val > root.val) {
            if (first[0] == null) {
                first[0] = prev[0];
                middle[0] = root;
            } else {
                last[0] = root;
            }
        }
        prev[0] = root;
        inorder(root.right, prev, first, middle, last);
    }

    public void recoverTree(TreeNode root) {
        if (root == null) {
            return;
        }
        TreeNode[] prev = {null};
        TreeNode[] first = {null};
        TreeNode[] middle = {null};
        TreeNode[] last = {null};
        inorder(root, prev, first, middle, last);
        if (first[0] != null && last[0] != null) {
            int temp = first[0].val;
            first[0].val = last[0].val;
            last[0].val = temp;
        } else if (first[0] != null && middle[0] != null) {
            int temp = first[0].val;
            first[0].val = middle[0].val;
            middle[0].val = temp;
        }
    }
}