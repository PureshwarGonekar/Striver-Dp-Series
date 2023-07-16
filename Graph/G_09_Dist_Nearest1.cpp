// Problem- https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-of-nearest-cell-having-1


//T.C. = O(N x M) + O(N x M x 4) ~ O(N x M)
//S.C. = O(N x M) 

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    bool check(int i, int j, int n, int m){
        if(i>=0 && j>=0 && i<n && j<m ) return true;
        return false;
    }
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n= grid.size();
	    int m= grid[0].size();
	    vector<vector<int>> vis(n,vector<int>(m,0));
	    vector<vector<int>> dist(n,vector<int>(m,0));
	    queue< pair< pair<int,int>,int > > q;
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            if(grid[i][j]==1){
	                q.push({{i,j},0});
	            }
	        }
	    }
	    
	    while(!q.empty()){
	        int row= q.front().first.first;
	        int col= q.front().first.second;
	        int distance= q.front().second;
	        
	        q.pop();
	        dist[row][col]=distance;
	        
	        int dr[] = {-1,0,1,0};
	        int dc[] = {0,1,0,-1};
	        for(int k=0;k<4;k++){
	            int nrow= row + dr[k];
	            int ncol= col + dc[k];
	            if(check(nrow,ncol,n,m) && !vis[nrow][ncol] && grid[nrow][ncol]==0){
	                vis[nrow][ncol]=1;
	                q.push({{nrow,ncol},distance+1});
	            }
	        }
	    }
	    return dist;
	}
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}