//Problem - https://leetcode.com/problems/insert-into-a-binary-search-tree/submissions/990894313/
//CN - https://www.codingninjas.com/studio/problems/insert-into-a-binary-search-tree_1279913

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == NULL ){
        TreeNode* node = new TreeNode(val);
        return node;
    }
    if(val < root->val){
        root->left = insertIntoBST(root->left,val);
    }
    else{
        root->right = insertIntoBST(root->right,val);
    }
    return root;
}

// Iterative Approch
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == NULL) return new TreeNode(val);
    TreeNode *cur = root;
    while(true) {
        if(cur->val <= val) {
            if(cur->right != NULL) cur = cur->right;
            else {
                cur->right = new TreeNode(val);
                break;
            }
        } else {
            if(cur->left != NULL) cur = cur->left;
            else {
                cur->left = new TreeNode(val);
                break;
            }
        }
    }
    return root;
}