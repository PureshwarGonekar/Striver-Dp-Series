// Problem - https://leetcode.com/problems/count-complete-tree-nodes/

int countNodes(TreeNode* root) {
    if(root == NULL) return 0; 
    
    int lh = findHeight(root,true); 
    int rh = findHeight(root,false); 
    
    if(lh == rh) return (1<<lh) - 1; 
    
    return 1 + countNodes(root->left) + countNodes(root->right); 
}
int findHeight(TreeNode* node , bool isleft) {
    int H = 0; 
    while(node) {
        H++; 
        if(isleft)
            node = node->left; 
        else node = node->right;
    }
    return H; 
}