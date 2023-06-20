//Problem - https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998

#include <bits/stdc++.h> 
int f(int i,int j,int m,int n,vector<vector<int>> &a){
    if(i>=m || j>= n) return INT_MIN;
    if(i==m-1) return a[i][j];

    int d= a[i][j] + f(i+1,j,m,n,a);
    int ld= a[i][j] + f(i+1,j-1,m,n,a);
    int rd= a[i][j] + f(i+1,j+1,m,n,a);
    return max(d,max(ld,rd));
    
}

// OR
int f(int i,int j,vector<vector<int>> &a){
    if(j<0 || j>=a[0].size()) return -1e8;
    if(i==0) return a[i][j];

   int up= a[i][j] + f(i-1,j,a);
    int lup= a[i][j] + f(i-1,j-1,a);
    int rup= a[i][j] + f(i-1,j+1,a);
    return max(up,max(lup,rup));
    
}
int getMaxPathSum(vector<vector<int>> &a)
{
    int m=a.size();
    int n=a[0].size();
    int maxi = INT_MIN;
    for (int k = 0; k < n; k++) {
        maxi = max(maxi, f(m-1,k,a));
    }
    return maxi;
}


// Memorization  T.C = O(MxN)  Space Complexity = O(M x N) + O(N)
int f(int i,int j,vector<vector<int>> &a, vector<vector<int>> &dp){
    if(j<0 || j>=a[0].size()) return -1e8;
    if(i==0) return a[i][j];
    if(dp[i][j]!=-1) return dp[i][j];

    int up= a[i][j] + f(i-1,j,a,dp);
    int lup= a[i][j] + f(i-1,j-1,a,dp);
    int rup= a[i][j] + f(i-1,j+1,a,dp);

    return dp[i][j]=max(up,max(lup,rup));
    
}
int getMaxPathSum(vector<vector<int>> &a)
{
    int m=a.size();
    int n=a[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    int maxi = INT_MIN;
    for (int k = 0; k < n; k++) {
        maxi = max(maxi, f(m-1,k,a,dp));
    }
    return maxi;
}


// Tabulation T.C = O(MxN)  Space Complexity = O(MXN)
int getMaxPathSum(vector<vector<int>> &a)
{
    int m=a.size();
    int n=a[0].size();
	int dp[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
            if(i==0) dp[i][j]= a[i][j];
            else{
                int lup=INT_MIN, rup=INT_MIN;
                int up= a[i][j] + dp[i-1][j];
                if(j>0)
                    lup= a[i][j] + dp[i-1][j-1];
                if(j<n-1)
                    rup= a[i][j] + dp[i-1][j+1];

                dp[i][j]= max(up,max(lup,rup));
            }
		}
	}
    int maxi = INT_MIN;
    for(int j=0;j<n;j++){
        maxi= max(maxi,dp[m-1][j]);
    }
    return maxi;
}
 
//Space Optimization  T.C = O(MxN)  Space Complexity = O(N)
int getMaxPathSum(vector<vector<int>> &a)
{
    int m=a.size();
    int n=a[0].size();
	vector<int> prev(n);
	for(int i=0;i<m;i++){
        vector<int> temp(n);
		for(int j=0;j<n;j++){
            if(i==0) temp[j]= a[i][j];
            else{
                int lup=INT_MIN, rup=INT_MIN;
                int up= a[i][j] + prev[j];
                if(j>0)
                    lup= a[i][j] + prev[j-1];
                if(j<n-1)
                    rup= a[i][j] + prev[j+1];

                temp[j]= max(up,max(lup,rup));
            }
		}
        prev =temp;
	}
    int maxi = INT_MIN;
    for(int j=0;j<n;j++){
        maxi= max(maxi,prev[j]);
    }
    return maxi;
}
