//https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=1

#include <bits/stdc++.h> 
// Recursion
int frogJump1(int n, vector<int> &heights,int i=0)
{
    // Write your code here.
    if(i==n-1){
        return 0;
    }
    int OneJump = INT_MAX;
    int TwoJump = INT_MAX;
    if(i+1 < n){
        OneJump= abs(heights[i]-heights[i+1])+ frogJump(n, heights,i+1);
    }
    if(i+2 < n){
        TwoJump= abs(heights[i]-heights[i+2])+ frogJump(n, heights,i+2);
    }
    return min(OneJump,TwoJump);
}

//Memorization 
int frogJump2(int n, vector<int> &heights,int i,int *dp)
{
    // Write your code here.
    if(i==n-1){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int OneJump = INT_MAX;
    int TwoJump = INT_MAX;
    if(i+1 < n){
        OneJump= abs(heights[i]-heights[i+1])+ frogJump(n, heights,i+1,dp);
    }
    if(i+2 < n){
        TwoJump= abs(heights[i]-heights[i+2])+ frogJump(n, heights,i+2,dp);
    }
    return dp[i]=min(OneJump,TwoJump);
}
int frogJump2(int n, vector<int> &heights){
    int *dp= new int[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    return frogJump(n, heights,0,dp);
}

// Tabular Method
int frogJump3(int n, vector<int> &heights){
    vector<int> dp(n);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int fs= dp[i-1] + abs(heights[i]-heights[i-1]);
        int ss= INT_MAX;
        if(i > 1) ss = dp[i-2] + abs(heights[i] - heights[i-2]);
        dp[i]= min(fs,ss);
    }
    return dp[n-1];
}

// Space Optimization
int frogJump(int n, vector<int> &heights){
    int prev2i=0,ans;
    int previ=abs(heights[1]-heights[0]);
    for(int i=2;i<n;i++){
        int first= previ + abs(heights[i]-heights[i-1]);
        int second=prev2i + abs(heights[i] - heights[i-2]);

        ans= min(first,second);
        prev2i= previ;
        previ=ans;
    }
    return ans;
}

// Other way
int frogJump(int n, vector<int> &heights){
    int prev2i=0,ans;
    int previ=0;
    for(int i=1;i<n;i++){
        int first= previ + abs(heights[i]-heights[i-1]);
        int second=INT_MAX;
        if(i>1)
            second=prev2i + abs(heights[i] - heights[i-2]);

        ans= min(first,second);
        prev2i= previ;
        previ=ans;
    }
    return ans;
}