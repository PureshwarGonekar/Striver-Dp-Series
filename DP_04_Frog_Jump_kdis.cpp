#include <bits/stdc++.h> 
int frogJumpWithK(int i, vector<int> &heights,int k)
{
    // Write your code here.
    if(i==0) return 0;
    int minSteps=INT_MAX;
    for(int j=1;j<=k;j++){
        if(i-j >=0){
            int jump = abs(heights[i]- heights[i-j]) + frogJumpWithK(i-j,heights,k);
            minSteps = min(minSteps,jump);
        }
        else break;
    }
    return minSteps;
}

//Memorization
int frogJumpWithK2(int i, vector<int> &heights,int k,vector<int> &dp) // i = n-1
{
    // Write your code here.
    if(i==0) return 0;
    if(dp[i]!=-1) return dp[i];
    int minSteps=INT_MAX;
    for(int j=1;j<=k;j++){
        if(i-j >=0){
            int jump = abs(heights[i]- heights[i-j]) + frogJumpWithK2(i-j,heights,k,dp);
            minSteps = min(minSteps,jump);
        }
        else break;
    }
    return dp[i]=minSteps;
}

// Tabular Method
int frogJumpWithK2(int n, vector<int> &heights,int k){ // Time C = O(N*K)  S.C= O(n)
    vector<int> dp(n);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int minSteps=INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j >=0){
                int jump = abs(heights[i]- heights[i-j]) + dp[i-j];
                minSteps = min(minSteps,jump);
            }
            else break;
        }
        dp[i]=minSteps;
    }
    return dp[n-1];
}

// Space Optimazation -->
// in avg case S.C. = O(k)
// But in worst case S.C. = O(n)