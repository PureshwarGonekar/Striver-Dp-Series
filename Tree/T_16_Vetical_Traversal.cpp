//Problem CN- https://www.codingninjas.com/studio/problems/vertical-order-traversal_920533

// leetcode - https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/submissions/986629752/

vector<vector<int>> verticalOrderTraversal(TreeNode<int>* root) {
  map <int, map < int, multiset < int >>> nodes;
  queue < pair < TreeNode<int>* , pair < int, int >>> todo;
  todo.push({root, {0,0} }); 
  
  while (!todo.empty()) {
    auto p = todo.front();
    todo.pop();
    TreeNode<int>* temp = p.first;
    int x = p.second.first, y = p.second.second;
    nodes[x][y].insert(temp -> data); 

    if (temp -> left) {
        todo.push({temp -> left,{x - 1,y + 1}});
    }
    if (temp -> right) {
        todo.push({temp -> right,{x + 1,y + 1}});
    }
  }
  vector<vector<int>> ans;
  for (auto p: nodes) {
    vector < int > col;
    for (auto q: p.second) {
        col.insert(col.end(), q.second.begin(), q.second.end());
    }
    ans.push_back(col);
  }
  return ans;
}