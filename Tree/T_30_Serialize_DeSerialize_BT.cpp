//Problem - https://leetcode.com/problems/serialize-and-deserialize-binary-tree/submissions/990248644/

//CN - https://www.codingninjas.com/studio/problems/serialise-deserialise-a-binary-tree_920328

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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string ans="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front == NULL) ans.append("null,");
            else{
                ans.append(to_string(front->val)+ ",");
            }

            if(front!=NULL){
                q.push(front->left);
                q.push(front->right);
            }

        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        string res="";
        stringstream s(data);
        string str;
        getline(s,str,',');

        TreeNode* root= new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            getline(s,str,',');
            
            if(str=="null"){
                node->left=NULL;
            }
            else{
                TreeNode* lnode= new TreeNode(stoi(str));
                node->left= lnode;
                q.push(lnode);
            }

            getline(s,str,',');
            if(str== "null"){
                node->right=NULL;
            }
            else{
                TreeNode* rnode= new TreeNode(stoi(str));
                node->right= rnode;
                q.push(rnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));