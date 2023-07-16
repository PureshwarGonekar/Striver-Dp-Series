// Problem - https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

// T.C => O(V + 2E) S.C. => O(N)
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detectCycle(int src,vector<int> adj[], int vis[] ){
        queue<pair<int,int>> q;
        q.push({src,-1});
        
        vis[src]=1;
        
        while(!q.empty()){
            int node = q.front().first;
            int parent= q.front().second;
            q.pop();
            
            for(auto it: adj[node]){
                if(vis[it] && parent!=it){
                    return true;
                }
                
                if(!vis[it]){
                    vis[it]= 1;
                    q.push({it,node});
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V]={0};
        for(int i=0; i< V; i++){
            if(!vis[i]){
                if(detectCycle(i,adj,vis)== true){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends



//Leetcode Problem - https://leetcode.com/problems/detect-cycles-in-2d-grid/description/

class Solution {
public:
    bool check(int i, int j, int n, int m){
        if(i>=0 && j>=0 && i<n && j<m ) return true;
        return false;
    }
    bool ans = false;
    void dfs(int i, int j, int parI, int parJ, vector<vector<char>>& grid, vector<vector<char>>&vis,int n, int m, char ch){
        vis[i][j] = 1;
        int a1[] = {1,-1,0,0};
        int a2[] = {0,0,1,-1};
        for(int k=0; k<4; k++){
            int r = i + a1[k];
            int c = j + a2[k];
            if(check(r,c,n,m) && vis[r][c] && grid[r][c] == ch && r != parI && c != parJ){
                ans = true;
                return;
            }
            else if(check(r,c,n,m) && !vis[r][c] && grid[r][c] == ch){
                dfs(r,c,i,j,grid,vis,n,m,ch);
            }
            
        }
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<char>>vis(n,vector<char>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j]){
                    dfs(i,j,-1,-1,grid,vis,n,m,grid[i][j]);
                }
            }
        }
        return ans;
    }
};