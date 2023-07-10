// Problem - https://www.codingninjas.com/studio/problems/ceil-from-bst_920464

// Ceil of an integer is the closest integer greater than or equal to a given number 

int findCeil(BinaryTreeNode<int> *root, int x){
    int ceil =-1;
    while(root){
        if(x  == root->data){
            ceil = root->data;
            return ceil;
        } 
        else if(x<root->data){
            ceil = root->data;
            root = root->left;
        }
        else{
            root = root->right;
        } 
            
    }
    return ceil;
}