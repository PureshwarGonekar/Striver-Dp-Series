// Problem - https://www.codingninjas.com/studio/problems/top-view-of-the-tree_799401


vector<int> getTopView(TreeNode<int> *root) {

    vector<int> ans;
    if(root == NULL) return ans;

    map <int,int> mp;
    queue <pair<TreeNode<int>* ,int>> todo;
    todo.push({root,0}); 
    
    while (!todo.empty()) {
        auto p = todo.front();
        todo.pop();
        TreeNode<int>* temp = p.first;
        int x = p.second;
        if(!mp.count(x)){  // if(mp.find(x) == mp.end() ) -->both works same
            mp[x] = temp->val;
        }

        if (temp -> left) {
            todo.push({temp -> left,x - 1});
        }
        if (temp -> right) {
            todo.push({temp -> right,x+1});
        }
    }
    for (auto p: mp) {
        ans.push_back(p.second);
    }
    return ans; 
}