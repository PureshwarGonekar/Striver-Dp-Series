// Problem - https://www.interviewbit.com/problems/path-to-given-node/

bool getPath(TreeNode *root, vector<int> &arr, int x) {
    if (root==NULL)
        return false;
    arr.push_back(root->val);   
    if (root->val == x)   
        return true;

    if (getPath(root->left, arr, x) ||
        getPath(root->right, arr, x))
        return true;
    arr.pop_back();
    return false;  
}
vector<int> solve(TreeNode* A, int B) {
    vector<int> arr; 
    if(A == NULL) {
        return arr; 
    }
    getPath(A, arr, B);
    return arr; 
}

// Other way
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    if(A== NULL) return ans;
    if(A->val == B){
        ans.push_back(B);
        return ans;
    }
    
    vector<int> rem1 = solve(A->left,B);
    if(rem1.size() > 0){
        ans.push_back(A->val);
        ans.insert(ans.end(),rem1.begin(),rem1.end());
        return ans;
    }
    
    vector<int> rem2 = solve(A->right,B);
    if(rem2.size() > 0){
        ans.push_back(A->val);
        ans.insert(ans.end(),rem2.begin(),rem2.end());
        return ans;
    }
    return ans;
}
