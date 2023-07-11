// Problem - https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

//1st approch
/*
    1. store the inorder in vector/array
    2. traverse the pointer at start and at end 
    T.C= O(N) S.C. O(N)
*/

//2nd Approch
/*
    1. make two iterator - next() {left root right} & before() {right root left}
    2. first take both next() before() and sum up
    3. if sum exceed call before() or if sum fall short call next() or if sum equal to given value(k) the return true;
    T.C= O(N) S.C. O(2*h)
*/


class BSTIterator {
    stack<TreeNode *> myStack;
    bool reverse = true; 
public:
    BSTIterator(TreeNode *root, bool isReverse) {
        reverse = isReverse; 
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tmpNode->right);
        else pushAll(tmpNode->left);
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node) {
        for(;node != NULL; ) {
             myStack.push(node);
             if(reverse == true) {
                 node = node->right; 
             } else {
                 node = node->left; 
             }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false; 
        BSTIterator l(root, false); 
        BSTIterator r(root, true); 
        
        int i = l.next(); 
        int j = r.next(); 
        while(i<j) {
            if(i + j == k) return true; 
            else if(i + j < k) i = l.next(); 
            else j = r.next(); 
        }
        return false; 
    }
};