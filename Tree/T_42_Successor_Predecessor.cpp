
//***********************Successor*********************
// In Binary Search Tree, Inorder Successor of an input node can also be defined as the node with the smallest key greater than the key of the input node.

//Iterativ Approch ---> T.C. = O(h) S.C. = O(1);
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* successor = NULL;
    
    while (root != NULL) {
        
        if (p->val >= root->val) {
            root = root->right;
        } else {
            successor = root;
            root = root->left;
        }
    }
    
    return successor;
}

// Recursion
void inorderSuccessor(TreeNode* root, TreeNode* p, TreeNode* &successor) {
    if(root==NULL) return;

    if(root->val > p->val) successor = root;
    if(root->val > val){
        inorderSuccessor(root->left,p,successor);
    }
    else{
        inorderSuccessor(root->right,p,successor);
    }
    
}


//***********************Predecessor *********************
/* Predecessor is the val which immediate lesser the given value(p)*/

//Iterativ Approch ---> T.C. = O(h) S.C. = O(1);
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* successor = NULL;
    
    while (root != NULL) {
        
        if (p->val >= root->val) {
            successor = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    
    return successor;
}
