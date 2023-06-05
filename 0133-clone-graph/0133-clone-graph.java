/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    public Node cloneGraph(Node node) {
        if(node==null){
            return null;
        }
        //Original Node, Clone Node
        Map<Node, Node> map = new HashMap<>();
        Queue<Node> queue = new ArrayDeque<>();
        queue.add(node);
        map.put(node, new Node(node.val, new ArrayList<>()));
        while(!queue.isEmpty()){
            Node curr = queue.poll();
            for(Node neighbor: curr.neighbors){
                if(!map.containsKey(neighbor)){
                    map.put(neighbor, new Node(neighbor.val, new ArrayList<>()));
                    queue.add(neighbor);
                }
                Node cloneNode = map.get(curr);
                Node neighborNode = map.get(neighbor);
                cloneNode.neighbors.add(neighborNode);
            }
        }
        return map.get(node);
    }
}