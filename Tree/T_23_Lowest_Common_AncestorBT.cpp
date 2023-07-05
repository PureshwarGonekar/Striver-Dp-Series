//Problem - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/986795442/


// T.C. = O(N)   S.C. = O(N)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL || root == p || root == q) return root;

    TreeNode* Left = lowestCommonAncestor(root->left,p,q);
    TreeNode* Right = lowestCommonAncestor(root->right,p,q);

    if(Left == NULL){ // both are null and if only left is null
        return Right;
    }
    else if(Right==NULL){ // only right is null
        return Left;
    }
    else{ // both are not null means p & q found on left & right subtree
        return root;
    }
    
}

//Binary Search Tree (CN) - https://www.codingninjas.com/studio/problems/lca-in-a-bst_981280
// Iterative Approch
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    TreeNode<int>* curr = root;
    
    while(curr != NULL){
        if(curr->data > P->data && curr->data > Q->data) curr = curr->left;
        else if(curr->data < P->data && curr->data < Q->data) curr = curr->right;
        else return curr;
    }

    return NULL;
}