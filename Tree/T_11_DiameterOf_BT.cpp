
// Naive Bayes Approch T.C = O(N^2)
int findHeight(BinaryTreeNode<int> *root){
    if(root == NULL) return 0;

    int lh = findHeight(root->left);
    int rh = findHeight(root->right);
    return max(lh, rh) +1;
}

int diameter(BinaryTreeNode<int> *root){
    if(root == NULL){
        return 0;
    }

    int option1 = findHeight(root->left) + findHeight(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max({option1, option2, option3});
}

// 2nd Approch T.C = O(N)

int findMaxPath(TreeNode *root, int & maxi){
    if(root== NULL) return 0;

    int lh = findMaxPath(root->left,maxi);
    int rh = findMaxPath(root->right,maxi);

    maxi= max(maxi, (lh+rh));

    return 1 + max(lh,rh);
}
int diameterOfBinaryTree(TreeNode* root) {
    int maxi =0;
    findMaxPath(root,maxi);  
    return maxi;
}