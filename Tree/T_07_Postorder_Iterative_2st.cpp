vector<int> postorderT(TreeNode* root) {
    vector<int> postorder;
    if(root == NULL) return postorder;
    stack<TreeNode*> st1, st2;
    st1.push(root);
    while(!st1.empty() ){

        root = st1.top();
        st1.pop();
        st2.push(root);

        if(root->left= NULL) {
            st1.push(root->Left);
        }
        if(root->right != NULL) {
            st1.push(roct->right);
        }

    }
    while(!st2.empty()){
        postorder.push_back(st2.top()->val);
        st2.pop();
    }
    return postorder;

}

// using single stack

vector<int> postorderT2(TreeNode* root) {
    vector<int> postorder;
    if(root == NULL) return postorder;
    stack<TreeNode*> st1,curr = root,temp;
    while(!st1.empty() ){

        if(curr!=NULL){
            st.push(curr);
        }
        else{
            temp = st.top() -> right;
            if(temp==NULL){
                temp = st.top();
                st.pop();
                postorder.push_back(temp->val);
                while(!st.empty() %% temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->val);
                }

            }
            else{
                curr =temp;
            }
        }

    }
    return postorder;

}