#include <bits/stdc++.h> 
int  mod= (int)1e9+7;

// Memorization T.C = O(N x (tar+1)) S.C. =  O(N x (tar+1)) + O(N) // from DP_17
int f(int ind,int target,vector<int> &num,vector<vector<int>> &dp){
    if (ind == 0) {
        if(target==0 && num[0]==0) return 2;
        else if(num[0]==target || target==0) return 1;
        else return 0;
    }

    if(dp[ind][target]!=-1) return dp[ind][target];

    int not_take = f(ind-1,target,num,dp);
    int take=0;
    if(num[ind]<= target){
        take = f(ind-1,target-num[ind],num,dp);
    }
    return dp[ind][target]=not_take+take;
}

int findWays(vector<int> &num, int tar)
{
    vector<vector<int>> dp(num.size(),vector<int>(tar+1,-1));
    return f(num.size()-1,tar,num,dp);
}

// tabulation from DP_17
int findWays(vector<int> &num, int tar)
{
    int n= num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,0));
    //for(int i=0;i<n;i++) dp[i][0] = 1;
    if(num[0]==0) dp[0][0]= 2; // if num[0] = 0 then if target =0 then there is 2 ways.
    else dp[0][0] =1;
     
    //if(num[0]<=tar) dp[0][num[0]] = 1; // fail if num[0] = 0 , it will overwrite the above if condition
    if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1;
    for(int ind=1;ind<n;ind++){
        for(int sum=0;sum<=tar;sum++){
            int not_take= dp[ind-1][sum];
            int take=0;
            if(num[ind]<=sum) take= dp[ind-1][sum-num[ind]];

            dp[ind][sum]= (not_take+take)%mod;
        }
    }
    return dp[n-1][tar];
}

// Space Optimization from DP_17
int findWays(vector<int> &num, int tar)
{
    int n= num.size();
    vector<int> prev(tar+1,0), cur(tar+1,0);
    if(num[0]==0) prev[0]= 2;
    else prev[0] =1;

    if(num[0]!=0 && num[0]<=tar) prev[num[0]] = 1;

    for(int ind=1;ind<n;ind++){
        for(int sum=0;sum<=tar;sum++){
            int not_take= prev[sum];
            int take=0;
            if(num[ind]<=sum) take= prev[sum-num[ind]];

            cur[sum]= not_take+take;
        }
        prev = cur;
    }
    return prev[tar];
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int totsum=0;
    for(int i=0;i<n;i++) totsum+= arr[i];

    //edge cases
    if(totsum-d <0 || (totsum-d)%2) return false;
    return findWays(arr,(totsum-d)/2);
}

