// Problem Link - https://www.codingninjas.com/studio/problems/time-to-burn-tree_630563

BinaryTreeNode<int>* findNode(BinaryTreeNode<int>* root, int target){
    if(root == NULL) return NULL;
    if(root->data == target) return root;
    BinaryTreeNode<int>* Left = findNode(root->left, target);
    if(Left) return Left;

    return findNode(root->right, target);
}

void markParents(BinaryTreeNode<int>* root, unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &parent_track, BinaryTreeNode<int>* target) {
    queue<BinaryTreeNode<int>*> queue;
    queue.push(root);
    while(!queue.empty()) { 
        BinaryTreeNode<int>* current = queue.front(); 
        queue.pop();
        if(current->left) {
            parent_track[current->left] = current;
            queue.push(current->left);
        }
        if(current->right) {
            parent_track[current->right] = current;
            queue.push(current->right);
        }
    }
}
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> parent_track;

    BinaryTreeNode<int>* target = findNode(root,start);

    markParents(root, parent_track, target); 
    
    unordered_map<BinaryTreeNode<int>*, bool> visited; 
    queue<BinaryTreeNode<int>*> queue;
    queue.push(target);
    visited[target] = true;
    int time = -1;
    while(!queue.empty()) { 
        int size = queue.size();

        time++;
        for(int i=0; i<size; i++) {
            BinaryTreeNode<int>* current = queue.front(); queue.pop();
            if(current->left && !visited[current->left]) {
                queue.push(current->left);
                visited[current->left] = true;
            }
            if(current->right && !visited[current->right]) {
                queue.push(current->right);
                visited[current->right] = true;
            }
            if(parent_track[current] && !visited[parent_track[current]]) {
                queue.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }
    return time;
}