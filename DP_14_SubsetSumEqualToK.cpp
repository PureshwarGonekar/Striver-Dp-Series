//Problem - https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954 

#include <bits/stdc++.h> 

//Recusion
bool f(int n, int k, int Sum, vector<int> &arr){
    if(n==0){
        if(Sum==k) return true;
        return false;
    }
    return f(n-1,k,Sum+arr[n],arr) || f(n-1,k,Sum,arr);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    return f(n-1,k,0,arr);
}

//Memorization
bool f(int n, int k,vector<int> &arr,vector<vector<int>> &dp){
    if(k==0) return true;
    if(n==0) return arr[0]==k;

    if(dp[n][k]!=-1) return dp[n][k];

    bool not_take= f(n-1,k,arr,dp);
    bool take = false;

    if (k >= arr[n]) {
      take = f(n - 1, k - arr[n], arr,dp);
    }
    return dp[n][k]= not_take || take;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(1001,vector<int>(1001,-1));
    return f(n-1,k,arr,dp);
}


//Tabulation

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++) dp[i][0]= true;
    dp[0][arr[0]] = true;
    for(int ind=1; ind<n; ind++){
        for(int target=1; target<=k; target++){
            bool not_take= dp[ind-1][target];
            bool take = false;

            if (target >= arr[ind]) {
                take =  dp[ind-1][target- arr[ind]];
            }
            dp[ind][target]= not_take || take;
        }
    }
    return dp[n-1][k];
}

//Space Optimization
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> front(k+1,0);
    vector<bool> curr(k+1,0);

    for(int i=0;i<n;i++) front[0]= true;
    front[arr[0]] = true;
    for(int ind=1; ind<n; ind++){

        for(int target=1; target<=k; target++){
            bool not_take= front[target];
            bool take = false;

            if (target >= arr[ind]) {
                take =  front[target- arr[ind]];
            }
            curr[target]= not_take || take;
        }
        front = curr;
    }
    return front[k];
}