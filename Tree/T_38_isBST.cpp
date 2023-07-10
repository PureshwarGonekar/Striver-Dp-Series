// Problem - https://leetcode.com/problems/validate-binary-search-tree/

/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/
#include<queue>
/*
bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root==NULL)
        return false;
    queue<BinaryTreeNode<int>*> pendingNodes;
    queue<bool> subtree;
    pendingNodes.push(root);
    
    while(!pendingNodes.empty()){
        BinaryTreeNode<int> *front= pendingNodes.front();
        pendingNodes.pop();
        int leftMax = root->data
		int rightMin = root->data;
        if(front->left!=NULL){
            if(front->left->data < front->data && front->left->data < leftMax)
            	pendingNodes.push(front->left);
            	subtree.push()
            else
                return false;
        }
        if(front->right!=NULL){
            if( front->right->data >= front->data)
            	pendingNodes.push(front->right);
            else
                return false;
        }
    }
    return true;
}

*/
#include<climits>

//2nd Approch --> T.C. O(n *h)
int maximum(BinaryTreeNode<int>* root) {
    if (root == NULL) { 
        return INT_MIN; 
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}
int minimum(BinaryTreeNode<int>* root) {
    if (root == NULL) { 
    	return INT_MAX; 
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}
bool isBST(BinaryTreeNode<int>* root) {
    if (root == NULL) { 
        return true;
    }
    int leftMax = maximum(root->left); 
    int rightMin = minimum(root->right); 
    bool output = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
    return output;
}

//3rd Approch T.C. = O(N)
bool isValidBST(TreeNode* root,int minVal=INT_MIN, int maxVal=INT_MAX) {
    if (root == NULL) return true;
    if (root->val >= maxVal || root->val <= minVal) return false;
    return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
    
}