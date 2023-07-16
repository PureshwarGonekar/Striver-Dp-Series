//Problem - https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-distinct-islands


//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool check(int i, int j, int n, int m){
        if(i>=0 && j>=0 && i<n && j<m ) return true;
        return false;
    }
    void dfs(int row,int col, int n, int m, vector<vector<int>> &grid, vector<vector<int>>& vis, 
    vector<pair<int,int>> &shape,int row0,int col0){
        
        vis[row][col] =1;
        shape.push_back({row-row0, col-col0});
        
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        
        for(int k=0;k<4;k++){
            int nrow= row + dr[k];
            int ncol= col + dc[k];
            if(check(nrow,ncol,n,m) && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                dfs(nrow,ncol,n,m,grid,vis,shape,row0,col0);
            }
        }   
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>> > uniqueIslands;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> shape;
                    dfs(i,j,n,m,grid,vis,shape,i,j);
                    uniqueIslands.insert(shape);
                }
            }
        }
        
        return uniqueIslands.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends