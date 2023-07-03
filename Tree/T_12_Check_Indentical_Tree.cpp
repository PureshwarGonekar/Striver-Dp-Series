// Problem - https://www.codingninjas.com/studio/problems/identical-trees_799364

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here. 
    if(root1 == NULL && root2 == NULL) return true;
    else if(root1 == NULL || root2 == NULL) return false;

    if(root1->data != root2->data ) return false;
    
    return identicalTrees(root1->left,root2->left) && identicalTrees(root1->right,root2->right);
}

// shorter way of writing code
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==NULL || q== NULL)
        return (p==q);

    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}