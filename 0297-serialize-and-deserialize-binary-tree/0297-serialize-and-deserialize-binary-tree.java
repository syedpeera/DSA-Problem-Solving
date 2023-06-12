/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {
    private static final String NULL_MARKER = "#";
    private static final String DELIMITER = ",";
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if(root==null){
            return "";
        }
        StringBuilder sb = new StringBuilder();
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            TreeNode curr = q.poll();
            if(curr==null){
                sb.append(NULL_MARKER).append(DELIMITER);
            }
            else{
                sb.append(curr.val).append(DELIMITER);
                q.add(curr.left);
                q.add(curr.right);
            }
        }
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if(data.equals("")){
            return null;
        }
        String  values[] = data.split(DELIMITER);
        Queue<TreeNode> q = new LinkedList<>();
        TreeNode root = new TreeNode(Integer.parseInt(values[0]));
        q.add(root);
        for(int i=1;i<values.length;i++){
            TreeNode parent = q.poll();
            if(!values[i].equals(NULL_MARKER)){
                TreeNode left = new TreeNode(Integer.parseInt(values[i]));
                parent.left = left;
                q.add(left);
            }
            if(!values[++i].equals(NULL_MARKER)){
                TreeNode right = new TreeNode(Integer.parseInt(values[i]));
                parent.right = right;
                q.add(right);
            }
        }
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));