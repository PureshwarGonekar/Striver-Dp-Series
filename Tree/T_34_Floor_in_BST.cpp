// Problem - https://www.codingninjas.com/studio/problems/floor-from-bst_920457

// floor of an integer is the closest integer smaller than or equal to a given number 

int findFloor(BinaryTreeNode<int> *root, int x){
    int floor =-1;
    while(root){
        if(x  == root->val){
            floor = root->val;
            return floor;
        } 
        else if(x<root->val){
            root = root->left;
        }
        else{
            floor = root->val;
            root = root->right;
        } 
            
    }
    return floor;
}   