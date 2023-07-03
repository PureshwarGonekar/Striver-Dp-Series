// naive based approch T.C ==> O(N^2)
int findHeight(BinaryTreeNode<int> *root){
    if(root == NULL) return 0;

    return max(findHeight(root->left), findHeight(root->right)) +1;
}
bool check(BinaryTreenode<int> * root){
    if( root == NULL)
        return true;

    int lh = findHeight(root->left);
    int rh = findHeight(root->right);

    if(abs(lh-rh) >1) return false;

    return check(root->left) && check(root->right);
}

// 2nd Approch T.C ==> O(N)

int check(BinaryTreenode<int> * root){
    if( root == NULL) return 0;

    int lh = check(root->left);
    int rh = check(root->right);

    if(lh==-1 || rh==-1) return -1;
    if(abs(lh-rh) >1) return -1;

    return max(lr,rh) +1 ;
}