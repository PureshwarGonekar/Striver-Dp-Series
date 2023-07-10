//problem - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/991149585/

// Recursion - T.C. = O(h) S.C. = O(h)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return NULL;
    int curr = root->val; 
    if(curr < p->val && curr < q->val) {
        return lowestCommonAncestor(root->right, p, q);
    }
    if(curr > p->val && curr > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    }
    return root;
}

// Iterative Approch - T.C. = O(h) S.C. = O(1)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* curr = root;

    while(curr != NULL){
        if(curr->val > p->val && curr->val > q->val) curr = curr->left;
        else if(curr->val < p->val && curr->val < q->val) curr = curr->right;
        else return curr;
    }

    return NULL;
}