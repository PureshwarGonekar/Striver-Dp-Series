// Problem - https://www.codingninjas.com/studio/problems/binary-tree-maximum-path-sum_1280142

// Same as Diameter ques 
// T.C. O(N)
int findMaxPathSum(TreeNode<int> *root, int & maxi){
    if(root== NULL) return 0;

    int lh = max(0,findMaxPathSum(root->left,maxi)); // taking max for neglecting -ve val
    int rh = max(0,findMaxPathSum(root->right,maxi));

    maxi= max(maxi, (lh+rh+root->val));

    return root->val + max(lh,rh);
}
int maxPathSum(TreeNode<int>* root)
{
	int maxi = INT_MIN;
    findMaxPathSum(root,maxi);  
    return maxi;
}