// Problem - https://www.codingninjas.com/studio/problems/spiral-order-traversal-of-a-binary-tree_630521

vector<vector<int>> zigzaglevelOrder(Treelode* root) {
    vector<vector<int>> result;
    if (root == NULL) {
        return result;
    }

    queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);
    bool leftToRight = true;

    while( !nodesQueue.empty()) {
        int size = nodesQueue.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++) {
            TreeNode* node = nodesQueue.front();
            nodesQueue.pop();

            //Find position to Fill node's value
            int index = (leftToRight) ? i: (size - 1-i);
            row[index] = node->val;
            if(node->left){
                nodesQueue.push(node->left);
            }
            if (node->right) {
                nodesQueue.push(node->right);
            }
        
        }
        // after this level
        leftToRight = !leftToRight;
        result.push(row);

    }
    return result;
}


// using stack and queue

vector<int> spiralOrder(BinaryTreeNode<int> *root)
{
    vector<int> result;
	if(root==NULL)
        return result;
	queue<BinaryTreeNode<int>*> pendingNodes;
    stack<BinaryTreeNode<int>*> st;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    
    int level=1;
    while(true){
        BinaryTreeNode<int> *front=pendingNodes.front();
        pendingNodes.pop();
        if(front==NULL){
            if(st.empty())
                return result;
            level++;
            if(level%2==0){ // even - right to left
                while(!st.empty()){
                    BinaryTreeNode<int> *top= st.top();
                    st.pop();
                    if(top->right!=NULL)
                    	pendingNodes.push(top->right);
                    if(top->left!=NULL)
                        pendingNodes.push(top->left);
                }
            }
            else{ // odd - left to right
                while(!st.empty()){
                    BinaryTreeNode<int> *top= st.top();
                    st.pop();
                    if(top->left!=NULL)
                        pendingNodes.push(top->left);
                    if(top->right!=NULL)
                    	pendingNodes.push(top->right);
                }
            }
            pendingNodes.push(NULL);
            cout<<endl;
        }
        else{
            result.push_back(front->data);
            st.push(front);
        }
    }
    return result;
}
