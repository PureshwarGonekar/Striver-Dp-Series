// Problem - https://leetcode.com/problems/recover-binary-search-tree/

class Solution {
	TreeNode* firstMistake, *secondMistake, *pre;
public:
	void recoverTree(TreeNode* root) {
		pre = new TreeNode(INT_MIN);
		inorder(root);
		swap(firstMistake->val, secondMistake->val);
	}

	void inorder(TreeNode* root) {
		if(root == nullptr) 
			return;

		inorder(root->left);

		if(firstMistake == nullptr && root->val < pre->val)
			firstMistake = pre;
		if(firstMistake != nullptr && root->val < pre->val)
			secondMistake = root;
		pre = root;

		inorder(root->right);
	}
};