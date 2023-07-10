//Problem - https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/991024263/

// Time Complexity: O(min(K,N))

// Space Complexity: O(min(K,N))
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int &k) { // inorder traversl --->  left root right
        if(root==NULL)
            return -1;
        int left=kthSmallest(root->left,k);
        if(left!=-1)
            return left;
        k--;
        if(k==0)
            return root->val;
        
        return kthSmallest(root->right,k);
    }
    int kthLargest(TreeNode* root, int &k) { // right root left
        if(root==NULL)
            return -1;
        int right = kthLargest(root->right,k);
        if(right!=-1)
            return right;
        k--;
        if(k==0)
            return root->val;
        
        return kthLargest(root->left,k);
    }
};