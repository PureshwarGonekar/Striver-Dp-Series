// Leetcode - https://leetcode.com/problems/maximum-width-of-binary-tree/submissions/986852448/

int widthOfBinaryTree(TreeNode * root) {
    if (!root) return 0;
    int ans = 0;
    queue < pair < TreeNode * , int >> q;
    q.push({root,0});
    while (!q.empty()) {
        int size = q.size();
        int curMin = q.front().second;
        int leftMost, rightMost;
        for (int i = 0; i < size; i++) {
            int cur_id = q.front().second - curMin; // subtracted to prevent integer overflow
            TreeNode * temp = q.front().first;
            q.pop();
            if (i == 0) leftMost = cur_id;
            if (i == size - 1) rightMost = cur_id;
            if (temp -> left)
                q.push({temp -> left,(long long)cur_id * 2 + 1}); // cur_id*2 +1 then it convert to INT_Max 
            if (temp -> right)
                q.push({temp -> right,(long long)cur_id * 2 + 2});
        }
        ans = max(ans, rightMost - leftMost + 1);
    }
    return ans;
}


// Coding Ninjas - https://www.codingninjas.com/studio/problems/maximum-width-in-binary-tree_763671

//In this we only max no of non-null node comparing each level using Level order Traversal
int getMaxWidth(TreeNode<int> *root)
{
    if (!root) return 0;
    int ans = 0;
    queue <TreeNode<int> * > q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode<int> * temp = q.front();
            q.pop();
            if (temp -> left)
                q.push(temp -> left); // cur_id*2 +1 then it convert to INT_Max 
            if (temp -> right)
                q.push(temp -> right);
        }
        ans = max(ans, size);
    }
    return ans;
}