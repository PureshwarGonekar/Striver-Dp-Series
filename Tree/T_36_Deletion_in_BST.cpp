// Problem - https://www.codingninjas.com/studio/problems/delete-node-in-bst_920381

// Leetcode - https://leetcode.com/problems/delete-node-in-a-bst/submissions/

#include <bits/stdc++.h> 
/*************************************************************
    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/

BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* node, int key){
    if(node==NULL)
        return NULL;
    if(node->data==key){
        if(node->left==NULL && node->right==NULL){
            delete node;
            return NULL;
        }
        else if(node->left==NULL && node->right!=NULL){  // Don't have left 
            BinaryTreeNode<int> *rightSubTree=node->right;
            node->right=NULL;
            delete node;
            return rightSubTree;
        }
        else if(node->right==NULL && node->left!=NULL){ // Don't have right
            BinaryTreeNode<int> *leftSubTree= node->left;
            node->left=NULL;
            delete node;
            return leftSubTree;
        }
        else{     // both left and right are not null 
            BinaryTreeNode<int>* minNode = node->right;
            while (minNode->left != NULL) {  // finding minimum from left subtree
                    minNode = minNode->left; 
            }
            int rightMin = minNode->data;
            node->data = rightMin; // replace the curr data with minNode data
            node->right = deleteNode(node->right,rightMin);
            return node;
        }
    }
    else if(node->data > key){
        node->left=deleteNode(node->left,key);
        return node;
    }else{
        node->right=deleteNode(node->right,key);
        return node;
    }
}

//Iterative Approch
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val == key) {
            return helper(root);
        }
        TreeNode *dummy = root;
        while (root != NULL) {
            if (root->val > key) {
                if (root->left != NULL && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }
    TreeNode* helper(TreeNode* root) {
            if (root->left == NULL) 
            {
                return root->right;
            } 
            else if (root->right == NULL)
            {
                return root->left;
            } 
            TreeNode* rightChild = root->right;
            TreeNode* lastRight = findLastRight(root->left);
            lastRight->right = rightChild;
            return root->left;
    }
    TreeNode* findLastRight(TreeNode* root) {
        if (root->right == NULL) {
            return root;
        }
        return findLastRight(root->right);
    }
};



//img example - file:///C:/Users/pures/OneDrive/Pictures/Screenshots/deletion%20in%20BST.png