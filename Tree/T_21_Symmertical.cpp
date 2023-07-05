// Problem CN - https://www.codingninjas.com/studio/problems/tree-symmetricity_630426
// Leetcode - https://leetcode.com/problems/symmetric-tree/submissions/

bool f(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2){
    if(root1== NULL  || root2==NULL) return root1==root2;
    if(root1->data != root2->data) return false;

    return f(root1->left,root2->right) && f(root1->right,root2->left);
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(root == NULL) return true;
        return f(root,root);
}