//same as prev problem

//Problem - https://practice.geeksforgeeks.org/problems/number-of-enclaves/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-enclaves

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        queue<pair<int,int>> q; 
        int n = grid.size(); 
        int m = grid[0].size(); 
        int vis[n][m] = {0}; 
        // traverse boundary elements
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                // first row, first col, last row, last col 
                if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                    // if it is a land then store it in queue
                    if(grid[i][j] == 1) {
                        q.push({i, j}); 
                        vis[i][j] = 1; 
                    }
                }
            }
        }
        
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, +0, -1}; 
        
        while(!q.empty()) {
            int row = q.front().first; 
            int col = q.front().second; 
            q.pop(); 
            
            // traverses all 4 directions
            for(int i = 0;i<4;i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i]; 
                // check for valid coordinates and for land cell
                if(nrow >=0 && nrow <n && ncol >=0 && ncol < m 
                && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1; 
                }
            }
            
        }
        
        int cnt = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                // check for unvisited land cell
                if(grid[i][j] == 1 & vis[i][j] == 0) 
                    cnt++; 
            }
        }
        return cnt; 
    }
};


//dfs traversal

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    bool check(int i, int j, int n, int m){
        if(i>=0 && j>=0 && i<n && j<m ) return true;
        return false;
    }
    void dfs(int row,int col, int n, int m, vector<vector<int>> &grid, vector<vector<int>>& vis){
        
        vis[row][col] =1;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for(int k=0;k<4;k++){
            int nrow= row + dr[k];
            int ncol= col + dc[k];
            if(check(nrow,ncol,n,m) && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                dfs(nrow,ncol,n,m,grid,vis);
            }
        }
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n= grid.size();
        int m= grid[0].size();
        
       vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if( (i==0 || i==n-1|| j==0 || j==m-1) && grid[i][j]==1){
                    dfs(i,j,n,m,grid,vis);
                }
            }
        }
        
        int count=0;
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(  grid[i][j]== 1 && !vis[i][j]){
                    count++;
                }
            }
        }
        
        return count;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends