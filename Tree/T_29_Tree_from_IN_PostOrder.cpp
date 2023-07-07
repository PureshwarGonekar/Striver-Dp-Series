// Problem -  https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/988540485/
//CN https://www.codingninjas.com/studio/problems/construct-a-binary-tree-from-preorder-and-inorder-traversal_920539


/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/

 TreeNode<int>* constructTree(vector < int > & postorder, int postStart, int postEnd, vector 
 < int > & inorder, int inStart, int inEnd, map < int, int > & mp) {
  if (postStart > postEnd || inStart > inEnd) return NULL;

  TreeNode<int>* root = new  TreeNode<int>(postorder[postEnd]);
  int elem = mp[root -> data];
  int numLeft = elem - inStart;

  root -> left = constructTree(postorder, postStart, postStart + numLeft-1, inorder,
  inStart, elem - 1, mp);
  root -> right = constructTree(postorder, postStart + numLeft, postEnd-1, inorder, 
  elem + 1, inEnd, mp);

  return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	int postStart = 0, postEnd = postOrder.size() - 1;
     int inStart = 0, inEnd = inOrder.size() - 1;

     map < int, int > mp;
     for (int i = inStart; i <= inEnd; i++) {
     mp[inOrder[i]] = i;
     }

     return constructTree(postOrder, postStart, postEnd, inOrder, inStart, inEnd, mp);
}