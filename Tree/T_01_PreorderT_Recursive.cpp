/**
 * Definition for a binary tree node.
 * template <typename T>
 * struct TreeNode {
 *     T val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(T x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };

*/

// Preorder ==> root left right

void preorder(TreeNode<int> *root){
    if(root == NULL)
        return;
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}