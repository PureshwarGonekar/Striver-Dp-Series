// Problem - https://leetcode.com/problems/search-in-a-binary-search-tree/submissions/990840039/
// CN - https://www.codingninjas.com/studio/problems/search-in-bst_1402878

//Recursion T.C. = O(logn)
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    if(root==NULL) return false;
    if(root->data == x) return true;
    else if(x < root->data) return searchInBST(root->left, x);
    else return searchInBST(root->right, x);
}

//Iterative method
TreeNode* searchBST(TreeNode* root, int val) {
    while(root != NULL && root->val != val){
        root = val<root->val? root->left:root->right;
    }
    return root;
}