
vectorcint> preorderTraversal(TreeNode* root) {
    vector<int> preorder;
    if(root == NULL) return preorder;

    stackeTreeNode*> st;
    st.push(root);
    while(!st.emptyO){
        root = st.top();
        st.pop();
        preorder.push_back(root->val);
        if(root->right != NULL)
            st.push(root->right);

        if(root->left!= NULL)
            st.push(root->Left);

    }
    return preorder;
}

 