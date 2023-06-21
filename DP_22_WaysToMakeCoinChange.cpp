// Problem - https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471

#include <bits/stdc++.h> 

//Recursion T.C >>> O(2^n) i.e. exponential S.C >>> O(N) in worst case O(V)
long f(int ind,int V,int *D){
    //Base case
    if(ind == 0)return V % D[ind]== 0;

    long notTake = f(ind-1,V,D);
    long Take=0;
    if(D[ind]<=V) Take = f(ind,V-D[ind],D);
    
    return notTake + Take;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    return f(n-1,value,denominations);
}


// Memorization
long f(int ind,int V,int *D,vector<vector<long>> &dp){
    //Base case
    if(ind == 0)return V % D[ind]== 0;

    if(dp[ind][V]!=-1) return dp[ind][V];

    long notTake = f(ind-1,V,D,dp);
    long Take=0;
    if(D[ind]<=V) Take = f(ind,V-D[ind],D,dp);
    
    return dp[ind][V]=notTake + Take;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n,vector<long>(value+1,-1));
    return f(n-1,value,denominations,dp);
}

// Tabulation
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n,vector<long>(value+1,0));

    for(int T=0; T<=value; T++){
        dp[0][T] = T % denominations[0]==0;
    }

    for(int ind=1 ; ind<n; ind++){
        for(int T=0;T<=value ; T++){

            long notTake = dp[ind-1][T];
            long Take=0;
            if(denominations[ind]<=T )
                Take = dp[ind][T-denominations[ind]];
            
            dp[ind][T]= notTake + Take;
        }
    }
    return dp[n-1][value];
}


// Space Optimization
long countWaysToMakeChange(int *D, int n, int value)
{
    vector<long> prev(value+1);
    vector<long> cur(value+1);

    for(int T=0; T<=value; T++){
        prev[T] = T % D[0]==0;
    }

    for(int ind=1 ; ind<n; ind++){
        for(int T=0;T<=value ; T++){

            long notTake = prev[T];
            long Take=0;
            if(D[ind]<=T )
                Take = cur[T-D[ind]];
            
            prev[T]= notTake + Take;
        }
        prev = cur;
    }
    return prev[value];
}

// More Space Optimization 
long countWaysToMakeChange(int *D, int n, int value)
{
    vector<long> prev(value+1);
    for(int T=0; T<=value; T++){
        prev[T] = T % D[0]==0;
    }

    for(int ind=1 ; ind<n; ind++){
        for(int T=value;T>=0 ; T--){

            long notTake = prev[T];
            long Take=0;
            if(D[ind]<=T )
                Take = prev[T-D[ind]];
            
            prev[T]= notTake + Take;
        }
    }
    return prev[value];
}

