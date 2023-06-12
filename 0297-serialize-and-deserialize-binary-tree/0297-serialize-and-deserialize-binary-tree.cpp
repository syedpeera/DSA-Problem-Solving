/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string NULL_MARKER="#";
    string DELIMITER=",";
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return "";
        }
        string serialized="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr==NULL){
                serialized += NULL_MARKER + DELIMITER;
            }
            else{
                serialized += to_string(curr->val) + DELIMITER;
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()){
            return NULL;
        }
        vector<string> values;
        string temp="";
        for(int i=0;i<data.size();i++){
            if(data[i]!=','){
                temp+=data[i];
            }
            else{
                values.push_back(temp);
                temp="";
            }
        }
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(values[0]));
        q.push(root);
        for(int i=1;i<values.size();i++){
            TreeNode* parent = q.front();
            q.pop();
            if(values[i]!=NULL_MARKER){
                TreeNode* left = new TreeNode(stoi(values[i]));
                parent->left = left;
                q.push(left);
            }
            if(values[++i]!=NULL_MARKER){
                TreeNode* right = new TreeNode(stoi(values[i]));
                parent->right = right;
                q.push(right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));