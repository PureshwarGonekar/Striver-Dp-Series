//https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261

#include <bits/stdc++.h> 
int helper1(vector<int> &nums,int i){
    if(i==0) return nums[i];
    if(i<0) return 0;
    int pick = nums[i] + helper1(nums,i-2);
    int not_pick = helper1(nums,i-1);
    return max(pick,not_pick);
}
int maximumNonAdjacentSum1(vector<int> &nums){
    // Write your code here.
    return helper1(nums,nums.size()-1);
}

// memorization T.C. = O(n)
int helper2(vector<int> &nums,int i,vector<int> &dp){
    if(i==0) return nums[i];
    if(i<0) return 0;
    if(dp[i]!=-1) return dp[i];
    int pick = nums[i] + helper2(nums,i-2,dp);
    int not_pick = helper2(nums,i-1,dp);
    return dp[i]=max(pick,not_pick);
}
int maximumNonAdjacentSum2(vector<int> &nums){
    // Write your code here.
    vector<int> dp(nums.size(),-1);
    return helper2(nums,nums.size()-1,dp);
}

//Tabular Method
int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums);
    dp[0]= nums[0];
    dp[1]= max(nums[0],nums[1]);
    for(int i=2;i<nums.size();i++){
        int pick = nums[i] + dp[i-2];
        int not_pick= dp[i-1];
        dp[i]= max(pick,not_pick);
    }
    return dp[nums.size()-1];
}

//Space Optimization
int maximumNonAdjacentSum(vector<int> &nums){
    if(nums.size()==1) return nums[0];
    int prev2= nums[0];
    int prev1= max(nums[0],nums[1]);
    int ans;
    for(int i=2;i<nums.size();i++){
        int pick = nums[i] + prev2;
        int not_pick= prev1;
        ans = max(pick,not_pick);
        prev2=prev1;
        prev1=ans;
    }
    return ans;
}


//Space Optimization (or)
int maximumNonAdjacentSum(vector<int> &nums){
    int prev2= 0;
    int prev1= nums[0];
    int ans;
    for(int i=2;i<nums.size();i++){
        int pick = nums[i] + prev2;
        int not_pick= prev1;
        ans = max(pick,not_pick);
        prev2=prev1;
        prev1=ans;
    }
    return ans;
}
