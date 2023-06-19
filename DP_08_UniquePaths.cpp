// Problem - https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470

#include <bits/stdc++.h> 
int uniquePaths1(int m, int n,int i=0,int j=0) {
	// Write your code here.
	if(i>m || j>n) return 0;
	if(i==m-1 && j== n-1){
		return 1;
	}

	int a= uniquePaths1(m,n,i+1,j);
	int b= uniquePaths1(m,n,i,j+1);
	return a+b;

}
//Memorization
int uniquePaths(int m, int n,int i,int j,vector<vector<int>> &dp) {
	// Write your code here.
	if(i>m || j>n) return 0;
	if(i==m-1 && j== n-1){
		return 1;
	}
	if(dp[i][j]!=-1) return dp[i][j];
	int a= uniquePaths(m,n,i+1,j,dp);
	int b= uniquePaths(m,n,i,j+1,dp);
	return dp[i][j]=a+b;

}

int uniquePaths(int i, int j,vector<vector<int>> &dp) {
	// Write your code here.
	if(i<0 || j<0) return 0;
	if(i==0 && j==0){
		return 1;
	}
	if(dp[i][j]!=-1) return dp[i][j];
	int a= uniquePaths(i-1,j,dp);
	int b= uniquePaths(i,j-1,dp);
	return dp[i][j]=a+b;

}


// Tabulation
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>> dp(m,vector<int>(n,1));
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			dp[i][j]= dp[i-1][j]+dp[i][j-1];
		}
	}
	return dp[m-1][n-1];

}

//or 
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>> dp(m,vector<int>(n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
            if(i==0 && j==0) dp[0][0]=1;
            else{
                int up=0,left=0;
                if(i>0) up= dp[i-1][j];
                if(j>0) left = dp[i][j-1];

                dp[i][j]=up +left;
            }
		}
	}
	return dp[m-1][n-1];

}

//Space Optimization
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<int> prev(n,0);
	for(int i=0;i<m;i++){
        vector<int> temp(n,0);
		for(int j=0;j<n;j++){
            if(i==0 && j==0) dp[0][0]=1;
            else{
                int up=0,left=0;
                if(i>0) up= prev[j];
                if(j>0) left = prev[j-1];

                temp[j]=up +left;
            }
		}
        prev=temp;
	}
	return dp[m-1][n-1];

}