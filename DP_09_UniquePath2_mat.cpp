//Problem - https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241

//Recusion
int uniquePaths1(int m,int n,int i,int j,vector< vector< int> > &mat) {
	// Write your code here.
	if(i>m || j>n) return 0;
	if(i==m-1 && j== n-1) return 1;
    if(i<m && j<n && mat[i][j]==-1) return 0;

	int a= uniquePaths1(m,n,i+1,j,mat);
	int b= uniquePaths1(m,n,i,j+1,mat);
	return a+b;

}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    return uniquePaths1(n,m,0,0,mat);
}


//Tabulation
int mod= (int)(1e9+7);
int mazeObstacles(int m, int n,vector< vector< int> > &mat) {
	// Write your code here.
	vector<vector<int>> dp(m,vector<int>(n,0));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
            if(mat[i][j]==-1) dp[i][j]=0;
            else if(i==0 && j==0) dp[0][0]=1;
            else{
                int up=0,left=0;
                if(i>0) up= dp[i-1][j];
                if(j>0) left = dp[i][j-1];

                dp[i][j]=(up +left)%mod;
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
			if(mat[i][j] == -1) temp[j]=0;
            else if(i==0 && j==0) temp[j]=1;
            else{
                int up=0,left=0;
                if(i>0) up= prev[j];
                if(j>0) left = prev[j-1];

                temp[j]= (up +left)%mod;
            }
		}
        prev=temp;
	}
	return prev[n-1];

}

