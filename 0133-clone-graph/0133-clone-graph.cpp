/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        //Original Node, Clone Node
        unordered_map<Node*, Node*> map;
        queue<Node*> q;
        q.push(node);
        map[node] = new Node(node->val);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            for(Node* neighbor: curr->neighbors){
                if(map.find(neighbor)==map.end()){
                    map[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                Node* cloneNode = map[curr];
                Node* neighborNode = map[neighbor];
                cloneNode->neighbors.push_back(neighborNode);
            }
        }
        return map[node];
    }
};