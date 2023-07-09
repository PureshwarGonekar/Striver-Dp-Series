//Problem - https://leetcode.com/problems/flatten-binary-tree-to-linked-list/submissions/990404619/
// CN  - https://www.codingninjas.com/studio/problems/flatten-binary-tree-to-linked-list_1112615

//Recursive Approch T.C. = O(N) S.C. = O(N)
node *prev = NULL;
void flatten(node * root) {
    if (root == NULL) return;

    flatten(root -> right);
    flatten(root -> left);

    root -> right = prev;
    root -> left = NULL;
    prev = root;
}

// Iterative Approch
 node * prev = NULL;
void flatten(node * root) {
    if (root == NULL) return;
    stack < node * > st;
    st.push(root);
    while (!st.empty()) {
        node * cur = st.top();
        st.pop();

        if (cur -> right != NULL) {
            st.push(cur -> right);
        }
        if (cur -> left != NULL) {
            st.push(cur -> left);
        }
        if (!st.empty()) {
            cur -> right = st.top();
        }
        cur -> left = NULL;
    }
}

// Anoter way - Using Intuition behind Morris Traversal.
 void flatten(node* root) {
    node* cur = root;
    while (cur)
    {
        if(cur->left)
        {
            node* pre = cur->left;
            while(pre->right)
            {
                pre = pre->right;
            }
            pre->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        }
        cur = cur->right;
    }
}
