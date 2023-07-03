// Same as Diameter ques

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