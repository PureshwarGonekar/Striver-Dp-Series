//Problem - https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494

#include <bits/stdc++.h> 
int f(int ind,vector<int> &arr, int Sum1,int Sum2){
	if(ind==-1) return abs(Sum1-Sum2);
	return min ( f(ind-1,arr,Sum1+arr[ind],Sum2) , f(ind-1,arr,Sum1,arr[ind]+Sum2));
}
int minSubsetSumDifference(vector<int>& arr, int n)
{
	return f(n-1,arr,0,0);
}

// Dynamic Programming
int minSubsetSumDifference(vector<int>& arr, int n)
{
    int k;
    for(int i=0;i<n;i++) k+=arr[i];
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

    int mini = 1e9;
    for(int s1=0 ; s1<= k/2; s1++){
        if(dp[n-1][s1]== true){
            mini = min(mini,abs((k-s1) - s1));
        }
    }
    return mini;
}
