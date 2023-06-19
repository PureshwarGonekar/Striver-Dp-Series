//Problem - https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349

//Recusion
int minSumPath(int i,int j,vector< vector< int> > &grid) {
	if(i==0 && j==0) return grid[0][0];
    if(i<0 || j<0) return 1e9;
    int up = grid[i][j] + minSumPath(i-1,j,grid);
    int left = grid[i][j] + minSumPath(i,j-1,grid);

    return min(up,left);
}
int minSumPath(vector<vector<int>> &grid) {
    int m=grid.size();
    int n=grid[0].size();
    return minSumPath(m-1,n-1,grid);
}

//Memorization
int minSumPath(int i,int j,vector< vector< int> > &grid,vector<vector<int>> &dp) {
	if(i==0 && j==0) return grid[0][0];
    if(i<0 || j<0) return 1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    int up = grid[i][j] + minSumPath(i-1,j,grid,dp);
    int left = grid[i][j] + minSumPath(i,j-1,grid,dp);

    return min(up,left);
}
int minSumPath(vector<vector<int>> &grid) {
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return minSumPath(m-1,n-1,grid,dp);
}

//Tabulation
int mod= (int)(1e9+7);
int minSumPath(vector<vector<int>> &grid){
	int m=grid.size();
    int n=grid[0].size();
	int dp[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
            if(i==0 && j==0) dp[0][0]= grid[i][j];
            else{
                int up=grid[i][j];
                if(i>0) up+= dp[i-1][j];
                else up+= 1e9;

                int left= grid[i][j];
                if(j>0) left += dp[i][j-1];
                else left += 1e9;

                dp[i][j]= min(up,left);
            }
		}
	}
	return dp[m-1][n-1];

}

//Space Optimization
int mazeObstacles(int m, int n,vector<vector<int>> &mat) {
	// Write your code here.
	vector<int> prev(n,0);
	for(int i=0;i<m;i++){
        vector<int> temp(n,0);
		for(int j=0;j<n;j++){
			if(i==0 && j==0) temp[j]=grid[i][j];
            else{
                int up=grid[i][j];
                if(i>0) up+= prev[j]; //up row
                else up+= 1e9;

                int left= grid[i][j];
                if(j>0) left += temp[j-1]; // down row
                else left += 1e9;

                temp[j]= min(up,left);
            }
		}
        prev=temp;
	}
	return prev[n-1];

}

