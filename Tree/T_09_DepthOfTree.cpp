#include<iostream>
using namespace std;


void DepthOFTree(BinaryTreeNode<int> *root)[
    if(root == NULL) return 0;

    return max(DepthOFTree(root->left), DepthOFTree(root->right)) +1;
]
int main(){
    
    return 0;
}