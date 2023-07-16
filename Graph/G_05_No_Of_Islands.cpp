//Problem - gfg = https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find_the_number_of_islands

//Time Complexity => O(N^2)
//Space Complexity => O(N^2)
class Solution {
    void bfs(int row,int col,vector<vector<char>>& grid, vector<vector<bool>> &vis){
        int n = grid.size();
        int m = grid[0].size();
        
        vis[row][col] = true;
        queue<pair<int,int>> q;
        q.push({row,col});
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int delrow=-1; delrow<=1; delrow++){
                for(int delcol=-1; delcol<=1; delcol++){
                    int nrow= row + delrow;
                    int ncol = col+ delcol;
                    
                    if(nrow >=0 && nrow <n && ncol >=0 && ncol <m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                        vis[nrow][ncol]=true;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
  public:
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        vector<vector<bool>> visited(n, vector<bool>(m,false));

        for (int i = 0; i < n; i++) {
            for(int j=0; j<m; j++){
                
                if(grid[i][j]=='1' && !visited[i][j]) {
                    islands++;
                    bfs(i,j,grid, visited);
                }
            }
        }

        return islands;
    }
};