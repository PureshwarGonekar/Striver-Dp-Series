// Problem - https://www.codingninjas.com/codestudio/problems/triangle_1229398

#include <bits/stdc++.h> 

//Recursion
int f(int i,int j,vector<vector<int>>& triangle,int n){
	if(i>=n || j>= i+1) return INT_MAX;
	if(i==n-1) return triangle[i][j];

	int a = triangle[i][j] + f(i+1,j,triangle,n);
	int b = triangle[i][j] + f(i+1,j+1,triangle,n);
	return min(a,b);

}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	return f(0,0,triangle,n);
}

 // Memorization
int f(int i,int j,vector<vector<int>>& triangle,int n,vector<vector<int>>& dp){
	if(i>=n || j>= i+1) return INT_MAX;
	if(i==n-1) return triangle[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    
	int a = triangle[i][j] + f(i+1,j,triangle,n,dp);
	int b = triangle[i][j] + f(i+1,j+1,triangle,n,dp);
	return dp[i][j]=min(a,b);

}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    vector<vector<int>> dp(n,vector<int>(n,-1));
	return f(0,0,triangle,n,dp);
}

// Tabulation
int minimumPathSum(vector<vector<int>>& triangle, int n){
	int dp[n][n]; 
    for(int j=0;j<n;i++){
        dp[n-1][j]= triangle[n-1][j];
    }

    for(int i=n-2;i>=0;i--){
        for(int j=0;j<i+1;j++){
            int a = triangle[i][j] + dp[i+1][j];
            int b = triangle[i][j] + dp[i+1][j+1];
            dp[i][j]=min(a,b);
        }
    }
	return dp[0][0];
}

// Space Optimization
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<int> front(n,0);
    for(int j=0;j<n;j++){
        front[j]= triangle[n-1][j];
    }

    for(int i=n-2;i>=0;i--){
        vector<int> temp(n,0);
        for(int j=0;j<i+1;j++){
            int a = triangle[i][j] + front[j];
            int b = triangle[i][j] + front[j+1];
            temp[j]=min(a,b);
        }
        front=temp;
    }
	return front[0];
}